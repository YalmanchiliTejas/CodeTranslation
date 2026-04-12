#include<bits/stdc++.h>

using namespace std;

int N, A, B, C, D, mod = 1e9 + 7, fac[2017], inv[2017], grp[1009][1009], dp[1009][1009];

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int substract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}

int pow (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = pow (fac[lim], mod - 2);for (int i=lim - 1; i>=1; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d %d", &N, &A, &B, &C, &D), Prec (2001);
grp[0][0] = 1;
for (int i=1; i<=N; i++)
    for (int j=0; j<=N; j+=i)
    {
        if (j == 0) grp[i][0] = 1;
        else grp[i][j] = mul (grp[i][j - i], comb (j - 1, i - 1));
    }
dp[A - 1][0] = 1;
for (int i=A; i<=B; i++)
    for (int j=0; j<=N; j++)
    {
        dp[i][j] = dp[i - 1][j];
        for (int k=C; k<=D && k * i <= j; k++)
            dp[i][j] = add (dp[i][j], mul (dp[i - 1][j - k * i], mul (comb (N - j + k * i, k * i), grp[i][k * i])));
    }
printf ("%d\n", dp[B][N]);
return 0;
}
