#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7, maxn = 2e5 + 9;
int64_t gt[maxn + 1], n, m, k;

int64_t Pow(int x, int y)
{
    if (y == 0)
        return 1;
    else
    {
        int64_t tmp = Pow(x, y/2);
        int64_t res = (tmp % MOD * tmp % MOD) % MOD;
        if (y % 2 == 0)
            return res;
        else
            return (res * x % MOD) % MOD;
    }
}

int64_t Comb(int n, int k)
{
    int64_t a = gt[n];
    int64_t b = (gt[k] % MOD * gt[n - k] % MOD) % MOD;
    int64_t c = (a * Pow(b, MOD - 2)) % MOD;  /// (a / b) % MOD = a * inverse(b) % MOD
    return c;
}

void Enter()
{
    cin >> n >> m >> k;
}

void Init()
{
    gt[0] = 1;
    for (int i = 1; i <= maxn; i++)
        gt[i] = (gt[i - 1] % MOD * i % MOD) % MOD;
}

int64_t SumX()
{
    int64_t s = 0;
    for (int i = 1; i <= m; i++)
    {
        int64_t l = i - 1, r = m - i;
        s = (s + l * i - r * i) % MOD;
    }
    s = (s % MOD * Pow(n, 2)) % MOD;
    return s;
}

int64_t SumY()
{
    int64_t s = 0;
    for (int i = 1; i <= n; i++)
    {
        int64_t l = i - 1, r = n - i;
        s = (s + l * i - r * i) % MOD;
    }
    s = (s % MOD * Pow(m, 2)) % MOD;
    return s;
}

void Solve()
{
    cout << ((SumX() + SumY()) % MOD * Comb(m * n - 2, k - 2)) % MOD;
}

int main()
{
    Enter();
    Init();
    Solve();
    return 0;
}
