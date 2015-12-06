// Sylvain mathieu
//  November 20015 https://github.com/sylvain121/attiny85_ir_send
//  Attiny send IR AIRTON CODE 

#include <attiny85_ir_send.h>

// defining pins
#define ledPin     0      // (optional)attiny physical pin 5 , normal led for visual feedback of when we are sending an ir command. 
                          //Use at least a 470R resistor in series with it



IRsend irsend; // IR led on physical pin 6 (Digital 1) , the IR output will be always on attiny physical pin 6

// Variables that will change:
int buttonState = HIGH;             // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin
// the following variables are long's because the time, measured in miliseconds,
// will quickly overflow an int
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin,HIGH); //activating internal pull-up on button pin
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
}

void loop() {
    irsend.Airton(0x24, 0x02, 0x07,0x38);// sending the azirton code
    digitalWrite(ledPin,HIGH); // blinks an led just for  a visual feedback
    delay(200);
    digitalWrite(ledPin,LOW);
    delay(500);
 }
