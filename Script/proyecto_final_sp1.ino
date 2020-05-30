#include <LiquidCrystal.h>
/*
  The circuit:
 * LCD RS pin to digital pin 13
 * LCD Enable pin to digital pin 12
 * LCD D4 pin to digital pin 11
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 9
 * LCD D7 pin to digital pin 8
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

#define PIR_sensor 14
#define m11 0
#define m12 1

void setup() 
{
  lcd.begin(16, 2);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(PIR_sensor, INPUT);
  lcd.print("    Automatic    ");
  lcd.setCursor(0,1); 
  lcd.print("   Door Opener   ");
  delay(3000);
  lcd.clear();
  delay(2000);
}

void loop() 
{
  if(digitalRead(PIR_sensor))
  {
    lcd.setCursor(0,0);
    lcd.print("Movement Detected");
    lcd.setCursor(0, 1);
    lcd.print("    Gate Opened    ");
    digitalWrite(m11, HIGH);         // La puerta se abre
    digitalWrite(m12, LOW);
    delay(1000);
    digitalWrite(m11, LOW);          // La puerta se detetiene por un rato 
    digitalWrite(m12, LOW);
    delay(1000);
    lcd.clear();
    lcd.print("   Gate Closed    ");
    digitalWrite(m11, LOW);           // La pueta se va cerrando
    digitalWrite(m12, HIGH);
    delay(1000);
    digitalWrite(m11, LOW);            // LA puerta se encunetra cerrada
    digitalWrite(m12, LOW);
    delay(1000);
  }
  
  else 
  {
    lcd.setCursor(0,0);
    lcd.print("   No Movement   ");
    lcd.setCursor(0,1);
    lcd.print("   Gate Closed   ");
    digitalWrite(m11, LOW);
    digitalWrite(m12, LOW);
  }
}
