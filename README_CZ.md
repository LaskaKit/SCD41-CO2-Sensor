![SCD41](https://github.com/LaskaKit/SCD41-CO2-Sensor/blob/main/img/SCD41-1.jpg)

# LaskaKit SCD41 Senzor CO2, teploty a vlhkosti vzduchu

Tři čidla v jednom malém (21x21x8mm) a levném modulu. Můžeš měřit koncentraci CO2 ve vzduchu, teplotu i vlhkost. To jsou základní parametry kvality vzduchu, které můžeš měřit jediným čidlem u sebe doma. 

![SCD41](https://github.com/LaskaKit/SCD41-CO2-Sensor/blob/main/img/SCD41-front_popis.jpg)

Na přední straně je ve středu desky je čidlo SCD41, po stranách pak najdeš náš konektor, který jsme nazvali μŠup. Je to malý, odolný a bezpečný konektor - nemůže se ti stát že bys přepóloval kabel, protože konektor má zámek. Pokud nechceš čidlo připojit k nějaké desce přes μŠup, nechali jsme na desce i klasický hřebínek s roztečí 2.54mm.

Na modulu ještě najdeš pájecí most, po zapájení se napájecí napětí 3.3V přivede na SCL a SDA I2C sběrnice. 

A jaké jsou parametry SCD41?

    Napájení: 2,4-5,5V
    Rozsah měření: 400 - 5000ppm
    Přesnost: ±(40 ppm + 5 %) z naměřené hodnoty
    Sběrnice: I2C
    Odezva: 60s
    Rozsah (teplota): -10 - +60 °C
    Přesnost (teplota): ±0.8°C (pro rozsah 15 - 35 °C)
    Rozsah (vlhkost): 0 - 100 % RH
    Přesnost (vlhkost): ± 6 % RH (15 °C – 35 °C, 20 %RH – 65 %RH)
    Rozměry: 21x21x8mm
    Váha: 2,5g

Připravili jsme i vzorový FW, ten najdeš v této složce https://github.com/LaskaKit/SCD41-CO2-Sensor/tree/main/FW/SCD41_MeteoMini

Modul s SCD41 si můžeš zakoupit na https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/
