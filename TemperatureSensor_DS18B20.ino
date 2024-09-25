#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

// Data wire is connected to pin 2
#define ONE_WIRE_BUS 3

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
hd44780_I2Cexp lcd;

void setup() {
  lcd.begin(16, 2);  // Initialize 16x2 LCD
  lcd.print("Temp: ");
  
  sensors.begin();   // Start DS18B20 sensor
}

void loop() {
  sensors.requestTemperatures();  // Send command to get temperature
  float tempC = sensors.getTempCByIndex(0);  // Get temperature in Celsius
  
  lcd.setCursor(6, 0);  // Position to print temp
  lcd.print(tempC);
  lcd.print((char)223); // Degree symbol
  lcd.print("C");
  
  delay(1000);  // Update every second
}
