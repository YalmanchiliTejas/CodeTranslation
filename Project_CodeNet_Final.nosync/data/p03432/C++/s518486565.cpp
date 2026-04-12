#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 16385
#define M 14
#define MOD 998244353
using namespace std;

namespace Comb
{
    int f[N], g[N];

    int Power(int x, int y)
    {
        int o;

        for(o = 1; y; y >>= 1)
        {
            if(y & 1)
                o = (long long)o * x % MOD;
            x = (long long)x * x % MOD;
        }

        return o;
    }

    void InitComb(void)
    {
        int i;

        for(i = f[0] = 1; i < N; i ++)
            f[i] = (long long)f[i - 1] * i % MOD;
        g[N - 1] = Power(f[N - 1], MOD - 2);
        for(i = N - 2; i > -1; i --)
            g[i] = (long long)g[i + 1] * (i + 1) % MOD;

        return;
    }

    int C(int n, int m)
    {
        return (long long)f[n] * g[m] % MOD * g[n - m] % MOD;
    }
}

int f[N][N], g[N], h[N];
int w[N], r[N];

inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

int InitNTT(int n)
{
    int i, j, c;

    if(!w[0])
    {
        w[0] = 1;
        w[1] = Comb::Power(3, (MOD - 1) >> M);
        for(i = 2; i < (1 << M); i ++)
            w[i] = (long long)w[i - 1] * w[1] % MOD;

        for(i = 0; i < (1 << M); i ++)
            for(j = 0; j < M; j ++)
                if(i & (1 << j))
                    r[i] |= 1 << (M - j - 1);
    }

    for(c = 0; (1 << c) < n; c ++)
        ;

    return c;
}

void NTT(int *f, int n)
{
    int i, j, l;
    int k;

    for(i = 0; i < (1 << n); i ++)
        if(i < (r[i] >> (M - n)))
            swap(f[i], f[r[i] >> (M - n)]);

    for(l = 0; l < n; l ++)
        for(i = 0; i < (1 << n); i += 2 << l)
            for(j = 0; j < (1 << l); j ++)
            {
                k = (long long)f[i + j + (1 << l)] * w[j << (M - l - 1)] % MOD;
                f[i + j + (1 << l)] = Mod(f[i + j] - k);
                f[i + j] = Mod(f[i + j] + k - MOD);
            }

    return;
}

void DFT(int *f, int n)
{
    NTT(f, n);

    return;
}

void IDFT(int *f, int n)
{
    int i, k;

    reverse(f + 1, f + (1 << n));
    NTT(f, n);

    k = Comb::Power(1 << n, MOD - 2);
    for(i = 0; i < (1 << n); i ++)
        f[i] = (long long)f[i] * k % MOD;

    return;
}

int main(void)
{
    int n, m;
    int i, j, c;

    // int ff[10]={2,3,3};
    // int c=InitNTT(5);
    // DFT(ff,c);
    // for(int i=0;i<(1<<c);i++)ff[i]=(long long)ff[i]*ff[i]%MOD;
    // IDFT(ff,c);
    // for(int i=0;i<10;i++)cout<<ff[i]<<' ';

    Comb::InitComb();
    cin >> n >> m;

    for(i = 0; i <= n; i ++)
        f[m][i] = Comb::C(n, i);

    c = InitNTT(n * 2 + 1);
    for(i = m - 1; i >= 0; i --)
    {
        fill(g, g + (1 << c), 0);
        fill(h, h + (1 << c), 0);
        for(j = 0; j <= n; j ++)
        {
            g[n - j] = (long long)f[i + 1][j] * Comb::f[j + 2] % MOD;
            h[j] = Comb::g[j + 3];
        }

        DFT(g, c);
        DFT(h, c);
        for(j = 0; j < (1 << c); j ++)
            g[j] = (long long)g[j] * h[j] % MOD;
        IDFT(g, c);

        for(j = 0; j < n; j ++)
            f[i][n - j - 1] = (long long)g[j] * Comb::g[n - j - 1] % MOD;
        for(j = 0; j <= n; j ++)
            f[i][j] = (f[i][j] + (long long)f[i + 1][j] * (Comb::C(j, 2) + j + 1)) % MOD;
    }
    cout << f[0][0] << endl;

    return 0;
}
