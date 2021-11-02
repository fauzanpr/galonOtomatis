int trigPin = 7;
int echoPin = 6;
int sounder = 11;
int tesPin = 10;
int led = 13;
bool gelas;

void setup() {
  Serial.begin (9600);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode (sounder, OUTPUT);
  pinMode (tesPin, INPUT);
  pinMode (led, OUTPUT);
}

void loop() {
  gelas = digitalRead(tesPin);
  if (gelas == 1) {
    digitalWrite (led, HIGH);
    int duration, distance;
    digitalWrite (trigPin, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin, LOW);
    duration = pulseIn (echoPin, HIGH);
    distance = (duration / 2) / 29.1;
    Serial.print ("Jarak Objek = ");
    Serial.print (distance);
    Serial.print (" cm");
    Serial.print ("\r");
    if (distance < 200) {
      digitalWrite (sounder, HIGH);
    } else {
      digitalWrite (sounder, LOW);
    }
  } else {
    digitalWrite (led, LOW);
    digitalWrite (sounder, LOW);
    Serial.println ("Gelas tidak ada");
  }
  delay (1000);
}
