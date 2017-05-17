#include <stdio.h>
#include <stdlib.h>
#include "operate.h"

int input() {
  char string[5];
  int n = 0;
  while (n == 0){
    gets(string);
    n = atoi(string);
    if (n == 0)
        printf("!!Podaj liczbe dodatnia: ");
  }
  return n;
}
double inputD() {
   char string[5];
  double n;
  do{
    gets(string);
    n = atof(string);
    if (n == 0.0)
        printf("!!Podaj liczbe dodatnia: ");
  }while (n == 0.0);
  return n;
}

