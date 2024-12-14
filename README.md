# Serial Communication with LED Control
![Signal Connection](https://github.com/user-attachments/assets/915310d6-7781-416f-b6c7-be746993ba48)

## Overview
This project demonstrates serial communication between two Arduino programs. The **Sender** sends digital signals (`1` and `0`) at intervals, while the **Receiver** reads the signals and controls an LED based on the received data.

## Components
- 2 Arduino boards
- 1 LED
- 1 Resistor (220Ω recommended)
- Connecting wires

## How It Works
1. **Sender**: Sends `1` (ON) and `0` (OFF) signals through the serial port at 1-second intervals.
2. **Receiver**: Reads the incoming signals and:
   - Turns the LED ON if the signal is `1`.
   - Turns the LED OFF if the signal is `0`.

## Circuit Diagram

1. **Receiver Circuit**:
   - Connect the LED's positive leg to pin **7** via the resistor.
   - Connect the LED's negative leg to GND.
  
2. **Serial Communication**:
   - Connect the Sender and Receiver boards via USB to your computer.

## Code Descriptions
### Sender Code
```cpp
void setup() {
  Serial.begin(9600);
}

void loop() {
  // Send digital signal 1
  Serial.println(1);
  delay(1000); // 1 second ON

  // Send digital signal 0
  Serial.println(0);
  delay(1000); // 1 second OFF
}
```
### Receiver Code
```cpp
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
```
## Usage
  1. Upload the `Sender` code to one Arduino board
  2. Upload `Receiver` code to another Arduino board
  3. Open the Serial Monitor for boath boards to observe data trasmission and LED Control

## Note
  - Ensure both Arduinos use the sam baud rate (9600).
  - The LED pin(7) can be modified in the `Receiver` code if necessary.
