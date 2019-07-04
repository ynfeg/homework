void setup()

{

  pinMode(2, OUTPUT);

  pinMode(3, OUTPUT);

  pinMode(4, OUTPUT);

  pinMode(5, OUTPUT);

  Serial.begin(9600);

}

void loop(){

  if (Serial.available()>0){

     int n,m;
     m = Serial.read();
     for (n = 2; n<= 5; n++){

      if (m % 2 == 1)

      {

        digitalWrite(n, HIGH);

      } 
      else {

        digitalWrite(n, LOW);

      }

        m = m / 2;
        }
        

    }

  

}
