#include<cstdio>

int main()
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    x -= z;
    int ans = x / (y + z);

    printf("%d", ans);
}