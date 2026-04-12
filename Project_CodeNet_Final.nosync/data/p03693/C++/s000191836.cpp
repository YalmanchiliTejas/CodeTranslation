#include <stdio.h>

int main(void)
{
    int r,g,b;
    int n=0;
    
    scanf("%d %d %d",&r,&g,&b);
    
    n = 100*r + 10*g + b;
    n = n%4;
    
    if(n==0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    
    return 0;
}

