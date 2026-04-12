#include <bits/stdc++.h>
#define int long long
const int MOD = 1e9 + 7;
using pii=std::pair<int,int>;
using namespace std;

const int maxn = 1e3 + 5;

int n, a, b, c, d, dp[maxn][maxn], fact[maxn], invfact[maxn];

int mod_expo(int x, int p)
{
    if(!p)
        return 1;
    int res = mod_expo(x, p / 2);
    res *= res;
    res %= MOD;
    if(p & 1)
        res *= x;
    return res % MOD;
}

int mod_inv(int x)
{
    return mod_expo(x, MOD - 2);
}

int nCr_mod(int x, int r)
{
    if(x < r)
        return 0;
    int num = fact[x];
    int invdenom = (invfact[r] * invfact[x - r]) % MOD;
    return (num * invdenom) % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = invfact[0] = 1;
    for(int i = 1; i < maxn; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        invfact[i] = mod_inv(fact[i]);
    }
    cin >> n >> a >> b >> c >> d;
    dp[a][n] = 1;
    for(int i = a; i <= b; i++)
        for(int j = n; j >= 0; j--)
            if(dp[i][j])
            {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= MOD;
                int ways = fact[j], mult = invfact[i];
                for(int k = 1; k <= d && i * k <= j; k++)
                {
                    ways *= mult;
                    ways %= MOD;
                    int curways = (invfact[j - k * i] * invfact[k]) % MOD;
                    if(k >= c)
                    {
                        dp[i + 1][j - i * k] += dp[i][j] * ((ways * curways) % MOD);
                        dp[i + 1][j - i * k] %= MOD;
                    }
                }
            }
    cout << dp[b + 1][0] << "\n";
    return 0;
}