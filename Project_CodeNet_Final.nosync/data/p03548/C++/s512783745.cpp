#include <bits/stdc++.h>

int X, Y, Z;

int main()
{
    //
    scanf("%d %d %d", &X, &Y, &Z);
    X -= Z;
    printf("%d\n", X / (Y + Z));
}
