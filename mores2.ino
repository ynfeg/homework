#include "Arduino.h"

#ifndef _MORSE_H
#define _MORSE_H
class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
    void c_space();
    void w_space();
  private:
    int _pin;
    int _dottime;
};
#endif /*_MORSE_H*/


Morse::Morse(int pin)
{
  pinMode(pin,OUTPUT);
  _pin=pin;
  _dottime=250;
}

void Morse::dot()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void Morse::dash()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime*4);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void Morse::c_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*3);
}

void Morse::w_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*7);
}




Morse morse(13);



//定义莫尔斯电码表

char MORSE[][4] = {

  {'.', '-', '*', '*'}, //A

  {'-', '.', '.', '.'}, //B

  {'-', '.', '-', '.'}, //C

  {'-', '.', '.', '*'}, //D

  {'.', '*', '*', '*'}, //E

  {'.', '.', '-', '.'}, //F

  {'-', '-', '.', '*'}, //G

  {'.', '.', '.', '.'}, //H

  {'.', '.', '*', '*'}, //I

  {'.', '-', '-', '-'}, //J

  {'-', '.', '-', '*'}, //K

  {'.', '-', '.', '.'}, //L

  {'-', '-', '*', '*'}, //M

  {'-', '.', '*', '*'}, //N

  {'-', '-', '-', '*'}, //O

  {'.', '-', '-', '.'}, //P

  {'-', '-', '.', '-'}, //Q

  {'.', '-', '.', '*'}, //R

  {'.', '.', '.', '*'}, //S

  {'-', '*', '*', '*'}, //T

  {'.', '.', '-', '*'}, //U

  {'.', '.', '.', '-'}, //V

  {'.', '-', '-', '*'}, //W

  {'-', '.', '.', '-'}, //X

  {'-', '.', '-', '-'}, //Y

  {'-', '-', '.', '.'}  //Z

};



void setup()

{

  Serial.begin(9600);

}



void loop()

{

  String s = "";  

  String morse_s = "";  

  int i, t , temp = 0;

  int n = 0;  

  while (Serial.available() > 0)

  {

    temp = 1; 
    s += char(Serial.read());  

    delay(2);  

    n++;

  }



  if (temp)

  {

    for (i = 0; i < n; i++)

    {

      if (s[i] >= 97 && s[i] <= 122)

      {

        for (t = 0; t < 4; t++)

        {

          morse_s += char(MORSE[int(s[i] - 97)][t]);

        }

      }

      if (int(s[i])!=32){morse_s += '/';}

      else{ morse_s += ' ';}

    }

    Serial.println(morse_s); 

    for (i = 0; morse_s[i] != '\0' ; i++) 
    {

      if (morse_s[i] == '.')morse.dot();

      else if (morse_s[i] == '-')morse.dash();

      else if (morse_s[i] == ' ')morse.w_space();

      else if (morse_s[i] == '/')morse.c_space();

    }

    Serial.println("发送完毕");

    delay(2);

  }

}
