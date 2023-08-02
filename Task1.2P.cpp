const int motionPin = 2; // Pin connected to the digital output of the motion sensor
const int ledPin = 13;   // Built-in LED pin on the Arduino board

volatile bool motionDetected = false;

void setup() {
  pinMode(ledPin, OUTPUT);   // Set the LED pin as output
  Serial.begin(9600);        // Initialize the Serial communication for monitoring

  attachInterrupt(digitalPinToInterrupt(motionPin), motionInterrupt, CHANGE);
}

void motionInterrupt() {
  if (digitalRead(motionPin) == HIGH) {
    motionDetected = true;
  } else {
    motionDetected = false;
  }
}

void loop() {
  if (motionDetected) {
    // Motion detected, turn on the LED
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion detected - LED ON");
  } else {
    // No motion detected, turn off the LED
    digitalWrite(ledPin, LOW);
    Serial.println("No motion detected - LED OFF");
  }
  
  // Add any other tasks you need to do here

  delay(100); // A short delay to avoid excessive LED toggling
}
