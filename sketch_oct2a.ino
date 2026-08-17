// Moisture sensor
const int sensorPin = A1;
float moistureThreshold = 50.0;

// Pump
int pumpPin = 8;
bool autoPump = false;


void setup() {
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
  
}

void loop() {
  float moisture_percentage;
  int sensor_analogVal;

  sensor_analogVal = analogRead(sensorPin);
  moisture_percentage = (100- ((sensor_analogVal/1023.00)*100));
  
  Serial.println(moisture_percentage);

  if (moisture_percentage < moistureThreshold) {
    digitalWrite(pumpPin, HIGH);
  }
  else {
    digitalWrite(pumpPin, LOW);
  }
  delay(100);
}
