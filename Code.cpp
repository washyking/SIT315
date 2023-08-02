const int motionPin = 2; // Pin connected to the digital output of the motion sensor
const int ledPin = 13;   // Light pin on the arduino

void setup() {
  pinMode(motionPin, INPUT); // Sets the motion sensor pin as input
  pinMode(ledPin, OUTPUT);   // Sets the LED pin as output
  Serial.begin(9600);        // start Serial communication 
}

void loop() {
  int motionValue = digitalRead(motionPin); // Read the value from the motion sensor

  if (motionValue == HIGH) {
    // Motion detected, turn on the LED
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion detected - LED ON");
  } else {
    // No motion detected, turn off the LED
    digitalWrite(ledPin, LOW);
    Serial.println("No motion detected - LED OFF");
  }

  delay(500); // Wait before repeating the loop
}
