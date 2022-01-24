/*
 * Example code for SCD41 (CO2 sensor) and MeteoMini board
 * 
 * Boards:
 * https://www.laskakit.cz/laskakit-meteo-mini/
 * https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/
 * 
 * 
 * Library:
 * https://github.com/sparkfun/SparkFun_SCD4x_Arduino_Library
 * 
 * Made by laskakit.cz (c) 2021
  */

#include <Wire.h>

#include "SparkFun_SCD4x_Arduino_Library.h"
SCD4x SCD41;

void setup() 
{
  Serial.begin(115200);
  Serial.println("SCD41 and MeteoMini example code");
  Wire.begin();

  //             begin, autoCalibrate
  //               |      |
  if (SCD41.begin(false, true) == false)
  {
    Serial.println("SCD41 was not set correctly. Check the connection.");
    while (1)
      ;
  }

  if (SCD41.startLowPowerPeriodicMeasurement() == true)
  {
    Serial.println("Low power mode enabled.");
  }
}

void loop() 
{
  if (SCD41.readMeasurement()) // wait for a new data (approx 30s)
  {
    Serial.println();

    Serial.print("CO2(ppm):");
    Serial.print(SCD41.getCO2());

    Serial.print("\tTemperature(C):");
    Serial.print(SCD41.getTemperature(), 1);

    Serial.print("\tHumidity(%RH):");
    Serial.print(SCD41.getHumidity(), 1);

    Serial.println();
  }

  delay(1000);
}
