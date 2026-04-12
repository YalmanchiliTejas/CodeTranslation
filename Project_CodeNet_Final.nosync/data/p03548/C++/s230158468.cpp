#include <stdio.h>

int main(void)
{
    int X, Y, Z, n;

    scanf("%d%d%d", &X, &Y, &Z);

    n = (X-Z)/(Y+Z);

    printf("%d\n", n);

    return 0;
}