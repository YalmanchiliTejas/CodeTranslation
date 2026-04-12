#include <stdio.h>

int main()
{
    int x, y, z, ans = 0;
    scanf("%d %d %d", &x, &y, &z);

    x -= z;
    while(x >= y + z){
        x -= z;
        x -= y;
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}
