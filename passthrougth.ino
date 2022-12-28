

#define RXD2 16
#define TXD2 17
#define COM_RST 18

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  pinMode(COM_RST, OUTPUT);
  digitalWrite(COM_RST, LOW);
  delay(600);
  digitalWrite(COM_RST, HIGH);
  delay(600);
//  digitalWrite(COM_RST, LOW);
  Serial.println("Passthrow program started\n");
}

void loop() {
  if (Serial.available()) {      // If anything comes in Serial (USB),
    Serial2.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
  }

  if (Serial2.available()) {     // If anything comes in Serial1 (pins 0 & 1)
    Serial.write(Serial2.read());   // read it and send it out Serial (USB)
  }
}
