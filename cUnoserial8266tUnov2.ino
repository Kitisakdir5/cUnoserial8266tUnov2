#include <Wire.h>

////////// variable serial tx , rx  //////////////////
byte switchr1 = 0  ; 
int Usend66 = 0 , E66sendU = 0 , checkserial1 = 0 ;
int countsend1 = 0 , ctime = 1 ,ctime2 = 1 ;
String E66sendUs ;

void setup() {
Serial.begin(115200); // 9600
Serial.println();
Serial.println("Begin Test Uno send data with TX RX  to ESP8266 ") ;
delay(2000) ;
 Serial.println("Wait Send number to ESP8266") ; 
 Serial.print("\n") ;
 delay(500) ;

} //////////////// END setup Loop //////////////////////

void loop() {

//////////////////  if countsend1 = 3 //////////////////////
   if ( countsend1 == 5 ) { // 3 
    // checkpush1 = 0 ;
 Serial.print("countsend1 = ") ;
 Serial.print(countsend1) ;
 Serial.print("  ") ;
 Serial.print("amount of sending 1234= ") ;
 Serial.print(ctime) ;
 Serial.print("\n") ;
    Serial.print("Send data = to ESP8266 is "); 
     Usend66 = 1234 ;
    Serial.println(Usend66); 
    delay(200) ;
    Serial.print(Usend66) ;
    Serial.print("\n") ;
    delay(100) ;
    Serial.flush(); 
    delay(1000) ; // 200
    countsend1 = 0 ;
    ctime++;
   } /////////// END countsend1 == 3///////////


 checkserial1 = Serial.available() ;      
  while ( checkserial1 > 0) /// While loop 1
  {
    int  E66sendU = Serial.parseInt(); // Serial.parseInt();

     Serial.println(Serial.read());
     
     if ( E66sendU == 2222 )   ///  if ( Serial.read() == '\n')
    {
      Serial.print("Receive data 2222 from ESP8266 is ");
      Serial.println(E66sendU) ;
       Serial.print("countsend1 = ") ;
       Serial.print(countsend1) ;
     Serial.print("  ") ;
     Serial.print("amount of receiving 2222= ") ;
     Serial.print(ctime2) ;
     Serial.print("\n") ;
      checkserial1 = 0 ;
      ctime2++;
      delay(1000) ;
     }  ////// END   if ( E66sendU == 2000 ){         
       
     if ( E66sendU != 2222 )   ///  if ( Serial.read() == '\n')
    {
      Serial.print("no data from ESP8266 ");
      Serial.println(E66sendU) ;
      checkserial1 = 0 ;
      delay(200) ; // delay(200)
     }  ////// END   if ( E66sendU == 2000 ){ 



    }  //// END  while ( checkserial1 < 1 )
 Serial.print("countsend1 = ") ;
 Serial.print(countsend1) ;
 Serial.print("\n") ;
  countsend1++ ;
  delay(1000) ;

}  //////////////// END Void Loop //////////////////////


