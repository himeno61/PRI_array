#include <stdio.h>
#include "menu.h"
#include "array.h"
void menu(){
    int select = 1;
    CLEAR;
    while (select != 6){
        printf("\nPodaj numer operacji ktora chcesz wykonac: ");
        printf("\n===========================================");
        printf("\n[1] Dodawanie macierzy ");
        printf("\n[2] Odejmowanie macierzy ");
        printf("\n[3] Mnozenie macierzy przez skalar ");
        printf("\n[4] Mnozenie macierzy ");
        printf("\n[5] Transponowanie macierzy ");
        printf("\n[6] Wyjscie \n");
        select = input();
        switch (select){
            case 1:
                    arrayAdding();
                    break;
            case 2:
                    arraySubraction();
                    break;
            case 3:
                    arrayScalar();
                    break;
            case 4:
                    arrayMultiplication();
                    break;
            case 5:
                    arrayTransposition();
                    break;
            case 6:
                    CLEAR;
                    printf("\n\t!Zegnaj!");
                    break;
            default:
                    CLEAR;
                    printf("===========================================\n");
                    printf("\t!!!  nie obslugiwana!!!\n",select);
                    printf("===========================================");
        }
    }
}
