#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 23//4
LiquidCrystal_I2C *pLCD = NULL;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
byte lcdAddressA = 63;
byte lcdAddressB = 39;
byte count = 0, lcdAddress;
void setup() {
  Serial.begin(115200);
  Wire.begin();
  for (byte i = 8; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0) {
      lcdAddress = i;
      count++;
    }
  }
  Serial.print (lcdAddress, DEC);
  pLCD = new LiquidCrystal_I2C(lcdAddress, 16, 2);
  pLCD -> backlight();

}
void loop() {
  pLCD -> begin();
  pLCD -> clear();
  pLCD -> setCursor(0, 0);
  pLCD -> print("CURRENT");
  pLCD -> setCursor(8, 0);
  pLCD -> print("FAIL");

}
