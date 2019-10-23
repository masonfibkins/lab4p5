int sensor1 = 0;
int sensor2 = 0;
int incoming; //to store incoming data from p5

void setup() {
  Serial.begin(9600);
  pinMode(11, OUTPUT);
}

void loop() {
  //read sensor values
  sensor1 = analogRead(A0);
  delay(1);
  sensor2 = analogRead(A1);
  
  //SEND BINARY - send a single byte (value btwn 0-255)
  //Serial.write(sensor1/4);

  //DON'T SEND BINARY & ASCII AT THE SAME TIME
  
  //SEND ASCII - send a message w/ punctuation
  //sensor1,sensor2
  //sensor1,sensor2
  Serial.print(sensor1);
  Serial.print(",");
  Serial. println(sensor2);

  //receive s-erial from p5
  if(Serial.available() > 0){ //if we have data
    incoming = Serial.read();

    if(incoming == 'H'){
      digitalWrite(11, HIGH);
    }

    if(incoming == 'L'){
      digitalWrite(11, LOW);
    }
  } //end receiving serial
  
  
} //end of loop
