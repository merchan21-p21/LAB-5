/*
 * Diseñado por: Juan Pablo Merchan Puentes - Electronico****************************************************
 * Proyecto: laboratorio-5***********************************************************************************
 *En este codigo se ve la implementacion de un codigo para un controlador(Arduino) mediante el uso de clases.
 ************************************************************************************************************
 */
 //definimos 
#define reference 540
/***********************************************************************************
 * se crea la clase switch_control, la encargada del control del dipswitch**********
 **********************************************************************************/
class switch_control
{
  private:  
    int S0; int S1;int S2;int S3;
    int estado1;int estado_S0; int estado_S1; int estado_S2;
  public:
    
    void switch_ports(int p0, int p1, int p2,int p3)
    {
      S0 = p0;
      S1 = p1;
      S2 = p2;
      S3 = p3;
    }
    void config_switchs()
    {
      pinMode(S0, INPUT);
      pinMode(S1, INPUT);
      pinMode(S2, INPUT);
      pinMode(S3, INPUT);
    }
    int switch_on_off()const
    {
      int estado1;
      estado1 = digitalRead(5);
      return estado1;
    }
    int switch_estado_S0()const
    {
      int estado_S0;
      estado_S0 = digitalRead(2);
      return estado_S0;
    }
    int switch_estado_S1()const
    {
      int estado_S1;
      estado_S1 = digitalRead(3);
      return estado_S1;
    }
    int switch_estado_S2()const
    {
      int estado_S2;
      estado_S2 = digitalRead(4);
      return estado_S2;
    }
    
    
};

 /***********************************************************************************
 * se crea la clase led_control, la encargada del control de los leds**********
 **********************************************************************************/
class led_control
{
  private:
    int D0; int D1;int D2;int D3;
  public:
  //nombrmos los puertos de los leds.
    void set_leds_ports(int p0, int p1, int p2,int p3)
    {
      D0 = p0;
      D1 = p1;
      D2 = p2;
      D3 = p3;
    }
    //Asignamos los led como puertos de salida
    void config_leds()
    {
      pinMode(D0, OUTPUT);
      pinMode(D1, OUTPUT);
      pinMode(D2, OUTPUT);
      pinMode(D3, OUTPUT);
    }
    /****************************************************************
     * se crean las funciones que set_led y clear_led, las cuales van 
     * a encender o apagar los leds.
     ****************************************************************
     */
    void set_led_D0()
    {
      digitalWrite(D0, HIGH);
    }
    void clear_led_D0()
    {
      digitalWrite(D0, LOW);
    }
    void set_led_D1()
    {
      digitalWrite(D1, HIGH);
    }
    void clear_led_D1()
    {
      digitalWrite(D1, LOW);
    }
    void set_led_D2()
    {
      digitalWrite(D2, HIGH);
    }
    void clear_led_D2()
    {
      digitalWrite(D2, LOW);
    }
    void set_led_D3()
    {
      digitalWrite(D3, HIGH);
    }
    void clear_led_D3()
    {
      digitalWrite(D3, LOW);
    }
};
/***********************************************************************************
 * se crea la clase res_variable, la encargada de los datos del potenciometro*******
 **********************************************************************************/
class res_variable
{
  private:
    int A0; int estado_A0;
  public:
    void config_res_port(int res)
    {
      A0 = res;
    }
    void config_res()
    {
      pinMode(A0, INPUT);
    }
    int estado_res()const
    {
      int estado_A0;
      estado_A0 = analogRead(A0);
      return estado_A0;
    }
    
};
/***********************************************************************************
 * se crea la clase tolerancia_res, la encargada de las operanciones metematicas 
 * relacionadas con el calculo de la tolerancia.
 **********************************************************************************/
class tolerance_res
{
  private:
  int porcentage_0_01;int porcentage_0_02;int porcentage_0_03;
  int porcentage_0_04;int porcentage_0_05;int porcentage_0_06;
  int porcentage_0_07;
  public:
    int tolerance_0_01() const
    {
      int porcentage_0_01;
      porcentage_0_01= (reference*0.01);
      return porcentage_0_01;
    }
    int tolerance_0_02() const
    {
      int porcentage_0_02;
      porcentage_0_02= (reference*0.02);
      return porcentage_0_02;
    }
    int tolerance_0_03() const
    {
      int porcentage_0_03;
      porcentage_0_03= (reference*0.03);
      return porcentage_0_03;
    }
    int tolerance_0_04() const
    {
      int porcentage_0_04;
      porcentage_0_04= (reference*0.04);
      return porcentage_0_04;
    }
    int tolerance_0_05() const
    {
      int porcentage_0_05;
      porcentage_0_05= (reference*0.05);
      return porcentage_0_05;
    }
    int tolerance_0_06() const
    {
      int porcentage_0_06;
      porcentage_0_06= (reference*0.06);
      return porcentage_0_06;
    }
    int tolerance_0_07() const
    {
      int porcentage_0_07;
      porcentage_0_07= (reference*0.07);
      return porcentage_0_07;
    }
    
};

