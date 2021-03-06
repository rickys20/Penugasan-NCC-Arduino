// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//deklarasi
int trigPin = 10;
int echoPin = 9;
int led =13;
long duration;
int distanceCm, distanceInch;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  // lcd.print("hello, world!");
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
  // delay 500 microseconds
  delay(500);

  {
    
	if (distanceCm <= 100)
	{
     
      lcd.clear();  
      lcd.setCursor(0,0);
  	  lcd.print("Jarak: ");
      lcd.print(distanceCm);
      lcd.print(" cm ");
	  digitalWrite(led, HIGH);
      
      lcd.setCursor(0,1);
      lcd.print("Full!Turn Off!!!");
	}
    else
    {
      
      if (distanceCm >= 335)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Out Of Range");
        lcd.setCursor(0,1);
        lcd.print("Error");
       }
       else
       { 
        lcd.clear();
        lcd.setCursor(0,0);
  	    lcd.print("Jarak: ");
        lcd.print(distanceCm);
        lcd.print(" cm ");
    
        digitalWrite (led, LOW);
        lcd.setCursor(0,1);
	    lcd.print("Jarak: ");
        lcd.print(distanceInch);
        lcd.print(" Inch ");
       }
     }
   }
}
 
