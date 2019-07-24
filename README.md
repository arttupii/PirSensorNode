# PIR sensor to flooding mesh network


Based on EspNowFloodingMesh project:
* https://github.com/arttupii/EspNowFloodingMesh

![alt text](https://raw.githubusercontent.com/arttupii/PirSendorNode/master/PirSensor.png)

```
        +--------------------------+
        |   ESP01                  |
        |                          |
        |                          |
        |                          |          +----------------+
        |                          |          |                |
        |                          |          |                |  
        |                          |          |           +----------+
        |                          |          |           |  VCC     |
        |   1     3     5     7    |      ---------       |          |
  +---------+-+   +-+   +-+   +-+  |        ----- 1.5v    |          |
  |     |   +-+   +-+   +-+   +-+  |          |           |PIR-SENSOR|
  |     |                |         |          |           |          |
  |     |   2     4     6|    8    |          |           |          |
  |     |   +-+   +-+   +-+   +-+ ------------+           |GND    SIG|
  |     |   +-+   +-+   +-+   +-+  |          |           +----------+
  |     |          |     |     |   |          |             |      |
  |     |          |     +-----+   |          |             |      |
  |     +----------|---------------+      ---------         |      |
  |                |                        -----  1.5v     |      |
  |                |                          |             |      |
  |                |                          |             |      |
  |                |                      ---------         |      |
  |                |                        -----  1.5      |      |
  |                |                          |             |      |
  |                |                          |             |      |
  +----------------|--------------------------+-------------+      |
                   |                                               |
                   +-----------------------------------------------+

1 GND
2 TXD
3 GPIO2
4 CHIP_EN
5 GPIO0
6 RESET
7 GPIO03
8 VCC
```
Links:
  * https://www.banggood.com/Mini-IR-Pyroelectric-Infrared-PIR-Motion-Human-Body-Sensor-Detector-Module-p-1424839.html?rmmds=search&cur_warehouse=CN
  * https://www.banggood.com/Upgraded-Version-1M-Flash-ESP8266-ESP-01-WIFI-Transceiver-Wireless-Module-p-979509.html?rmmds=search&cur_warehouse=UK
  * https://www.banggood.com/1-Slots-AA-Battery-Holder-Plastic-Case-Storage-Box-for-1AA-Battery-p-1472098.html?rmmds=search&cur_warehouse=CN
