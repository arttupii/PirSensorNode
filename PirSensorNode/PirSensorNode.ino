#include <EspNowFloodingMesh.h>
#include<SimpleMqtt.h>

/********NODE SETUP********/
#define ESP_NOW_CHANNEL 1
const char deviceName[] = "PirOlohuone1";
//unsigned char secredKey[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
//unsigned char iv[16] = {0xb2, 0x4b, 0xf2, 0xf7, 0x7a, 0xc5, 0xec, 0x0c, 0x5e, 0x1f, 0x4d, 0xc1, 0xae, 0x46, 0x5e, 0x75};;
//const int ttl = 3;
#include "/home/arttu/git/myEspNowMeshConfig.h" //My secred mesh setup...
/*****************************/

#define LED 1 /*LED pin*/

SimpleMQTT simpleMqtt = SimpleMQTT(ttl, deviceName);

void espNowFloodingMeshRecv(const uint8_t *data, int len, uint32_t replyPrt) {
  if (len > 0) {
    simpleMqtt.parse(data, len, replyPrt); //Parse simple Mqtt protocol messages
  }
}

void deepSleepMode(){
  ESP.deepSleep(0);  
}

bool setLed;
bool ledValue;
void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  
  //Set device in AP mode to begin with
  espNowFloodingMesh_RecvCB(espNowFloodingMeshRecv);
  espNowFloodingMesh_secredkey(secredKey);
  espNowFloodingMesh_setAesInitializationVector(iv);
  espNowFloodingMesh_setToMasterRole(false, ttl);
  espNowFloodingMesh_setToBatteryNode();
  espNowFloodingMesh_begin(ESP_NOW_CHANNEL);//, bsid);

  espNowFloodingMesh_ErrorDebugCB([](int level, const char *str) {
    Serial.print(level); Serial.println(str); //If you want print some debug prints
  });


  if (!espNowFloodingMesh_syncWithMasterAndWait()) {
    //Sync failed??? No connection to master????
    Serial.println("No connection to master!!! Reboot");
    deepSleepMode(); //Perhaps this works in the next time. Let's go to sleep
  }

  //Handle MQTT events from master. Do not call publish inside of call back. --> Endless event loop and crash
  simpleMqtt.handleSubscribeAndGetEvents([](const char *topic, const char* value) {
  });

  //Handle MQTT events from master
  simpleMqtt.handlePublishEvents([](const char *topic, const char* value) {
  });

  if (!simpleMqtt.publish(deviceName, "/motion/value", "on")) {
    Serial.println("Publish failed... Reboot");
    deepSleepMode(); //Perhaps this works in the next time. Let's go to sleep
  }
  Serial.println("Alarm has been published succesfully!!");
  deepSleepMode(); 
}

void loop() {
  espNowFloodingMesh_loop();
}
