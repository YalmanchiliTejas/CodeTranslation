#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 3020
#define MOD 998244353
using namespace std;

int a[N];
int f[N];

int main(void)
{
    int n, s;
    int i, j, o;

    scanf("%d %d", &n, &s);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);

    f[0] = 1;
    for(i = 1, o = 0; i <= n; i ++)
    {
        for(j = s; j >= a[i]; j --)
            f[j] = (f[j] + f[j - a[i]]) % MOD;
        f[0] = (f[0] + 1) % MOD;
        o = (o + f[s]) % MOD;
        // memset(g, 0, sizeof(int) * (s + 1));
        // for(j)
    }
    printf("%d\n", o);

    return 0;
}
