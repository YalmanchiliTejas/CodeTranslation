#include <bits/stdc++.h>
#define int long long 

using namespace std;
const int somod = 1e9 + 7;
const int maxn = 1007;

int n, m, a, b, dp[maxn][maxn], c, d, fact[maxn], invfact[maxn], cac[maxn][maxn];

void Add(int &a, int b)
{
    a += b;
    if(a >= somod) a -= somod;
}

int Pow(int a, int b)
{
    int ans = 1;
    for(; b > 0; b >>= 1, a = a * a % somod)
    {
        if(b & 1) ans = ans * a % somod;
    }
    return ans;
}

void Prepare()
{
    fact[0] = 1;
    for(int i = 1; i < maxn; i++) fact[i] = fact[i - 1] * i % somod;
    invfact[maxn - 1] = Pow(fact[maxn - 1], somod - 2);
    for(int i = maxn - 2; i >= 0; i--) invfact[i] = (invfact[i + 1] * (i + 1)) % somod;
}

int C(int k, int n)
{
    return fact[n] * invfact[k] % somod * invfact[n - k] % somod;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("test.inp", "r")) freopen("test.inp", "r", stdin);
    Prepare();
    cin >> n >>a >> b >> c >> d;
    for(int i = 1; i < maxn; i++)
    {
        cac[i][0] = 1;
        for(int j = 1; j < maxn; j++)
        {
            if(i * j <= n) cac[i][j] = cac[i][j - 1] * C(i, j * i) % somod;
        }
    }
    dp[a - 1][0] = 1;
    for(int i = a; i <= b; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = c; k <= d; k++)
            {
                if(i * k > j) break;
                Add(dp[i][j], dp[i - 1][j - i * k] * C(i * k, n - j + i * k) % somod * cac[i][k] % somod * invfact[k] % somod);
            }
        }
        for(int j = 0; j <= n; j++) Add(dp[i][j], dp[i - 1][j]);
    }
    cout << dp[b][n];
}