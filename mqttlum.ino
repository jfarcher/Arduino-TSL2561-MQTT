#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include <Wire.h>
#include "TSL2561.h"
#include "config.h"

TSL2561 tsl(TSL2561_ADDR_FLOAT); 


// Update these with values suitable for your network.
byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
byte ip[]     = { 192, 168, 1, 200 };

EthernetClient ethClient;
PubSubClient client(MQTT_SERVER, 1883, 0, ethClient);

void getLum()
{

  client.publish("LS1","Sensor UP");
  tsl.setGain(TSL2561_GAIN_16X);      // set 16x gain (for dim situations)
  tsl.setTiming(TSL2561_INTEGRATIONTIME_13MS);  // shortest integration time (bright light) 
  uint16_t x = tsl.getLuminosity(TSL2561_FULLSPECTRUM);

  char* lum;
  char message_buffer[100];
  lum = dtostrf(x,4,2,message_buffer);
  client.publish("lum", lum);
  delay(5000);

}
void setup()
{
  Ethernet.begin(mac);
  client.connect("arduinoClient");
  tsl.begin();


}

void loop()
{

  client.loop();
  getLum();
}


