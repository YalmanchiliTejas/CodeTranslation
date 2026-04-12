#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
constexpr lint MOD = 1000000007;
int N, A, B, C, D;

vector<lint> factorial;
vector<lint> facInv;

template <typename T>
T power(T x, T n, T mod)
{
    T ans = 1;
    while (n>0)
    {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}

void cPrecal(int n)
{
    factorial = facInv = vector<lint>(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        factorial[i] = factorial[i - 1] * i % MOD;
        facInv[i] = power(factorial[i], MOD - 2, MOD);
    }
}

lint nCr(int n, int r)
{
    if (n<r || r<0) return 0;
    else return (factorial[n] * facInv[r] % MOD) * facInv[n-r] % MOD;
}

lint coeff(int K, int X, int i)
{
    return (((facInv[X] * factorial[N - i + K * X]) % MOD) * facInv[N - i] % MOD) * power(facInv[K], (lint)X, MOD) % MOD;
}

int main()
{
    cin >> N >> A >> B >> C >> D;
    cPrecal(N+1);
    vector<lint> dp(N + 1);
    dp[0] = 1;
    for (int K = A; K <= B; K++)
    {
        for (int i = N; i >= 0; i--)
        {
            for (int X = C; ((i - K * X) >= 0 && X <= D); X++)
            {
                dp[i] = (dp[i] + coeff(K, X, i) * dp[i - K * X]) % MOD;
            }
        }
    }
    cout << dp[N] << endl;
}
