
#include<stdio.h>


int main()
{   int r,g,b;
    scanf("%d %d %d",&r,&g,&b);
    int p=r*100+g*10+b;
    if(p%4==0){
        printf("YES\n");

    }else{
    printf("NO\n");

    }


    return 0;
}
