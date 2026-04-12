#include<stdio.h>
int a,b,c,d;
int main(){
    scanf("%d %d %d",&a,&b,&c);
    if((a*100+b*10+c)%4){
        printf("NO");
    }
    else{
        printf("YES");
    }
}