#include <stdio.h>
#include <conio.h>

int main () {
    int x,y,h;
    char op;

    tampilan:
    printf("\n\t\t\t----------------------\n");
    printf("\t\t\t|Kalkulator SEDERHANA|\n");
    printf("\t\t\t----------------------\n");


    proses:
    printf("\nMasukkan Angka Pertama: ", x);
    scanf ("%d", &x);
    printf("Masukkan Operator +, -, *, /: ", op);
    scanf (" %c",&op);
    printf("Masukkan Angka kedua: ", y);
    scanf ("%d" , &y);
    
    if (op == '+') {
        h =  x + y;
        printf (" %d+%d=%d", x,y,h);
        }
    else if (op == '-') {
        h = x - y;
        printf(" %d - %d = %d",x,y,h);
    }
    else if (op == '*') {
        h = x * y ;
        printf(" %d * %d = %d", x,y,h);
    }
    else if (op == '/') {
        h = x / y ;
        printf (" %d / %d = %d", x,y,h);
    }
    else {
        printf("Operator tidak dikenal\n");
        goto tampilan;
    }
    getch();
    goto proses;
    return 0;
}
