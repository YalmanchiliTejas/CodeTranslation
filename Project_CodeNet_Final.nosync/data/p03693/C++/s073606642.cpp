#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);

    int n = g*10 + b;
    if (n%4 == 0) printf("YES\n");
    else printf("NO\n");

    
    return 0;
} 

