#include <Arduino.h>
#include <EEPROM.h>

#define EEPROM_SIZE 1023  // atmega32u4 has 1 kB

// Variables
int memAddr = 0;

// Parameters
const byte uid_size = 7;        // Max length of uid array
const byte password_size = 30;  // Max length of password char array

// Struct defining uid/password pair
struct tagData{
  byte uid[uid_size];
  char password[password_size];
};

// ###############################
// ########## User data ##########
// ###############################
struct tagData tags[] = {
  {{0xFF, 0xFF, 0xFF, 0xFF},                    "test1\n"},
  {{0xFE, 0xFE, 0xFE, 0xFE},                    "test2\n"},
  {{0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD},  "test3\n"},
  {{0xFC, 0xFC, 0xFC, 0xFC},                    "test4\n"}
};
// ###############################
// ###############################
// ###############################

// Count how many tags were entered
const byte nbrOfTags = sizeof(tags)/sizeof(tagData);

void setup(){
  // Initialize serial connecton
  Serial.begin(115200);

  // Wait for serial connection
  while(!Serial){
    ;
  }

  // Calculate size of the data the user wants to store
  int memUsage = sizeof(nbrOfTags) + sizeof(tags);

  // Break if the required memory is larger than the available memory
  if(memUsage > EEPROM_SIZE){
    Serial.print("Size of information (");
    Serial.print(memUsage);
    Serial.print(" byte) exceeds EEPROM limit (");
    Serial.print(EEPROM_SIZE);
    Serial.println(" byte).");
    return;
  }

  // Store number of tags in first byte and increment memory index
  EEPROM.put(memAddr, nbrOfTags);
  memAddr += sizeof(nbrOfTags);

  // Write data struct to memory
  EEPROM.put(memAddr, tags);
  Serial.print("Successfully wrote ");
  Serial.print(nbrOfTags);
  Serial.print(" entries (");
  Serial.print(memUsage);
  Serial.println(" byte).");
}

void loop(){
  // Infinite loop when done
  delay(10000);
}
