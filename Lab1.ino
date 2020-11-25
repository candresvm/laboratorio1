
#include <Keypad.h>
#include <LiquidCrystal.h>
const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //three columns
const int rs=A0,en=A1,d4=A2,d5=A3,d6=A4,d7=A5;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
const int btn=13;
int cont=0;
int cont1=0;
int cont2=0;
int cont3=0;

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3','A'},
  {'4','5','6','C'},
  {'7','8','9','J'},
  {'-','0','+','V'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; 
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; 

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

const String password = "CA900813"; 
const String password1 = "AJ881112";
const String password2 = "JA890109";
const String password3 = "VC921121";
String input_password;
void setup(){
  pinMode(btn,INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  input_password.reserve(32);
}

void loop(){
  char key = keypad.getKey();

  if (key){
    Serial.print(key);
    if(key == '-') {
      input_password = ""; // clear input password
    }
    else if(key == '+') {
      if(password == input_password ) {
        Serial.println();
        Serial.println("Contraseña Correcta");
        lcd.setCursor(1,1);
        lcd.print("BIENVENIDO CARLOS ARIAS                 ");
        for (int posicion = 0; posicion < 41; posicion++){
          lcd.scrollDisplayLeft();
          delay(300);
        }
        cont=1;
      }
      else if(password1 == input_password ) {
        Serial.println();
        Serial.println("Contraseña Correcta");
        lcd.setCursor(1,1);
        lcd.print("BIENVENIDO ANDRES JUAREZ                ");
        for (int posicion = 0; posicion < 41; posicion++){
          lcd.scrollDisplayLeft();
          delay(300);
        }
        cont1=1;
      }
      else if(password2 == input_password ) {
        Serial.println();
        Serial.println("Contraseña Correcta");
        lcd.setCursor(1,1);
        lcd.print("BIENVENIDO JAVIER ANDRADA               ");
        for (int posicion = 0; posicion < 41; posicion++){
          lcd.scrollDisplayLeft();
          delay(300);
        }
        cont2=1;
      }
      else if(password3 == input_password ) {
        Serial.println();
        Serial.println("Contraseña Correcta");
        lcd.setCursor(1,1);
        lcd.print("BIENVENIDO CHRISTIAN VILLEGAS           ");
        for (int posicion = 0; posicion < 41; posicion++){
          lcd.scrollDisplayLeft();
          delay(300);
        }
        cont3=1;
      }
      else {
        Serial.println();
        Serial.println("Contraseña Incorrecta");
      }
      input_password = ""; 
    } else {
      input_password += key; 
    }
  }
  if(digitalRead(btn)==HIGH){
    delay(300);
        Serial.println("REGRISTRO DE ASISTENCIA");
        Serial.println("***********************");
          if(cont==1)
            Serial.println("CARLOS ARIAS        INGRESO A LA EMPRESA");
          else
            Serial.println("CARLOS ARIAS        NO INGRESO A LA EMPRESA");
          if(cont1==1)
            Serial.println("ANDRES JUAREZ       INGRESO A LA EMPRESA");
          else
            Serial.println("ANDRES JUAREZ       NO INGRESO A LA EMPRESA");
          if(cont2==1)
            Serial.println("JAVIER ANDRADA      INGRESO A LA EMPRESA");
          else
            Serial.println("JAVIER ANDRADA      NO INGRESO A LA EMPRESA");
          if(cont3==1)
            Serial.println("CHRISTIAN VILLEGAS  INGRESO A LA EMPRESA");
          else
            Serial.println("CHRISTIAN VILLEGAS  NO INGRESO A LA EMPRESA");
          }
}
