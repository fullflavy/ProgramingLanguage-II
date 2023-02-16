/*O usuário diga quantos países irá digitar, e depois digite os seguintes dados do país: nome do País, quantidade total de infectados com Covid e quantidade total de recuperados da Covid. Mostre o resultado ordenado a partir do país que teve maior número de casos de
Covid até o que teve menos Casos. Mostre também o nome de todos os países em que a quantidade de infectados foi inferior a 30.000 habitantes e recuperados
superior a 25.000.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct t_country {
  char name[30];
  int qtdInfected, qtdRecuperados;
} country;

//functions (header):
int compareCountriesCases (const void *a, const void *b);
int condictionOne();
int condictionTwo();

int main(){
  int qtdCountries = 0, i, j;

  printf("\nEnter the number of countries: ");
  scanf("%d", &qtdCountries);
  printf ("\n");
  
  country *countries = malloc(qtdCountries* sizeof(*countries));
  
  for (i = 0; i < qtdCountries; i++) {
    country newCountry;
      
    printf("Enter the name of the %dª country: ", i+1);
    scanf("%s", &newCountry.name);
    printf("Enter the number of infected in %s: ", &newCountry.name);
    scanf("%d", &newCountry.qtdInfected);
      
    printf("Enter the amount recovered in %s: ", &newCountry.name);
    scanf("%d", &newCountry.qtdRecuperados);
      
    countries[i] = newCountry;
    printf("\n");
  }

  qsort(countries, qtdCountries, sizeof(country), compareCountriesCases);
 
  printf("\nDescending order of countries with Covid cases:");

  for (j = 0; j < qtdCountries; j++){
    printf("\n %s", countries[j].name);
  }
  
  printf ("\n\nCountries where the number of infected was less than 30K and the number of recovered was greater than 25K: ");

  for (int j = 0; j < qtdCountries; j++) {
    if (condictionOne(countries[j].qtdInfected) == 1 && condictionTwo(countries[j].qtdRecuperados) == 2){
      printf ("\n%s", countries[j].name);
    } // parte bugada
  }
}

//functions (complete):
// parte que buga
int compareCountriesCases (const void *a, const void *b){
  country *countryA = (country *)a;
  country *countryB = (country *)b;

  return(countryB->qtdInfected - countryA->qtdInfected);
}  

int condictionOne(country *countries){
  if (countries->qtdInfected < 30000){
    return 1;
  }  
}