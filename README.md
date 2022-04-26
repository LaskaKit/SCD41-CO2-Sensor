![SCD41](https://github.com/LaskaKit/SCD41-CO2-Sensor/blob/main/img/SCD41-1.jpg)

# LaskaKit SCD41 Sensor of CO2, temperature and humidity of air

Three sensors are inside of one small (21x21x8mm) and cheap module. You can measure the concentration of CO2, temperature and humidity. That are the main parameters of the quality of air what you can measure by only one sensor.

![SCD41](https://github.com/LaskaKit/SCD41-CO2-Sensor/blob/main/img/SCD41-front_popis.jpg)

On the front, in the center of module, is the SCD41 sensor. On the sides, you can see and use connector what we called μŠup. It is small connector what is durable and safe for connection to the our evaluation board or other sensor board. 
If you don't want to use μŠup, you can use the general header with 2.54mm.

The module includes pull-up resistors and the power supply is enabled by soldering of solder bridge. If you solder it, you connect 3.3V to pull-up resistors of SCL and SDA of I2C bus.

What are the parameters of SCD41?

    Power supply: 2,4-5,5V
    Range: 400 - 5000ppm
    Accuracy: ±(40 ppm + 5 %) from read value
    Bus: I2C
    Respond: 60s
    Range (temperature): -10 - +60 °C
    Accuracy (temperature): ±0.8°C (for range 15 - 35 °C)
    Range (humidity): 0 - 100 % RH
    Accuracy (humidity): ± 6 % RH (15 °C – 35 °C, 20 %RH – 65 %RH)
    Dimension: 21x21x8mm
    Weight: 2,5g

We wrote an example FW what you can use on https://github.com/LaskaKit/SCD41-CO2-Sensor/tree/main/FW/SCD41_MeteoMini

You can buy the module on https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/
