#include <LiquidCrystal.h>


int moisturesensorpin = A2;
int motorpin = 9;
int sensorValue = 0;      


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  Serial.begin(9600);
  pinMode(moisturesensorpin, INPUT);  //initialize the LED pin as an output
  pinMode(motorpin, OUTPUT);

  lcd.begin(20, 4);// set up the LCD's number of columns and rows:
}

void loop() {




  lcd.setCursor(0, 0);
  lcd.print("Smart Irrigation ");

  sensorValue = analogRead(moisturesensorpin);
  Serial.println(sensorValue);
  sensorValue = map(sensorValue, 970, 100, 0, 100);
  //Serial.println(sensorValue);
  if (sensorValue >= 70) {

    Serial.println(sensorValue);
    digitalWrite(motorpin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Moisture In soil");
    lcd.setCursor(0, 2);
    lcd.print(sensorValue);
    lcd.setCursor(3, 2);
    lcd.print("%");
    lcd.setCursor(0, 3);
    lcd.print("Pump Off ");


  }
  else if (sensorValue < 70 ) {


    digitalWrite(motorpin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Moisture In soil");
    lcd.setCursor(0, 2);
    lcd.print(sensorValue);
    lcd.setCursor(3, 2);
    lcd.print("%");
    lcd.setCursor(0, 3);
    lcd.print("Pump On ");


  }


  delay(1000);
}
