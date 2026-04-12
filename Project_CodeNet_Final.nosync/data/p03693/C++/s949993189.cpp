#include <cstdio>

int main()
{
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);

    int sum = 100*r + 10*g + b;
    if (sum % 4 == 0)   printf("%s", "YES");
    else printf("%s", "NO");
    
}