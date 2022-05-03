// C++ code
//
#include <LiquidCrystal.h>

const int rs = 11, en = 10, d4 = 9, d5 = 8, d6 = 7, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int val;
int tempPin = 0;
int greenPin = 2;
int redPin = 3;

void setup() {
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(10, OUTPUT);
  
  lcd.begin(16, 2);
  
  Serial.begin(9600);
}

void loop() {
  val = analogRead(tempPin);
  float mv = ( val/1023.0)*5000; 
  float cel = mv/10;
  
  lcd.setCursor(0, 0);
  lcd.print("Temprature:");
  
  lcd.setCursor(0,1);
  lcd.print(cel);
  lcd.print(" Celcious");
  delay(500);
  if(cel >= 35 && cel <= 39) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
  } else {
    digitalWrite(greenPin, LOW);
    
    digitalWrite(redPin, HIGH);
    delay(300);
    digitalWrite(redPin, LOW);
    delay(300);
    tone(4, 523, 100);
  }
}
