#include <Morse.h>
int pin = 13;
char MORSE[][4] = {

  {'morse.dot()', 'morse.dash()', 'w_space()', 'w_space()'}, //A

  {'morse.dash()', 'morse.dot()', 'morse.dot()', 'morse.dot()'}, //B

  {'morse.dash()', 'morse.dot()', 'morse.dash()', 'morse.dot()'}, //C

  {'morse.dash()', 'morse.dot()', 'morse.dot()', 'w_space()'}, //D

  {'morse.dot()', 'w_space()', 'w_space()', 'w_space()'}, //E

  {'morse.dot()', 'morse.dot()', 'morse.dash()', 'morse.dot()'}, //F

  {'morse.dash()', 'morse.dash()', 'morse.dot()', 'w_space()'}, //G

  {'morse.dot()', 'morse.dot()', 'morse.dot()', 'morse.dot()'}, //H

  {'morse.dot()', 'morse.dot()', 'w_space()', 'w_space()'}, //I

  {'morse.dot()', 'morse.dash()', 'morse.dash()', 'morse.dash()'}, //J

  {'morse.dash()', 'morse.dot()', 'morse.dash()', 'w_space()'}, //K

  {'morse.dot()', 'morse.dash()', 'morse.dot()', 'morse.dot()'}, //L

  {'morse.dash()', 'morse.dash()', 'w_space()', 'w_space()'}, //M

  {'morse.dash()', 'morse.dot()', 'w_space()', 'w_space()'}, //N

  {'morse.dash()', 'morse.dash()', 'morse.dash()', 'w_space()'}, //O

  {'morse.dot()', 'morse.dash()', 'morse.dash()', 'morse.dot()'}, //P

  {'morse.dash()', 'morse.dash()', 'morse.dot()', 'morse.dash()'}, //Q

  {'morse.dot()', 'morse.dash()', 'morse.dot()', 'w_space()'}, //R

  {'morse.dot()', 'morse.dot()', 'morse.dot()', 'w_space()'}, //S

  {'morse.dash()', 'w_space()', 'w_space()', 'w_space()'}, //T

  {'morse.dot()', 'morse.dot()', 'morse.dash()', 'w_space()'}, //U

  {'morse.dot()', 'morse.dot()', 'morse.dot()', 'morse.dash()'}, //V

  {'morse.dot()', 'morse.dash()', 'morse.dash()', 'w_space()'}, //W

  {'morse.dash()', 'morse.dot()', 'morse.dot()', 'morse.dash()'}, //X

  {'morse.dash()', 'morse.dot()', 'morse.dash()', 'morse.dash()'}, //Y

  {'morse.dash()', 'morse.dash()', 'morse.dot()', 'morse.dot()'}  //Z

};
void setup() {
  Serial.begin(9600); //设置波特率为9600，一般是这个波特率

}

void loop() {
   String str = "";  //定义未转义字符串

  String morse_s = "";  //定义转义后字符串

  int i, t , temp = 0;

  int n = 0;  //对传入字符个数计数

  while (Serial.available() > 0)

  {

    temp = 1;  //判断是否有数据传入

    str += char(Serial.read());  //将传入的数据储存在字符串中

    delay(2);  //延迟保证传入正常

    n++;

  }



  if (temp)

  {

    //查询Morse电码表并进行转换

    for (i = 0; i < n; i++)

    {

      for (t = 0; t < 4; t++)

      {

        //判断是否为小写字母，如果是则转义

        if (str[i] >= 97 && str[i] <= 122)

        {

          morse_s += char(MORSE[int(str[i] - 97)][t]);

        }

      }

      //每段Morse之后补空格

      morse_s += ' ';

    }

    Serial.println(morse_s);  //串口传入


  }
}
