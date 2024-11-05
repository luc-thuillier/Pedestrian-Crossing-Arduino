//SFHW1P3 Luc Thuillier
//thuillier.l@northeastern.edu

// Declare global variables
int GreenLightState = 0;
int RedLightState = 0;

void setup() {
  pinMode(3, INPUT);
  pinMode(5, OUTPUT); // Red
  pinMode(7, OUTPUT); // Green
  pinMode(6, OUTPUT); // Yellow
  pinMode(9, OUTPUT); // RGB Red
  pinMode(10, OUTPUT); // RGB Green
  pinMode(11, OUTPUT); // RGB Blue

  // Initial State
  GreenLightState = 0;
  RedLightState = 0;
}

void loop() {
  // Start with green light
  GreenLightState = 1;
  digitalWrite(7, HIGH); // Turn on green light
  
  // Continuously check button state while green light is on
  unsigned long startTime = millis();
  while (millis() - startTime < 5000) {
    if (digitalRead(3) == LOW) { // Button pressed
      break; // Exit loop to change lights
    }
  }

  digitalWrite(7, LOW); // Turn off green light
  GreenLightState = 0;

  if (GreenLightState == 0) {
    // Change to yellow then red, including pedestrian light, only if green was interrupted or completed
    changeToYellowThenRed();
  }

  // Reset states as needed and loop back
}

void changeToYellowThenRed() {
  // Yellow light sequence
  digitalWrite(6, HIGH);
  delay(2500); // Yellow for 2.5 seconds
  digitalWrite(6, LOW);

  // Red light sequence
  RedLightState = 1;
  digitalWrite(5, HIGH); // Red on
  pedestrianLightSequence(); // Start pedestrian light sequence
  digitalWrite(5, LOW); // Turn off red light
  RedLightState = 0;
}

void pedestrianLightSequence() {
  // Assuming RGB LED is used for pedestrian light
  // White light
  analogWrite(9,255); 
  analogWrite(10,255); 
  analogWrite(11,255); 
  delay(3000); // White light for 3 seconds

  // Blinking orange 
  for (int i = 0; i < 8; i++) {
    analogWrite(9,204); 
    analogWrite(10,153);
    analogWrite(11,51) 
    ;delay(250); 
    analogWrite(9,255); 
    analogWrite(10,255); 
    analogWrite(11,255); 
    delay(250);
  }

  // Solid orange
  analogWrite(9,204); 
  analogWrite(10,153); 
  analogWrite(11,51); 
  delay(2500);
}