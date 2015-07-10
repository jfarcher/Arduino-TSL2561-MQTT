# Arduino-TSL2561-MQTT

Takes a reading from a TSL2561 Lum sensor and publishes to a topic on MQTT

#Installation
Make sure you have the PubSubClient library installed, https://github.com/knolleary/pubsubclient

Modify config.h to reflect your MQTT server and your topic you wish to pubish to.

Connect the sensor to your arduino:

VCC to 3v+
GND to GND
SCL to Analog 5
SDA to Analog 4


