// ==================== Gas Leakage Detection ====================
const int gasPin = 34;     // ADC pin for MQ sensor
const int relayPin = 26;   // Relay to control gas valve
const int buzzerPin = 13;  // Buzzer
const int ledPin = 27;     // LED alert

int warningThreshold = 300;  // Adjust after calibration
int dangerThreshold  = 600;  // Adjust after calibration

void setup() {
  Serial.begin(115200);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(relayPin, LOW);  // Ensure gas valve is open at start
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);

  Serial.println("Gas Leakage Detection System Starting...");
  delay(2000); // short delay for sensor stabilization
}

void loop() {
  int sensorValue = analogRead(gasPin);
  Serial.print("Gas sensor value: ");
  Serial.println(sensorValue);

  if(sensorValue >= dangerThreshold) {
    triggerAlarm(true);
  } else if(sensorValue >= warningThreshold) {
    triggerAlarm(false);
  } else {
    // Normal state
    digitalWrite(relayPin, LOW);  // open gas valve
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }

  delay(1000); // read every second
}

// Function to trigger alarms
void triggerAlarm(bool danger) {
  digitalWrite(relayPin, HIGH);  // Close gas valve
  digitalWrite(ledPin, HIGH);

  if(danger){
    // Danger: buzzer blinking fast
    for(int i=0;i<5;i++){
      digitalWrite(buzzerPin,HIGH);
      delay(200);
      digitalWrite(buzzerPin,LOW);
      delay(100);
    }
    Serial.println("DANGER: Gas leak detected!");
  } else {
    // Warning: short beep
    digitalWrite(buzzerPin,HIGH);
    delay(500);
    digitalWrite(buzzerPin,LOW);
    Serial.println("WARNING: Gas detected!");
  }
}
