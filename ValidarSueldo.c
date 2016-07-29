#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Validar el sueldo introducido y elegir 
 * el tipo de billete máximo a utilizar (500,200,100 ó 50).
 */

int validarSueldo() {

    int cEntera, cDecimal;
    int billete;
    int billeteV;
    char stringNum[5];
    float num;
    
    do{
        printf("Ingrese una cantidad\n");
        scanf("%s",stringNum);
        num=atof(stringNum);
        printf("Billete a empezar \n");
        scanf("%d", &billete);
                
            if (billete == 500) {
                billeteV = 1;
            } else if (billete == 200) {
                billeteV = 1;
            } else if (billete == 100) {
                billeteV = 1;
            } else if (billete == 50) {
                billeteV = 1;
            } else {
                printf("Billete no válido.\n");
                billeteV = 0;
            }
    }
    while ((num<1) || (billeteV != 1) || (validarEntrada(stringNum)!=0));
        if(num!=0){
            //printf("El numero es: %f\n",num);
            printf("el número introducido es %f y el billete es %i\n", num, billete);
            cEntera= (int)num;
            //printf("entera %i\n", cEntera);
            cDecimal=(num-cEntera)*100;
            //printf("decimal %i\n", cDecimal);
        }
    
    return num, billete, cEntera, cDecimal;
}


int validarEntrada(char nom[]) 
{ 
    int i = 0; 
    int valido = 0;
    int numCarac = strlen(nom); 

    for( i = 0; i < numCarac; i++) 
    { 
        if(isalpha(nom[i])) 
        {  
            valido = 1;
            break;
        }else if(isdigit(nom[i])) 
        {  
            valido = 0;
            break;
        }
    }
    return valido; 
}
