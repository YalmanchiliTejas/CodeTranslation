#include <stdio.h>

int main()
{
    int red, green, blue;
    scanf("%d%d%d", &red, &green, &blue);
    if ((100 * red + 10 * green + blue) % 4 == 0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
