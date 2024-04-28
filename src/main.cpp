#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define PIN_SOILMOISTURESENSOR 34
int soilValue = 0;
int soilHigherValue = 0;
int soilLowerValue = 0;

LiquidCrystal_I2C lcd (0x27, 16,2);

void setup() {
  lcd.init();
  lcd.backlight();
  
  soilValue = analogRead(PIN_SOILMOISTURESENSOR);
  soilLowerValue = soilHigherValue = soilValue;
}

void loop() {
  soilValue = analogRead(PIN_SOILMOISTURESENSOR);
  soilHigherValue = (soilValue > soilHigherValue)? soilValue : soilHigherValue;
  soilLowerValue  = (soilValue < soilLowerValue) ? soilValue : soilLowerValue;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Higher: " + String(soilHigherValue));
  lcd.setCursor(0, 1);
  lcd.print("Lower : " + String(soilLowerValue));
  delay(500);

}
