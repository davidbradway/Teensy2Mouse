/* Simple USB Mouse Example
   Teensy becomes a USB mouse
   You must select Mouse from the "Tools > USB Type" menu

   LED Blink, Teensyduino Tutorial #1
   http://www.pjrc.com/teensy/tutorial.html

   This example code is in the public domain.
*/

// Teensy 2.0 has the LED on pin 11
const int ledPin = 11;

byte left=0;
byte middle=0;
byte right=0;

// the setup() method runs once, when the sketch starts
void setup() { 
  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);
}

// the loop() methor runs over and over again,
// as long as the board has power
void loop() {
  digitalWrite(ledPin, HIGH);   // set the LED on
  delay(1000);                  // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED off
  delay(1000);                  // wait for a second

  int i;
  // Move the mouse to the minimize button
  for (i=0; i<80; i++) {
    Mouse.move(127, -127);
  }
  Mouse.move(-88, 10);

  myLeftMouseClick();

  // Move the mouse to the start buttn
  for (i=0; i<80; i++) {
    Mouse.move(-127, 127);
  }
  Mouse.move(10, 10);

  myLeftMouseClick();
}

void myLeftMouseClick(){
  // Click the mouse button
  left = 1;
  Mouse.set_buttons(left, middle, right);
  delay(10);
  left = 0;
  Mouse.set_buttons(left, middle, right);
  delay(10);
}