/******** se crea un objeto y se le asingna un nombre*************
 *  **************************************************************
 */
switch_control control_1; //Crea un objeto switch_control llamdo control_1
led_control control_2;    //Crea un objeto led_control llamdo control_2
res_variable control_3;   //Crea un objeto res_variable llamdo control_3
tolerance_res control_4;  //Crea un objeto tolerancia_res llamdo control_4
/******************************************************************
 ******************* variables globales****************************  
 *****************************************************************/

int estado = 0;//variable de control del estado del pin S3 del dipswitch
int estado_S0 = 0;//variable de control del estado del pin S0 del dipswitch
int estado_S1 = 0;//variable de control del estado del pin S1 del dipswitch
int estado_S2 = 0;//variable de control del estado del pin S2 del dipswitch
int estado_A0 = 0;//variable de control del estado del pin analogo A0 para el pontenciometro.

// variables de los esados de los leds D0, D1 y D2.
int estado_D0 = 0;
int estado_D1 = 0;
int estado_D2 = 0;

int tolerance_01 = 0;
int tolerance_02 = 0;
int tolerance_03 = 0;
int tolerance_04 = 0;
int tolerance_05 = 0;
int tolerance_06 = 0;
int tolerance_07 = 0;

int tolerance1 = 0;
int tolerance2 = 0;

void setup() {
  Serial.begin(9600);
  control_1.switch_ports(2,3,4,5);
  control_1.config_switchs();
  

  control_2.set_leds_ports(8,9,10,11);
  control_2.config_leds();

  control_3.config_res_port(A0);
  control_3.config_res();
}

