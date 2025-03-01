#include <stdio.h>
#include <math.h>
void dodawanie(float zmienna);
void wprowadzanie();
void mnozenia(float zmienna);
void dzielenie(float zmienna);
void potega(float zmienna);
void procent(float zmienna);
float wynik;//zmienna globalna która jest stale modyfikowana przez jedną liczbę co iteracje nieskończonej pętli
int main() {
    printf("podaj liczbe: ");
    scanf("%f",&wynik); //napisałem to osobno, aby nie wyświetlać wyniku po 1 argumencie
    wprowadzanie();
    return 0;}


void wprowadzanie(){
    float zmienna;
    char znak=0;
    while (1==1){
        while (1==1){//safeguard przed wpisywaniem złego znaku
            printf("podaj znak dzialania(+,-,*,/,p,x).'K' konczy dzialanie kalkulatora: ");//niezbyt eleganckie ale jest jak jest
            scanf(" %c",&znak);
            if (znak=='k'||znak=='K'||znak=='-'||znak=='+'||znak=='*'||znak=='/' || znak=='x'|| znak=='p')break;}//Przy dodawaniu case'ów dodawajcie tutaj adekwatne znaki
        if (znak=='k'||znak=='K') break;//koniec pracy
        printf("podaj liczbe");
        scanf(" %f",&zmienna);
        switch (znak) {
            case '+':
                dodawanie(zmienna);
                break;
            case '-':
                dodawanie(zmienna*-1);
                break;
            case '*':
                mnozenia(zmienna);
                break;
            case '/':
                dzielenie(zmienna);
                break;

            case 'x':
                potega(zmienna);
                break;

            case 'p':
                procent(zmienna);
                break;
                //tutaj inne case'y. Przydałoby się mnożenie(oparte na dodawaniu), potęgowanie(oparte na mnożeniu), dzielenie,(z komunikatem o niedzieleniu przez 0)
                //jakaś silnia(trzeba pominąć drugą liczbę if znak!='!' scanf(zmienna)), jakiś może logarytm, może jakiś pierwiastek(gdzie stopień jest równy drugiej liczbie)
        }
        printf("wynik to: %0.2f\n",wynik);}
}//oczywiście jak kod jest jakoś głupio napisany, to zmieniajcie, pamiętajcie jednak o zachowaniu modularności

void dodawanie (float zmienna){//wprowadzamy zmienną z każdą iteracją
    wynik+=zmienna;} //wszystko jest pakowane w zmienną globalną, która jest po każdej iteracji pętli printowana}
//taka krótka funkcja brzmi głupio, ale chyba tak to powinno się robić

void mnozenia(float zmienna){
    wynik*=zmienna;}

void dzielenie(float zmienna){
    wynik/=zmienna;
}

void potega(float zmienna){
    wynik=pow(zmienna,2);
}

void procent(float zmienna){
    wynik = zmienna/100;
}
