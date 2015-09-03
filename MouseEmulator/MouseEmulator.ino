/* Simple USB Mouse Example
   Teensy becomes a USB mouse and moves the cursor in a triangle

   You must select Mouse from the "Tools > USB Type" menu

   This example code is in the public domain.
*/
byte left=0;
byte middle=0;
byte right=0;

void setup() { 
  int cnt;
  int i;
  // Try 20 times, determined empirically
  for (cnt=0; cnt<20; cnt++){
    // Move the mouse to the minimize button
    for (i=0; i<10; i++) {
      Mouse.move(127, -127);
    }
    Mouse.move(-88, 10);

    // Click the mouse button
    left = 1;
    Mouse.set_buttons(left, middle, right);
    delay(10);
    left = 0;
    Mouse.set_buttons(left, middle, right);
    delay(10);
  }

  // Move the mouse to the start buttn
  for (i=0; i<15; i++) {
    Mouse.move(-127, 127);
  }
  Mouse.move(10, 10);

  // Click the mouse button
  left = 1;
  Mouse.set_buttons(left, middle, right);
  delay(10);
  left = 0;
  Mouse.set_buttons(left, middle, right);
  delay(10);
}
  
void loop() {
}

