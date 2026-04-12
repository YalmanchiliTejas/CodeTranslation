#include<stdio.h>

int main(void){
    int r;
    int g;
    int b;
    scanf("%d",&r);
    scanf("%d",&g);
    scanf("%d",&b);
    int X;
    X=100*r+10*g+b;
    if(X%4==0){
    printf("YES\n");}
    else{
    printf("NO\n");
    }
    return 0;
}
