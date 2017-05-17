#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "operate.h"

int x3, y3, enter = 1;
double table3[SMAX][SMAX];

void arrayDimension(int* x, int* y){
    printf("\n===========================================\n");
    printf("Podaj wymiary macierzy: \n");
    do{
       printf("\tSzerokosc: ");
       *x = input();
    } while (*x<=0 || *x>= SMAX);
    do{
        printf("\tWysokosc: ");
        *y = input();
    }while (*y <= 0 || *y>= SMAX);
}
void arrayFill(int x, int y, double table[][SMAX]){
    int i, j;
    double z;
    //CLEAR;
    printf("\n===========================================\n");
    fseek(stdin,0,SEEK_END);
    for(i = 0; i < y; i++)
    {
        for(j = 0; j < x; j++)
        {
            printf("\tPodaj zawartosc[%d][%d]: ", i+1, j+1);
            z = inputD();
            table[i][j] = z;
        }
    }

}
void arrayAddingNew(){
    int x1 = 1, x2 = 2, y1 = 3, y2 = 4;
    int i, j;
    double table1[SMAX][SMAX];
    double table2[SMAX][SMAX];
    CLEAR;
    while (x1 != x2 || y1 != y2){
        printf("\n!! Aby dodac macierze musza miec takie same wymiary!!\n");
        arrayDimension(&x1,&y1);
        arrayDimension(&x2,&y2);
    }
    arrayFill(x1, y1, table1);
    arrayFill(x2, y2, table2);
    CLEAR;
    printf("\n===========================================\n");
    printf("Suma tych dwoch macierzy to: \n");
    for(i = 0; i < y1; i++ ){
        for(j = 0; j < x1; j++){
            printf("%3f ",table1[i][j]+table2[i][j]);
            table3[i][j]=table1[i][j]+table2[i][j];
        }
        printf("\n");
    }
    x3=x1;
    y3=y1;
}
void arrayAddingMem(){
    int x = 11, y = 12;
    int i, j;
    double table[SMAX][SMAX];
    CLEAR;
    printf("Wymiary macierzy z pamieci: x= %d, y= %d",x3,y3);
    x = x3;
    y = y3;
    arrayFill(x, y, table);
    CLEAR;
    printf("\n===========================================\n");
    printf("Suma tych dwoch macierzy to: \n");
    for(i = 0; i < y; i++ ){
        for(j = 0; j < x; j++){
            printf("%3f ",table[i][j]+table3[i][j]);
            table3[i][j]=table[i][j]+table3[i][j];
        }
        printf("\n");
    }
}
void arrayAdding(){
    int operate;
    if (enter == 1) {
        arrayAddingNew();
        enter++;
    }
    else{
    CLEAR;
    printf("Podaj numer operacji: \n");
    printf("[1] Wykorzystaj poprzedni wynik.\n");
    printf("[2] Podaj nowe dane.\n");
    operate = input();
    switch (operate){
        case 1:
                arrayAddingMem();
                break;
        case 2: arrayAddingNew();
                break;
        default:
                printf("!!Liczba nie obslugiwana!!\n");
                break;
        }
    }
}
void arraySubractionNew (){
    int x1 = 1, x2 = 2, y1 = 3, y2 = 4;
    int i, j;
    double table1[SMAX][SMAX];
    double table2[SMAX][SMAX];
    CLEAR;
    while (x1 != x2 || y1 != y2){
        printf("\n!! Aby odjac macierze musza miec takie same wymiary!!\n");
        arrayDimension(&x1,&y1);
        arrayDimension(&x2,&y2);
    }
    arrayFill(x1, y1, table1);
    arrayFill(x2, y2, table2);
    CLEAR;
    printf("\n===========================================\n");
    printf("Roznica tych dwoch macierzy to: \n  ");
    for(i = 0; i < y1; i++ ){
        for(j = 0; j < x1; j++){
            printf("%3f ",table1[i][j]-table2[i][j]);
            table3[i][j]=table1[i][j]-table2[i][j];
        }
        printf("\n");
    }
    x3=x1;
    y3=y1;
}
void arraySubractionMem(){
    int x = 11, y = 11;
    int i, j;
    double table[SMAX][SMAX];
    CLEAR;
    printf("Wymiary macierzy z pamieci: x= %d, y= %d\n",x3,y3);
    printf("!! Od starej macierzy zostanie odjeta nowa!!");
    x = x3;
    y = y3;
    arrayFill(x, y, table);
    CLEAR;
    printf("\n===========================================\n");
    printf("Roznica tych dwoch macierzy to: \n");
    for(i = 0; i < y; i++ ){
        for(j = 0; j < x; j++){
            printf("%3f ",table3[i][j]-table[i][j]);
            table3[i][j]=table3[i][j]-table[i][j];
        }
        printf("\n");
    }
}
void arraySubraction (){
    int operate;
    if (enter == 1) {
        arraySubractionNew();
        enter++;
    }
    else{
    CLEAR;
    printf("Podaj numer operacji: \n");
    printf("[1] Wykorzystaj poprzedni wynik.\n");
    printf("[2] Podaj nowe dane.\n");
    operate = input();
    switch (operate){
        case 1:
                arraySubractionMem();
                break;
        case 2: arraySubractionNew();
                break;
        default:
                printf("!!Liczba nie obslugiwana!!\n");
                break;
        }
    }
}
void arrayScalarMem (){
    int i, j;
    double z;
    CLEAR;
    printf("\nPodaj skalar przez ktory chcesz pomnozyc ta macierz: ");
    z = inputD();
    CLEAR;
    printf("\n===========================================\n");
    printf("Macierz po pomnozeniu przez skalar %f: \n",z);
    for(i = 0; i < y3; i++ ){
        for(j = 0; j < x3; j++){
            printf("%3f ", table3[i][j] * z);
            table3[i][j] = table3[i][j] * z;
        }
        printf("\n");
    }
}
void arrayScalarNew(){
    int x = 1, y = 3;
    int i, j;
    double z;
    double table[SMAX][SMAX];
    CLEAR;
    arrayDimension(&x, &y);
    arrayFill(x, y, table);
    printf("\nPodaj skalar przez ktory chcesz pomnozyc ta macierz: ");
    z = inputD();
    CLEAR;
    printf("\n===========================================\n");
    printf("Macierz po pomnozeniu przez skalar %f: \n",z);
    for(i = 0; i < y; i++ ){
        for(j = 0; j < x; j++){
            printf("%3f ", table[i][j] * z);
            table3[i][j] = table[i][j] * z;
        }
        printf("\n");
    }
    x3 = x;
    y3 = y;
}
void arrayScalar (){
    int operate;
    if (enter == 1) {
        arrayScalarNew();
        enter++;
    }
    else{
    CLEAR;
    printf("Podaj numer operacji: \n");
    printf("[1] Wykorzystaj poprzedni wynik.\n");
    printf("[2] Podaj nowe dane.\n");
    operate = input();
    switch (operate){
        case 1:
                arrayScalarMem();
                break;
        case 2: arrayScalarNew();
                break;
        default:
                printf("!!Liczba nie obslugiwana!!\n");
                break;
        }
    }
}
void arrayTranspositionNew(){
    int x = 1, y = 3;
    int i, j;
    double table[SMAX][SMAX];
    CLEAR;
    arrayDimension(&x, &y);
    arrayFill(x, y, table);
    CLEAR;
    for (i = 0; i < y; i++)
      for( j= 0 ; j < x ; j++ )
         table3[j][i] = table[i][j];
    printf("\n===========================================\n");
    printf("Macierz po transpozycji : \n");
    for (i = 0; i < x; i++) {
      for (j = 0; j < y; j++)
         printf("%3f",table3[i][j]);
      printf("\n");
   }
    x3 = y;
    y3 = x;
}
void arrayTranspositionMem(){
    int x = x3, y = y3;
    int i,j;
    double table[SMAX][SMAX];
    for (i = 0; i < y; i++)
      for( j= 0 ; j < x ; j++ )
         table[i][j] = table3[i][j];
    CLEAR;
    for (i = 0; i < y; i++)
      for( j= 0 ; j < x ; j++ )
         table3[j][i] = table[i][j];
    printf("\n===========================================\n");
    printf("Macierz po transpozycji : \n");
   for (i = 0; i < x; i++) {
      for (j = 0; j < y; j++)
         printf("%3f ",table3[i][j]);
      printf("\n");
   }
    x3 = y;
    y3 = x;
}
void arrayTransposition(){
    int operate;
    if (enter == 1) {
        arrayTranspositionNew();
        enter++;
    }
    else{
    CLEAR;
    printf("Podaj numer operacji: \n");
    printf("[1] Wykorzystaj poprzedni wynik.\n");
    printf("[2] Podaj nowe dane.\n");
    operate = input();
    switch (operate){
        case 1:
                arrayTranspositionMem();
                break;
        case 2: arrayTranspositionNew();
                break;
        default:
                printf("!!Liczba nie obs³ugiwana!!\n");
                break;
        }
    }
}
void arrayMultiplicationNew(){
    int x1 = 1, x2 = 2, y1 = 3, y2 = 4;
    int i, j, k, sum=0;
    double table1[SMAX][SMAX];
    double table2[SMAX][SMAX];
    CLEAR;
    while (x1 != y2){
        printf("\n!! Aby pomnozyc macierze x1 musi byc rownie y2!!\n");
        arrayDimension(&x1,&y1);
        arrayDimension(&x2,&y2);
    }
    arrayFill(x1, y1, table1);
    arrayFill(x2, y2, table2);
    for (i = 0; i < y1; i++) {
      for (j = 0; j < x2; j++) {
        for (k = 0; k < y2; k++) {
          sum = sum + table1[i][k]*table2[k][j];
        }
        table3[i][j] = sum;
        sum = 0;
      }
    }
    printf("\n Macierz po wymnozeniu dwoch wejsciowych: \n");
    for (i = 0; i < y1; i++) {
      for (j = 0; j < x2 ; j++)
         printf("%3f",table3[i][j]);
      printf("\n");
   }
   x3 = x2;
   y3 = y1;
}
void arrayMultiplicationMem(){
    int x1 = 11, x2 = 22, y1 = 33, y2 = 44;
    int i, j, k, sum=0;
    double table1[SMAX][SMAX];
    double table2[SMAX][SMAX];
    x1 = x3;
    y1 = x3;
    for (i = 0; i < y3; i++)
      for( j= 0 ; j < x3 ; j++ )
         table1[i][j] = table3[i][j];
    CLEAR;
    printf("Wymiary macierzy z pamieci: x= %d, y= %d\n",x1,y1);
    printf("!! Od starej macierzy zostanie pomnozona przez nowa!!");
    while (x1 != y2){
        printf("\n!! Aby pomnozyc macierze x1 musi byc rownie y2!!\n");
        arrayDimension(&x2,&y2);
    }
    arrayFill(x2, y2, table2);
    for (i = 0; i < y1; i++) {
      for (j = 0; j < x2; j++) {
        for (k = 0; k < y2; k++) {
          sum = sum + table1[i][k]*table2[k][j];
        }
        table3[i][j] = sum;
        sum = 0;
      }
    }
    printf("\n Macierz po wymnozeniu dwoch wejsciowych: \n");
    for (i = 0; i < y1; i++) {
      for (j = 0; j < x2 ; j++)
         printf("%3f ",table3[i][j]);
      printf("\n");
   }
   x3 = x2;
   y3 = y1;
}
void arrayMultiplication(){
    int operate;
    if (enter == 1) {
        arrayMultiplicationNew();
        enter++;
    }
    else{
    CLEAR;
    printf("Podaj numer operacji: \n");
    printf("[1] Wykorzystaj poprzedni wynik.\n");
    printf("[2] Podaj nowe dane.\n");
    operate = input();
    switch (operate){
        case 1:
                arrayMultiplicationMem();
                break;
        case 2: arrayMultiplicationNew();
                break;
        default:
                printf("!!Liczba nie obs³ugiwana!!\n");
                break;
        }
    }
}
