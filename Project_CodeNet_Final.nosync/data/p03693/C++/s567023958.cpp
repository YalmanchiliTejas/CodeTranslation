#include<stdio.h>
int main(void){
    int r,g,b,wa;
    
    scanf("%d %d %d",&r,&g,&b);

    wa=100*r + 10*g + b;

    if(wa%4==0){
         printf("YES");
    }else{
         printf("NO");
    }

    return 0;
}
