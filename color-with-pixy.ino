int azul=3;
int verde=5;
int rojo=6;
#include <Pixy2.h>
Pixy2 pixy;
int color;
void setup()
{
  pinMode (rojo, OUTPUT);
pinMode (verde, OUTPUT);
pinMode (azul, OUTPUT);
  Serial.begin(115200);  
  pixy.init();
}

void loop()
{ 
  int i; 
  pixy.ccc.getBlocks();
  
  if (pixy.ccc.numBlocks)
  {
    for (i=0; i<pixy.ccc.numBlocks; i++)
    {
      color=pixy.ccc.blocks[i].m_signature; 
      if(color==1){
        digitalWrite(rojo, HIGH); 
        digitalWrite(azul, LOW); 
        digitalWrite(verde, LOW);
      }
      else if(color==2){
        digitalWrite(rojo, LOW); 
        digitalWrite(azul, HIGH); 
        digitalWrite(verde, LOW);
      }
      else if(color==4){
        digitalWrite(rojo, LOW); 
        digitalWrite(azul, LOW); 
        digitalWrite(verde, HIGH);
        
      }
    }
  }  
}
