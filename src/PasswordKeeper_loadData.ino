#include <Arduino.h>
#include <EEPROM.h>

#define EEPROM_SIZE 1023  // atmega32u4 has 1 kB

int memAddr = 0;

struct tagData{
  byte uid[7];
  char password[30];
};
struct tagData tags[] = {
  {{0xFF, 0xFF, 0xFF, 0xFF},                    "test1\n"},
  {{0xFE, 0xFE, 0xFE, 0xFE},                    "test2\n"},
  {{0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD},  "test3\n"},
  {{0xFC, 0xFC, 0xFC, 0xFC},                    "test4\n"}
};
const byte nbrOfTags = sizeof(tags)/sizeof(tagData);

void setup(){
  Serial.begin(115200);
  while(!Serial){
    ;
  }

  int memUsage = sizeof(nbrOfTags) + sizeof(tags);
  if(memUsage > EEPROM_SIZE){
    Serial.print("Size of information (");
    Serial.print(memUsage);
    Serial.print(" byte) exceeds EEPROM limit (");
    Serial.print(EEPROM_SIZE);
    Serial.println(" byte).");
    return;
  }

  EEPROM.put(memAddr, nbrOfTags);
  memAddr += sizeof(nbrOfTags);

  EEPROM.put(memAddr, tags);
  Serial.print("Successfully wrote ");
  Serial.print(nbrOfTags);
  Serial.print(" entries (");
  Serial.print(memUsage);
  Serial.println(" byte).");
}

void loop(){
  delay(10000);
}
