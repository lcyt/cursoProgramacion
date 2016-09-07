/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include<ctype.h> 
#include<string.h>


int comprobarSalario(char entrada[]);   //Definición para la función que comprueba que el salario introducido
                                        //es válido y sólo contiene un máximo de 2 decimales

int comprobarBillete(char billete[]);     //Definición de la función que comprueba que hemos solicitado el
                                        //desglose a partir de un billete válido (500,200,100 o 50 €)

int redondear(float s, int eu);         //Función para que tome la parte decimla (2 dígitos) correctamente.
                                        //Para ello tenemos que redondear los céntimos

int main()
{
 
    char entradasalario[8];
    char entradabillete[4];
    
    int billete;
    float salario;
    int euros;
    int centimos;
    int cantidadEuro;
    int cantidadCentimos;
    
    
    const int unidadesEuros[9]={500,200,100,50,20,10,5,2,1};
    
    do
    {
        printf("Introducir salario:\t");
        scanf("%s",entradasalario);
        printf("\nIntroducir billete (500, 200, 100 o 50€):\t");
        scanf("%s",entradabillete);
    } while ((comprobarSalario(entradasalario)==0) || (comprobarBillete(entradabillete)==0));

    salario=atof(entradasalario);
    euros=(int)salario;
    centimos = redondear(salario, euros);
    billete=atoi(entradabillete);  
  
    
    int i;
    int posicionBillete;
    for (i=0;i<4;i++)
    {
        if (unidadesEuros[i]==billete)
            posicionBillete=i;       
    }
    
    for (i=posicionBillete;i<9;i++)
    {
        
        cantidadEuro = euros / unidadesEuros[i];
        euros = euros - (cantidadEuro * unidadesEuros[i]);
        
        if (cantidadEuro > 0)
        {
            if (i<7) 
              printf("Billetes de %d Euros son %d , resto %d.%d €\n\n",unidadesEuros[i],cantidadEuro,euros,centimos);
            else
              printf("Monedas de %d Euros son %d , resto %d.%d €\n\n",unidadesEuros[i],cantidadEuro,euros,centimos);
        }
    }
    

    for (i=3;i<9;i++)
    {
        cantidadCentimos = centimos / unidadesEuros[i];
        centimos = centimos - (cantidadCentimos * unidadesEuros[i]);
        
        if (cantidadCentimos > 0)
            printf("Monedas de %d Céntimos son %d, resto %d céntimos\n\n",unidadesEuros[i],cantidadCentimos,centimos);
        
        
    }
    
   
    
    return 0;
    
}

 int redondear(float s, int eu)
    {
       float salario;
       int redondeado;
       //printf("%f salario\t %d euros en la función\n",s,eu);
       salario = (s - eu)*100;
       //printf("%f\t",salario);
       salario = round(salario);
       //printf("%f\t",salario);
       redondeado = (int)(salario);
       //printf("%d Comprobacion redondeo\t",redondeado);
       return redondeado;
    }
 

 int comprobarSalario(char entrada[])
 {
     
     int punto = 0;
     int numUnidades=0;
     int numDecimales=0;
     int totalEntrada = strlen(entrada);
     int i;
     for (i=0;i<totalEntrada;i++)
     {
         if (entrada[i]==46)
         {
             if (numUnidades>0)
             {
                punto = punto +1; 
             }
             else
             {
               printf ("\n\t\tSalario incorrecto, vuelva a introducir el salario correctamente poniendo las unidades de euro\a\n\n");
               return 0;
               break;  
             }
         }
         else
         {
            if (isdigit(entrada[i]) && (punto < 2 ) && (numDecimales < 2 ))
            {
                if (punto == 1)
                {
                    numDecimales = numDecimales + 1;
                    //printf("\nDecimales %d", numDecimales);
                }
                else
                {
                    numUnidades=numUnidades+1;
                    //printf("\nUnidades %d", numUnidades);
                    
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
 {
     int i=0;
     int longitudArray=strlen(billete);
     //printf("\nBillete:%s\n",billete);
     if (longitudArray<4)
     {
        if ((atoi(billete)==500) || (atoi(billete)==200) || (atoi(billete)==100) || (atoi(billete)==50))
        {
            return 1;
        }
        else
        {
            printf("\nBillete incorrecto\nintroduzca de nuevo los datos\n\n");
            printf("Billete:%s",billete);
            return 0;
        }
     }
     else
     {
         printf("\nBillete incorrecto, recuerde 500, 200, 100 o 50€\n\n");
         return 0;
     }
 }
 