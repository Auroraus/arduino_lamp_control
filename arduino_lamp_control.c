//超声波台灯程序
//作者：张凡
//邮箱：zf083415@gmail.com
const int Trigpin=2;
const int Echpin=3;
float cm;
char i;
void setup() {
  // put your setup code here, to run once:
pinMode(Trigpin,OUTPUT);
pinMode(Echpin,INPUT);
pinMode(10,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
digitalWrite(10,HIGH);
digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
Serial.begin(9600);
}
int cmm()
{digitalWrite(Trigpin, LOW); 
delayMicroseconds(2); 
digitalWrite(Trigpin, HIGH); 
delayMicroseconds(10); 
digitalWrite(Trigpin, LOW); 
 
cm = pulseIn(Echpin, HIGH) / 58.8235; //算成厘米 
//cm = (int(cm * 100.0)) / 100.0; //保留两位小数 
return cm;}
void openlight()
{digitalWrite(10,LOW);
digitalWrite(8,LOW);
}
void closelight()
{digitalWrite(10,HIGH);
digitalWrite(8,HIGH);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
{char i=Serial.read();
while(i=='a')
{openlight();
if(Serial.available())
{char j=Serial.read();
if(j=='b') {
 digitalWrite(8,HIGH); 
 digitalWrite(10,HIGH); 
 break;}
}
}
while(i=='b')
{closelight();
if(Serial.available())
{char j=Serial.read();
if(j!='b') {
 digitalWrite(8,HIGH); 
 digitalWrite(10,HIGH); 
 break;}
}
}
}
else{
int a=cmm();
if(a>0&&a<=110)
{delay(500);
  int b =cmm();
if(b>0&&b<=110){    //距离判断，在给定条件内台灯才亮
  digitalWrite(10,LOW);
  delay(15000); }  //延时一分钟
}
else digitalWrite(10,HIGH);
}
}