void loop() {
  
  estado = control_1.switch_on_off();
  if(estado == HIGH)
  {
    delay(1000);
    control_2.set_led_D3();
    estado_S0 = control_1.switch_estado_S0();
    estado_S1 = control_1.switch_estado_S1();
    estado_S2 = control_1.switch_estado_S2();

    estado_A0 = control_3.estado_res();

    tolerance_01 = control_4.tolerance_0_01();
    tolerance_02 = control_4.tolerance_0_02();
    tolerance_03 = control_4.tolerance_0_03();
    tolerance_04 = control_4.tolerance_0_04();
    tolerance_05 = control_4.tolerance_0_05();
    tolerance_06 = control_4.tolerance_0_06();
    tolerance_07 = control_4.tolerance_0_07();
    Serial.println(estado_A0);
    
      if((estado_S0==0) && (estado_S1== 0) && (estado_S2== 0))
      {
         if(estado_A0 == reference )
         {
          control_2.set_led_D1();
          
          control_2.clear_led_D2(); 
          control_2.clear_led_D0();
         }
         else if (reference > estado_A0 )
         {
          control_2.set_led_D0();
          
          control_2.clear_led_D1();
          control_2.clear_led_D2();
         }
         else if (reference < estado_A0 )
         {
          control_2.set_led_D2();
          
          control_2.clear_led_D0();
          control_2.clear_led_D1();
         }
      }
      else if((estado_S0==0) && (estado_S1== 0) && (estado_S2== 1))
      {
         tolerance1= reference + tolerance_01;
         tolerance2= reference - tolerance_01;
         if((tolerance2 <= estado_A0) && (estado_A0 <= tolerance1) )
         {
          control_2.set_led_D1();
          
          control_2.clear_led_D2(); 
          control_2.clear_led_D0();
         }
         else if (tolerance2 > estado_A0 )
         {
          control_2.set_led_D0();
          
          control_2.clear_led_D1();
          control_2.clear_led_D2();
         }
         else if (tolerance1 < estado_A0 )
         {
          control_2.set_led_D2();
          
          control_2.clear_led_D0();
          control_2.clear_led_D1();
         }
      }
      else if((estado_S0==0) && (estado_S1== 1) && (estado_S2== 0))
      {
         tolerance1=0;
         tolerance2=0;
         tolerance1= reference + tolerance_02;
         tolerance2= reference - tolerance_02;
         if((tolerance2 <= estado_A0) && (estado_A0 <= tolerance1) )
         {
          control_2.set_led_D1();
          
          control_2.clear_led_D2(); 
          control_2.clear_led_D0();
         }
         else if (tolerance2 > estado_A0 )
         {
          control_2.set_led_D0();
          
          control_2.clear_led_D1();
          control_2.clear_led_D2();
         }
         else if (tolerance1 < estado_A0 )
         {
          control_2.set_led_D2();
          
          control_2.clear_led_D0();
          control_2.clear_led_D1();
         }
      }
      else if((estado_S0==0) && (estado_S1== 1) && (estado_S2== 1))
      {
         tolerance1=0;
         tolerance2=0;
         tolerance1= reference + tolerance_03;
         tolerance2= reference - tolerance_03;
         if((tolerance2 <= estado_A0) && (estado_A0 <= tolerance1) )
         {
          control_2.set_led_D1();
          
          control_2.clear_led_D2(); 
          control_2.clear_led_D0();
         }
         else if (tolerance2 > estado_A0 )
         {
          control_2.set_led_D0();
          
          control_2.clear_led_D1();
          control_2.clear_led_D2();
         }
         else if (tolerance1 < estado_A0 )
         {
          control_2.set_led_D2();
          
          control_2.clear_led_D0();
          control_2.clear_led_D1();
         }
      }
      else if((estado_S0==1) && (estado_S1== 0) && (estado_S2== 0))
      {
         tolerance1=0;
         tolerance2=0;
         
         tolerance1= reference + tolerance_04;
         tolerance2= reference - tolerance_04;
         if((tolerance2 <= estado_A0) && (estado_A0 <= tolerance1) )
         {
          control_2.set_led_D1();
          
          control_2.clear_led_D2(); 
          control_2.clear_led_D0();
         }
         else if (tolerance2 > estado_A0 )
         {
          control_2.set_led_D0();
          
          control_2.clear_led_D1();
          control_2.clear_led_D2();
         }
         else if (tolerance1 < estado_A0 )
         {
          control_2.set_led_D2();
          
          control_2.clear_led_D0();
          control_2.clear_led_D1();
         }
      }
      else if((estado_S0==1) && (estado_S1== 0) && (estado_S2== 1))
      {
         tolerance1=0;
         tolerance2=0;
         
         tolerance1= reference + tolerance_05;
         tolerance2= reference - tolerance_05;
         if((tolerance2 <= estado_A0) && (estado_A0 <= tolerance1) )
         {
          control_2.set_led_D1();
          
          control_2.clear_led_D2(); 
          control_2.clear_led_D0();
         }
         else if (tolerance2 > estado_A0 )
         {
          control_2.set_led_D0();
          
          control_2.clear_led_D1();
          control_2.clear_led_D2();
         }
         else if (tolerance1 < estado_A0 )
         {
          control_2.set_led_D2();
          
          control_2.clear_led_D0();
          control_2.clear_led_D1();
         }
      }
      else if((estado_S0==1) && (estado_S1== 1) && (estado_S2== 0))
      {
         tolerance1=0;
         tolerance2=0;
         
         tolerance1= reference + tolerance_06;
         tolerance2= reference - tolerance_06;
         if((tolerance2 <= estado_A0) && (estado_A0 <= tolerance1) )
         {
          control_2.set_led_D1();
          
          control_2.clear_led_D2(); 
          control_2.clear_led_D0();
         }
         else if (tolerance2 > estado_A0 )
         {
          control_2.set_led_D0();
          
          control_2.clear_led_D1();
          control_2.clear_led_D2();
         }
         else if (tolerance1 < estado_A0 )
         {
          control_2.set_led_D2();
          
          control_2.clear_led_D0();
          control_2.clear_led_D1();
         }
      }
      else if((estado_S0==1) && (estado_S1== 1) && (estado_S2== 1))
      {
         tolerance1=0;
         tolerance2=0;
         
         tolerance1= reference + tolerance_07;
         tolerance2= reference - tolerance_07;
         if((tolerance2 <= estado_A0) && (estado_A0 <= tolerance1) )
         {
          control_2.set_led_D1();
          
          control_2.clear_led_D2(); 
          control_2.clear_led_D0();
         }
         else if (tolerance2 > estado_A0 )
         {
          control_2.set_led_D0();
          
          control_2.clear_led_D1();
          control_2.clear_led_D2();
         }
         else if (tolerance1 < estado_A0 )
         {
          control_2.set_led_D2();
          
          control_2.clear_led_D0();
          control_2.clear_led_D1();
         }
      }
      
  }
  else{
    control_2.clear_led_D3();
    control_2.clear_led_D0(); 
    control_2.clear_led_D1();
    control_2.clear_led_D2();
  }
}
