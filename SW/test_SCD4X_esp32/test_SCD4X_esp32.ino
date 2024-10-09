/* Sensirion SCD4x test with LaskaKit DEVkits
 * example from GxEPD2 library is used
 * 
 * Board:   LaskaKit ESP32-DEVKit       https://www.laskakit.cz/laskakit-esp32-devkit/
 *          or LaskaKit ESP32-S3-DEVKit https://www.laskakit.cz/laskakit-esp32-s3-devkit
 * Sensor:  LaskaKit SCD41 Sensor CO2   https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/
 * 
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */

// Display Library example for SPI e-paper panels from Dalian Good Display.
// Requires Adafruit_GFX and https://github.com/ZinggJM/GxEPD2 Author: Jean-Marc Zingg
// Display Library based on Demo Example from Good Display: http://www.e-paper-display.com/download_list/downloadcategoryid=34&isMode=false.html
#include <SensirionI2CScd4x.h>
#include <Wire.h>

// SPI uSUP LaskaKit ESP32-DEVKit 
#define SCL     22
#define SDA     21
#define POWER   2

// SPI uSUP LaskaKit ESP32-S3-DEVKit 
//#define SCL     2
//#define SDA     42
//#define POWER   47

SensirionI2CScd4x scd4x;

void printUint16Hex(uint16_t value) {
    Serial.print(value < 4096 ? "0" : "");
    Serial.print(value < 256 ? "0" : "");
    Serial.print(value < 16 ? "0" : "");
    Serial.print(value, HEX);
}

void printSerialNumber(uint16_t serial0, uint16_t serial1, uint16_t serial2) {
    Serial.print("Serial: 0x");
    printUint16Hex(serial0);
    printUint16Hex(serial1);
    printUint16Hex(serial2);
    Serial.println();
}

void setup() {

    Serial.begin(115200);
    while (!Serial) {
        delay(100);
    }
  
    pinMode(POWER, OUTPUT);    // Set uSUP connector power transistor as output
    digitalWrite(POWER, HIGH); // Turn power ON uSUP connector
    delay(100);    

    Wire.begin(SDA, SCL);

    uint16_t error;
    char errorMessage[256];

    scd4x.begin(Wire);

    // stop potentially previously started measurement
    error = scd4x.stopPeriodicMeasurement();
    if (error) {
        Serial.print("Error trying to execute stopPeriodicMeasurement(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    }

    uint16_t serial0;
    uint16_t serial1;
    uint16_t serial2;
    error = scd4x.getSerialNumber(serial0, serial1, serial2);
    if (error) {
        Serial.print("Error trying to execute getSerialNumber(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        printSerialNumber(serial0, serial1, serial2);
    }

    // Start Measurement
    error = scd4x.startPeriodicMeasurement();
    if (error) {
        Serial.print("Error trying to execute startPeriodicMeasurement(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    }

    Serial.println("Waiting for first measurement... (5 sec)");
}

void loop() {
    uint16_t error;
    char errorMessage[256];

    delay(5000);

    // Read Measurement
    uint16_t co2;
    float temperature;
    float humidity;
    error = scd4x.readMeasurement(co2, temperature, humidity);
    if (error) {
        Serial.print("Error trying to execute readMeasurement(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    }/* else if (co2 == 0) {
        Serial.println("Invalid sample detected, skipping.");
    } */else {
        Serial.print("Co2:");
        Serial.print(co2);
        Serial.print("\t");
        Serial.print(" Temperature:");
        Serial.print(temperature);
        Serial.print("\t");
        Serial.print(" Humidity:");
        Serial.println(humidity);
    }
}
