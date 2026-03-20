#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT22.h> // or any other DHT Sensor Library

int DHT = 4;  // you can change all of the pins if you want to
int LED1 = 3;
int LED2 = 5;
int LED3 = 6;

LiquidCrystal_I2C lcd(0x27, 16, 2);  // the adress (0x27) could needed to be changed when you have a other lcd 
DHT22 dht(DHT);  // change for your DHT

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.print("Thermometer");
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  float temp = dht.getTemperature();

  if (temp >= 25.0) {
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }

  if (temp <= 20.0) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }

  if (temp >= 20.0 && temp <= 25.0) {
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }

  Serial.println("Temperatur: ");
  Serial.print(temp, 1);
  Serial.println(" °C");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp, 1);
  lcd.print(" °C");

  lcd.setCursor(0, 1);
  lcd.print("LED: ");
  lcd.print((temp > 25.0) ? "AN" : "AUS");

  delay(1000);
}

