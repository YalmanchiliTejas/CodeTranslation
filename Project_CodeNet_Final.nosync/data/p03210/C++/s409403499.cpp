#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    if (x != 1 && x != 9 && x % 2 == 1)
    {
        printf("YES");
        return 0;
    }

    printf("NO");
    return 0;
}