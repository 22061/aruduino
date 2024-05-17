int TRIG = 3;
int ECHO = 2;

double duration = 0;
double distance = 0;
double speed_of_sound = 331.5 + 0.6 * 25; //気温が25度の場合

void setup() {
  Serial.begin( 9600 );

  pinMode(ECHO, INPUT );
  pinMode(TRIG, OUTPUT );
}

void loop() {
  digitalWrite(TRIG, LOW); 
  delayMicroseconds(2); 
  digitalWrite( TRIG, HIGH );
  delayMicroseconds( 10 ); 
  digitalWrite( TRIG, LOW );
  duration = pulseIn( ECHO, HIGH ); 

  if (duration > 0) {
    duration = duration / 2; 
    distance = duration * speed_of_sound * 100 / 1000000;
    Serial.print("Distance:");
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(700);
}
