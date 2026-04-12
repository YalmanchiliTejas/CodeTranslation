#include<stdio.h>
int main()
{
    int charge, payback, n, x, y;
    charge = 800;
    payback = 200;
    scanf("%d",&n);
    x = n * charge;
    y = n / 15 * payback;
    printf("%d\n",x-y);
    return 0;
}