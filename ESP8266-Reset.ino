#include <ESP8266WiFi.h>
#include <EEPROM.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  // WiFi Config Erase
  WiFi.disconnect(true);
  ESP.eraseConfig();

  // EEPROM Erase
  EEPROM.begin(512);
  for (int i = 0; i < 512; i++) {
    EEPROM.write(i, 0xFF);
  }
  EEPROM.commit();
  EEPROM.end();

  delay(1000);
  ESP.restart();
}

void loop() {
}
