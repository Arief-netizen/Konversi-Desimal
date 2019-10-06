#include <stdio.h>
#include <string.h>

void welcome() {
        printf("Selamat datang di Basis Angka Konverter");
        printf("\nby diketik ulang oleh Imam Arief Al Baihaqy");
		printf("\nby tegar (http://about.me/tegarimansyah)");
}

void cls() {
    int i;
    for (i=0;i<100;i++) {
        printf("\n");
    }
}

void biner(int n) {
    if (n > 0) {
        biner(n/2);
        printf("%d",n%2);
    }
}

int pangkat(int n,int x) {
    int nilai=1,i;
    for (i=0;i<x;i++) {
        nilai=nilai*n;
    }
    return nilai;
}

int cekdesimal(int x) {
    //checking
    if (x < 0)    { //no minus
        return 1;
    }
    //end of checking, all is right
    return 0;
}

int cekbiner(char str[],int *x) {
    int i,dec = 0;

    //checking
    for (i = 0; i < strlen(str); i++)
    {
        if ((str[i] - '0' != 1 ) && (str[i] - '0' != 0))
        {
            return 1;
        }
    }
    //end of checking, all is right

    for (i =0; i <  strlen(str) ; i++)
    {
        if (str[i] - '0' == 1) {
            dec = dec + pangkat(2,strlen(str)-1-i);
        }
    }
    *x = dec;
    return 0;
}

int cekoktal(char str[],int *x) {
    int i,dec=0;

    //checking
    if ((strlen(str) >= 6) && (str[0] > 49)) {
        return 1;
    }

    for (i = 0; i < strlen(str); i++)
    {
        if (!((str[i] > 47 ) && (str[i] < 56)))
        {
            return 1;
        }
    }
    //end of checking, all is right
    for (i =0; i <  strlen(str) ; i++)
    {
        dec = dec + (str[i] - '0') * pangkat(8,strlen(str)-1-i);
    }
    *x = dec;
    return 0;
}

int cekhexa(char str[],int *x) {
    int i,dec=0;

    //checking
    for (i = 0; i < strlen(str); i++)
    {
        if (! ( ((str[i] > 47 ) && (str[i] < 58)) || ((str[i] > 96 ) && (str[i] < 103)) || ((str[i] > 64 ) && (str[i] < 71)) ))
        {
            return 1;
        }
    }
    //end of checking, all is right
    for (i =0; i < strlen(str) ; i++)
    {
        if ((str[i] >= '0' ) && (str[i] <= '9')) {
            dec = dec + (str[i] - '0') * pangkat(16,strlen(str)-1-i);
        }
        else if ((str[i] > '@' ) && (str[i] < 'G')) {
            dec = dec + (str[i] - 55) * pangkat(16,strlen(str)-1-i);
        }
        else if ((str[i] > 96 ) && (str[i] < 'g')) {
            dec = dec + (str[i] - 87) * pangkat(16,strlen(str)-1-i);
        }
    }
    *x = dec;
    return 0;
}

int main() {
    int x,dec;
    char oct[6],bin[16],hex[4];
    welcome();
    while(1) {
    printf("\n\n===============================\nBasis Angka Masukan\n1. Desimal\n2. Biner\n3. Oktal\n4. Heksadesimal\nChoose: ");
    scanf("%d",&x);
    switch(x) {
        case 1:
                    printf("Masukan angka desimal (Maksimal 65535): ");
                    scanf("%d",&dec);
                    if(cekdesimal(dec) != 0) {
                        printf("Input salah");
                        break;
                    }
                    printf("Biner: ");
                    biner(dec);
                    printf("\nOktal: %o",dec);
                    printf("\nHexa: %X",dec);
                    break;
        case 2:
                    printf("Masukan angka biner (Maksimal 16 bit): ");
                    scanf("%s",bin);
                    if(cekbiner(bin,&dec) != 0) {
                        printf("Input salah");
                        break;
                    }
                    printf("\nDesimal: %d",dec);
                    printf("\nOktal: %o",dec);
                    printf("\nHexa: %X",dec);
                    break;
        case 3:
                    printf("Masukan angka Oktal (Maksimal 177777): ");
                    scanf("%s",oct);
                    if(cekoktal(oct,&dec) != 0) {
                        printf("Input salah");
                        break;
                    }
                    printf("Desimal: %d",dec);
                    printf("\nBiner: ");
                    biner(dec);
                    printf("\nHexa: %X",dec);
                    break;
        case 4:
                    printf("Masukan angka hexa (Maksimal FFFF): ");
                    scanf("%s",hex);
                    if(cekhexa(hex,&dec) != 0) {
                        printf("Input salah");
                        break;
                    }
                    printf("Desimal: %d",dec);
                    printf("\nBiner: ");
                    biner(dec);
                    printf("\nOktal: %o",dec);
                    break;
        default: printf("Not Present");
    } //end case
    } //end loop
    return 0;
} //end main
