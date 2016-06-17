/*

LCD display code modified from: http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// initialize button
const int buttonPin = 8;
int buttonState = 0;

char* topText[] = {"whoever u r", "situp/standdown", "all y'all", "if ur a they", "l@s tod@s", "tg or not", "clocked?","queermerica :-)","3v3ry1 is ="};
char* bottomText[] = {"u r welcome here", "come on in", "u r safe here", "shelter inside", "welcome here", "inside u r free", "pee where u want", "we don't care", "peace"};

int i = 0;
int j = 0;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // setup pushbutton as an input
  pinMode(buttonPin, INPUT);

}

void loop() {
  // read button state
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  delay(100);

  if (buttonState == HIGH){
    i = random(0,9);
    j = random(0,9);
    lcd.clear();
  }
  // Print a message to the LCD.
  lcd.setCursor(0,0);
  lcd.print(topText[i]);
    
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(bottomText[j]);
  
}

