#include<stdio.h>
int main(){
    int r,g, b;
    scanf("%d%d%d",&r,&g,&b);
    printf("%s",(r*100+g*10+b)%4==0?"YES":"NO");
    return 0;
}