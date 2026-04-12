#include <stdio.h>
int main()
{
    int i, n, k;
    char a;
    char b[20];
    scanf("%d", &n);
    scanf("%s", b);
    scanf("%d", &k);
    a = b[k - 1];
    for (i = 0; i < n; i++)
    {
        if (b[i] != a)
            b[i] = '*';
    }
    printf("%s\n", b);
    return 0;
}
