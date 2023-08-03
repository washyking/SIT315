const int motionPin = 2;     // Pin connected to the digital output of the motion sensor
const int moisturePin = A0;  // Analog Pin connected to the soil moisture sensor
const int ledPin = 13;       // Built-in LED pin on the Arduino board

volatile bool motionDetected = false;
int moistureValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);   // Set the LED pin as output
  pinMode(motionPin, INPUT); // Set the motion sensor pin as input
  Serial.begin(9600);        // Initialise Serial communication for monitoring

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
  // Read the value from the soil moisture sensor
  moistureValue = analogRead(moisturePin);

  if (motionDetected) {
    // Motion detected, turn on the LED
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion detected - LED ON");
  } else {
    // No motion detected, turn off the LED
    digitalWrite(ledPin, LOW);
    Serial.println("No motion detected - LED OFF");
  }

  // Check the moisture level and print
  Serial.print("Moisture Level: ");
  Serial.println(moistureValue);


  delay(500); // A delay before repeating loop
}
