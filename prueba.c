/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<stdio.h>

int main()
{
 //   char nombre[];
    int salario;
    int billete;
    int cantidadEuro;
    
    const int unidadesEuros[9]={500,200,100,50,20,10,5,2,1};
    
    printf("Introducir salario");
    scanf("%d",&salario);
    printf("Introducir billete");
    scanf("%d",&billete);
    
    int i;
    int posicionBillete;
    for (i=0;i<4;i++){
        if (unidadesEuros[i]==billete)
            posicionBillete=i;       
    }
    
    for (i=posicionBillete;i<9;i++){
        
        cantidadEuro=salario / unidadesEuros[i];
        salario = salario - (cantidadEuro * unidadesEuros[i]);
        
        if (cantidadEuro > 0)
        printf("Unidades de %d Euros son %d , resto %d\n\n",unidadesEuros[i],cantidadEuro,salario);
     
        
        
    }
    
    
    return 0;
    
}