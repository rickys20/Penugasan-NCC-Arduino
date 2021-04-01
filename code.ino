#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
int trigPin = 10;
int echoPin = 11;
int led =12;
long duration;
int distanceCm, distanceInch;

void setup() {
lcd.begin(16,2);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(led, OUTPUT);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= (duration/2) / 29.1;
distanceInch = (duration/2) / 74;

lcd.setCursor(0,0);
lcd.print("Jarak: ");
lcd.print(distanceCm);
lcd.print(" cm ");
delay(10);

;
  {
	if (distanceCm <= 100)
	{
	  digitalWrite(led, HIGH);
      lcd.setCursor(0,1);
	  lcd.print("FULL!!");
      lcd.print("Turn Off");
      lcd.print("!!!");
	}
    else{
      digitalWrite (led, LOW);
      lcd.setCursor(0,1);
	  lcd.print("Jarak: ");
      lcd.print(distanceInch);
      lcd.print(" Inch ");
    }
   }
}
