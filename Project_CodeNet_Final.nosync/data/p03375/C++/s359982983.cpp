#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
int n, m, s[3005][3005], fac[3005], inv[3005], mul2[3005];
int ksm(int a, int b, int mod)
{
    int s = 1;
    while (b)
    {
        if (b & 1)
        {
            s = s * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return s;
}
void init()
{
    s[0][0] = 1;
    for (int i = 1; i <= 3001; i++)
    {
        for (int j = 1; j <= 3001; j++)
        {
            s[i][j] = (s[i - 1][j - 1] + j * s[i - 1][j] % m) % m;
        }
    }
    fac[0] = mul2[0] = 1;
    for (int i = 1; i <= 3001; i++)
    {
        fac[i] = fac[i - 1] * i % m;
    }
    inv[3001] = ksm(fac[3001], m - 2, m);
    for (int i = 3000; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % m;
    }
    for (int i = 1; i <= 3001; i++)
    {
        mul2[i] = mul2[i - 1] * 2 % (m - 1);
    }
}
#undef int
int main(int argc, char const *argv[])
{
    #define int long long
    scanf("%lld%lld", &n, &m);
    init();
    int ans = 0, f = -1, tmp;
    for (int i = 0; i <= n; i++)
    {
        f *= -1;
        tmp = 0;
        for (int k = 0; k <= i; k++)
        {
            tmp = (tmp + s[i + 1][k + 1] * ksm(2LL, ((n - i) * k + mul2[n - i]) % (m - 1), m) % m) % m;
        }
        ans = (ans + f * fac[n] * inv[i] % m * inv[n - i] % m * tmp % m) % m;
    }
    printf("%lld", (ans + m) % m);
    return 0;
}