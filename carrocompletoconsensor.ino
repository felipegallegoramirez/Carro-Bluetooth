#include <Servo.h>
Servo xd;


int M1a = 5; 
int M1b = 6; 
int M2a = 9; 
int M2b = 10;           
int est = 'g';         


//3 servo
//2 luz servo
//4 amarillas
//8 Alerta

int bl=2;
int ama=4;
int ale=8;

bool l1=false;
bool l2= false;
bool l3= false;


void setup()  { 
  Serial.begin(9600);    
  pinMode(M2a, OUTPUT);
  pinMode(M2b, OUTPUT);
  pinMode(M1a, OUTPUT);
  pinMode(M1b, OUTPUT);

  pinMode(bl, OUTPUT);
  pinMode(ama, OUTPUT);
  pinMode(ale, OUTPUT);
  xd.attach(3);
  xd.write(0);
 } 
 
void loop()  { 
  //LEE EL Bluetooth
  if(Serial.available()>0){        
      est = Serial.read();
  }

  /*
   Direccion
   a=Frente
   b=Izquierda
   c=Parar
   d=Derecha
   e=Atras
  */
  
  if(est=='a'){           
      analogWrite(M2b, 0);     
      analogWrite(M1b, 0); 
      analogWrite(M2a, 255);  
      analogWrite(M1a, 255);       
  }
  if(est=='b'){          
      analogWrite(M2b, 0);     
      analogWrite(M1b, 0); 
      analogWrite(M2a, 0);  
      analogWrite(M1a, 255);      
  }
  if(est=='c'){         
      analogWrite(M2b, 0);     
      analogWrite(M1b, 0); 
      analogWrite(M2a, 0);    
      analogWrite(M1a, 0); 
  }
  if(est=='d'){          
       analogWrite(M2b, 0);     
       analogWrite(M1b, 0);
       analogWrite(M1a, 0);
       analogWrite(M2a, 255);  
  } 
  
  if(est=='e'){          
       analogWrite(M2a, 0);    
       analogWrite(M1a, 0);
       analogWrite(M2b, 255);  
       analogWrite(M1b, 255);      
  }
  if  (est=='g'){          

/* 
 Servo motor 
 j= Angulo 0
 k= Angulo 90
 l= Angulo 180
*/
  if  (est=='j'){   
    xd.write(0);    
  }
  if  (est=='k'){  
    xd.write(90);
  }
  if  (est=='l'){ 
    xd.write(180);    
  }
/*


*/

      if  (est=='z'){ 
        if(l1==false){
          l1=true;
          digitalWrite(bl, HIGH); 
          }else{
            
                      l1=false;
          digitalWrite(bl, LOW); 
          }
  
  }
        if  (est=='y'){ 
                  if(l2==false){
          l2=true;
          digitalWrite(ama, HIGH); 
          }else{
            
                      l2=false;
          digitalWrite(ama, LOW); 
          }
          
 
  }
        if  (est=='x'){ 
                  if(l3==false){
          l3=true;
          digitalWrite(ale, HIGH); 
          }else{
            
                      l3=false;
          digitalWrite(ale, LOW); 
          }
    
  }




  
}
