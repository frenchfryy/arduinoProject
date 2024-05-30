#include <LiquidCrystal.h>

const int greenLight = 8;
const int redLight = 9;
const int switchPin = 10;
int toggleSwitch;
int switchState = 0;

LiquidCrystal lcd(12,11,5,4,3,2);

void setup(){
  	pinMode(greenLight, OUTPUT);
  	pinMode(redLight, OUTPUT);
  	pinMode(switchPin, INPUT);
  	Serial.begin(9600);
  	Serial.println("ready & listening");
}

void loop(){  
  
  lcd.begin(16,2);
  toggleSwitch = digitalRead(switchPin);
  Serial.print(toggleSwitch);
  Serial.print(" , ");
  Serial.println(switchState);
  delay(10);
  
  if(toggleSwitch == 1 && switchState == 1){
  	switchState = 0;
    //if(switchState % 2 == 0){
    //	switchState = 0;
    //}
    delay(100);
  }
  else if(toggleSwitch == 1 && switchState == 0){
  	switchState = 1;
    //if(switchState % 2 == 0){
    //	switchState = 0;
    //}
    delay(100);
  }

  if(switchState == 0){
  	digitalWrite(greenLight, LOW);
  	digitalWrite(redLight, HIGH);
  	lcd.print("   you may not come in :(");
    
   	for (int positionCounter = 0; positionCounter < 10; positionCounter++) {
  		lcd.scrollDisplayLeft();
      //lcd.setCursor(0, 1);
      //lcd.print("SS0");
   		delay(250);
    }
  }
  
  else if(switchState == 1){
    digitalWrite(redLight, LOW);
    digitalWrite(greenLight, HIGH);
    lcd.print("   you may come in :)");
    
    for (int positionCounter = 0; positionCounter < 10; positionCounter++) {
  		lcd.scrollDisplayLeft();
      //lcd.setCursor(0, 1);
      //lcd.print("SS1");
   		delay(250);
    }
  }
}
