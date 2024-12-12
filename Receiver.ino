const int ledPin = 7; // Define the pin for the LED

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); // Initialize the LED pin as an output
}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming data as an integer (1 or 0)
    int signal = Serial.parseInt();

    // Print the signal to Serial Monitor and Serial Plotter
    Serial.println(signal);
    
    // Control the LED based on the signal
    if (signal == 1) {
      digitalWrite(ledPin, HIGH); // Turn on LED
    } else {
      digitalWrite(ledPin, LOW); // Turn off LED
    }
  }
}
