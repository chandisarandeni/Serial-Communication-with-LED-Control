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
