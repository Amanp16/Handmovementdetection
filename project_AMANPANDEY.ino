/* Aman Pandey 
 * 20je0109
 * Hand motion detector bot 
 * 
 */
const int leftPing = 2;  // Trigger Pin of Ultrasonic Sensor 1
const int rightPing = 4; // Trigger Pin of Ultrasonic Sensor 2
const int leftecho = 6; // Echo Pin of Ultrasonic Sensor 1
const int rightecho = 8; // Echo Pin of Ultrasonic Sensor 2
int maxD = 10; // cm
boolean left=false;
boolean right=false;
void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(leftPing, OUTPUT);
   pinMode(rightPing, OUTPUT);
   pinMode(leftecho, INPUT);
   pinMode(rightecho, INPUT);
}
void loop() {
  left = ping(leftPing, leftecho); 
  right = ping(rightPing, rightecho);
  if (left)
  {
    Serial.println("Left ");
    delay(1000);
  }
  if (right)
  {
    Serial.println("Right ");
    delay(1000);
  }
}
int getDistance(int trigPin, int pingPin) {
   
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(pingPin, HIGH);
  // Calculating the distance
  float distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  return distance;
}
boolean ping(int trigPin, int pingPin) { 
 int d = getDistance(trigPin, pingPin); //cm 
 boolean pinActivated = false;
 if (d < maxD) {
 pinActivated = true;
 }
 return pinActivated;
}
