/*
LIBRERIAS
*/

#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include<ctype.h> 
#include<string.h>


/*
DEFINICIÓN DE FUNCIONES
*/

int comprobarSalario(char entrada[]);   //Definición para la función que comprueba que el salario introducido
                                        //es válido y sólo contiene un máximo de 2 decimales

int comprobarBillete(char billete[]);   //Definición de la función que comprueba que hemos solicitado el
                                        //desglose a partir de un billete válido (500,200,100 o 50 €)

int redondear(float s, int eu);         //Función para que tome la parte decimla (2 dígitos) correctamente.
                                        //Para ello tenemos que redondear los céntimos
/*
FIN DEFINICIÓN DE FUNCIONES
*/



int main()
{
 
    char entradasalario[8]; //En esta variable se almacena el salario introducido desde teclado
    char entradabillete[4]; //En esta variable se almacena el billete introducido desde teclado
    
    int billete;    //En esta variable se almacena el billete despues de haber comprobado
                    //que se ha introducido correctamente
    float salario;  //En esta variable se almacena el salario despues de haberse comprobado
                    //que se ha introducido correctamente
    int euros;      //En esta variable se almacena solo la parte entera del salario
    int centimos;   //En esta variable se almacena solo la parte decimal del salario como parte entera
    int cantidadEuro;   //Esta variable contendrá la cantidad correspondiente al desglose de cada uno
                        //los billetes/monedas de euros correspondiente al salario
    int cantidadCentimos;   //Esta variable contendrá la cantidad correspondiente al desglose de cada uno
                            //las monedas de centimos correspondiente al salario
    
/*
     Array correspondiente a los billetes y monedas que se van a utilizar
*/
    const int unidadesEuros[9]={500,200,100,50,20,10,5,2,1};
    
    
/*
    Bucle para solicitar el salario y el billete a filtrar a través del teclado.
    Se repetirá mientras el salario o el billete introducido no sea correcto.
    Llama a las funciones "comprobarSalario" y "comprobarBillete" para realizar la detección de errores
*/
    do
    {
        printf("\n\nIntroducir salario:\t");
        scanf("%s",entradasalario);
        printf("\nIntroducir billete (500, 200, 100 o 50€):\t");
        scanf("%s",entradabillete);
    } while ((comprobarSalario(entradasalario)==0) || (comprobarBillete(entradabillete)==0));

    
/*
    Una vez validado los valores introducidos realizamos las siguientes operaciones
*/
    salario=atof(entradasalario); //Convierte la entrada del salario válida de cadena de caracteres a formato float
    euros=(int)salario; //En la variable euros almacenamos la parte entera del salario, es decir, los euros.
    centimos = redondear(salario, euros);   //En la variable centimos guardamos el resultado de la función redondear 
    billete=atoi(entradabillete); //Convierte la entrada del billete válido de cadena de caracteres a formato entero 
  
    
    
/*
                OBTENCIÓN DEL DESGLOSE DEL SALARIO
    
*/
    int i;  //Variable para inicializar los bucles FOR
    int posicionBillete;    // Variable para guargar el índice del Array "unidadesEuros" correspondiente al billete introducido.
                            // A partir de esa posición realizaremos el desglose de la cantidad de billetes correspondiente al salario
    
/*
    Bucle que recorre las 4 primeras posiciones del array para obtener el índice correspondiente la billete solicitado
*/
    for (i=0;i<4;i++)
    {
        if (unidadesEuros[i]==billete)
            posicionBillete=i;       
    }
 
/*
    Bucle que recorre todo el array a partir del índice correspondiente al billete solicitado
*/
    for (i=posicionBillete;i<9;i++)
    {
        
        cantidadEuro = euros / unidadesEuros[i]; //Calcula el total de cada uno de los billetes/monedas de Euros
        euros = euros - (cantidadEuro * unidadesEuros[i]); //Va descontando a la variable los euros que ya hemos calculado
        
/*
        Antes de imprimir en pantalla la cantidad correspondiente a cada uno de los billetes o monedas de euro
        se pregunta por la posición del array para indicar si son billetes o monedas
*/
        if (cantidadEuro > 0)
        {
            if (i<7) 
              printf("Billetes de %d Euros son %d , resto %d.%d €\n\n",unidadesEuros[i],cantidadEuro,euros,centimos);
            else
              printf("Monedas de %d Euros son %d , resto %d.%d €\n\n",unidadesEuros[i],cantidadEuro,euros,centimos);
        }
    }
    
/*
    Bucle que recorre el array a partir del índice 3, a partir de monedas de 50 céntimos
*/
    for (i=3;i<9;i++)
    {
        cantidadCentimos = centimos / unidadesEuros[i]; //Calcula el total de las monedas de céntimos
        centimos = centimos - (cantidadCentimos * unidadesEuros[i]);//Va descontando a la variable los céntimos que ya hemos calculado
/*
    Antes de imprimir en pantalla la cantidad correspondiente a cada uno de las monedas
    se compruba que hay céntimos
*/      
        if (cantidadCentimos > 0)
            printf("Monedas de %d Céntimos son %d, resto %d céntimos\n\n",unidadesEuros[i],cantidadCentimos,centimos);
    }
    
    return 0;
}



    /*
     FUNCIONES
     */


  
 int comprobarSalario(char entrada[])
  /*
  Función para comprobar que el salario introducido es correcto
  Comprueba que tenga alguna unidad, que no tenga más de dos puntos
  y que no tenga más de 2 decimales
  */
  {
     
     int punto = 0; //Variable para acumular la cantidad de puntos decimales que contiene el Array "entradaSalario"
     int numUnidades=0; //Variable para acumular la cantidad de unidades enteras que contiene el Array "entradaSalario"
     int numDecimales=0;//Variable para acumular la cantidad de unidades decimales que contiene el Array "entradaSalario"
     int totalEntrada = strlen(entrada);//Variable que contiene el número de caracteres que contiene el Array "entradaSalario"

/*
     Bucle que recorre todo el Array "entradaSalario"
*/
     int i;//Variable para inicializar el bucle FOR
     for (i=0;i<totalEntrada;i++)
     {
         if (entrada[i]==46)//Se comprueba si el valor correspondiente al índice i es un punto decimal
         {
             if (numUnidades>0)//Si hay punto pero ya había unidades de euro se suma 1 a la variable punto
             {
                punto = punto +1; 
             }
             else //Si hay punto pero no hay unidades de euro es un ERROR ya que no puede haber decimales sin parte entera
             {
               printf ("\n\t\tSalario incorrecto, vuelva a introducir el salario correctamente poniendo las unidades de euro\a\n\n");
               return 0;
               break;  
             }
         }
         else
         {
/*
            La siguiente condición se ejecuta si el valor de la posición i del Array no es un punto decimal
            Se comprueba que es un valor numérico, que solo se ha leído un punto decimal como máximo
            y que no contiene más de dos decimales porque en caso contrario el valor introducido es ERRONEO
*/
            if (isdigit(entrada[i]) && (punto < 2 ) && (numDecimales < 2 ))
            {
                if (punto == 1) //Condición para saber si el valor leído correspondiente al índice i del Array se corresponde con un valor entero o decimal
                {
                    numDecimales = numDecimales + 1;
                    
                }
                else
                {
                    numUnidades=numUnidades+1;
                                       
                }
            }
            else
            {
             
                 printf ("\n\t\tSalario incorrecto, vuelva a introducir el salario correctamente\a\n\n");
                 return 0;
                 break;
            }    
        }    
     }
 }
 
 
 
 
 int comprobarBillete(char billete[])
 /*
  Función para comprobar que el billete introducido es correcto
 */
 {
     int i=0;//Variable para inicializar el bucle FOR
     int longitudArray=strlen(billete);//Variable que contiene el número de caracteres que contiene el Array "entradaBillete"
     
/*
     Se comprueba que el valor introducido en el Array "entradaBillete" es válido
     La comprobación hay que realizarla como si el contenido del Array es de tipo entero
*/
        if ((atoi(billete)==500) || (atoi(billete)==200) || (atoi(billete)==100) || (atoi(billete)==50))
        {
            return 1;
        }
        else
        {
            printf("\nBillete incorrecto, recuerde 500, 200, 100 o 50€\n\nintroduzca de nuevo los datos\n\n");
            return 0;
        }
 }
 
 
/*
Función para redondear los decimales,
el valor resultante serán solo los dos dígitos correspondientes a los decimales

 Utilizamos esta función para corregir el problema con la coma flotante en donde se introduce un valor de solo
 dos decimales pero en la variable float se almacena con más decimales variando el contenido real de la parte decimal
 */
 int redondear(float s, int eu)

    {
       float salario;//Variable para almacenar el salario una vez evaluado que es correcto
       
       //printf("%f salario\t %d euros en la función\n",s,eu);
       salario = (s - eu)*100;//Eliminamos la parte entera del salario y convertimos los dos primeros dígitos de la parte decimal en entera
       //printf("%f\t",salario);
       salario = round(salario);//Redondeamos la parte entera que se corresponde con los dígitos de los céntimos del salario
       //printf("%f\t",salario);
       int redondeado = (int)(salario);//Variable que almacena los 2 dígitos decimales redondeados como 2 unidades enteras
       //printf("%d Comprobacion redondeo\t",redondeado);
       return redondeado;//Se devuelven los 2 decimales correspondientes a los céntimos
    }
 
 