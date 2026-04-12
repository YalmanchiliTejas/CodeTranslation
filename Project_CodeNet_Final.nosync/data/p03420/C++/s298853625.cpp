#include<stdio.h>

int main()
{
    int n, k,i;
    long ans=0;
    scanf("%d%d", &n, &k);
    for (i = 1; k + i <= n; i++)
    {
        ans += i * (n/(k+i));
        if (n % (k + i) >= k)
            ans += n % (k + i) - k + 1;
        if (k == 0)
            ans--;
    }
    printf("%ld", ans);
    return 0;
}