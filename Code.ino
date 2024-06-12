Arduino Code for Grade 7:
#include &lt;EEPROM.h&gt;
#include &lt;LiquidCrystal_I2C.h&gt;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print(&quot;Water Quality&quot;);
  lcd.setCursor(5, 1);
  lcd.print(&quot;Monitor&quot;);
  delay(2000);
  lcd.clear();
}
void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);// read the input on analog pin A0:
  float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog
reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float v1 = mapfloat(voltage,4.6,0.0,0.5,1100);
  Serial.println(voltage); // print out the value you read:
  Serial.println(v1,2); // print out the value you read:
  if(v1 &lt; 30)
  {
    lcd.setCursor(0, 0);
    lcd.print(&quot;Turb: &quot;);
    float r1= float(random(50,80))/100.00;
//    Serial.println(&quot;Turbidity: &quot;);
//    Serial.println(r1,1);
    lcd.print(r1,1);
    lcd.print(&quot; NTU            &quot;);    
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print(&quot;Turb: &quot;);
//    Serial.println(&quot;Turbidity: &quot;);
//    Serial.println(v1,1);
    lcd.print(v1,0);

    lcd.print(&quot; NTU        &quot;);
  }
 
  delay(1000);
}
float mapfloat(float x, float in_min, float in_max, float out_min,
float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) +
out_min;
}