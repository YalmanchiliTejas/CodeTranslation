#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 2e5 + 10;
int n, a[maxn], c[maxn];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]), c[i] = a[i];
    sort(c + 1, c + 1 + n);
    for(int i = 1; i <= n; i ++)
        if(a[i] <= c[n / 2])
            printf("%d\n", c[n / 2 + 1]);
        else
            printf("%d\n", c[n / 2]);

    return 0;
}
