#include<stdio.h>

int X, Y, Z;

int main(){
    scanf("%d %d %d", &X, &Y, &Z);

    int num = 1;
    while(X >= (num+1)*Y + (num+2)*Z)num++;

    printf("%d", num);

    return 0;
}