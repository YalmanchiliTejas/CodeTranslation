#define ll long long
#define ld long double
#define MOD 1000000007
#define MOD2 998244353
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define set2d(array, val, m, n) memset(array, val, sizeof(array[0][0]) * m * n);
#include <bits/stdc++.h>
using namespace std;
ll dp[3005][3005];
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x %= p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
ll po(ll base, ll powerRaised)
{
    if (powerRaised != 0)
        return (base * po(base, powerRaised - 1));
    else
        return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, s;
    cin >> n >> s;
    vector<ll> v;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.pb(x);
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= s; j++)
            dp[i][j] = 0;
    for (int i = 0; i < n; i++)
        dp[i + 1][v[i]] = i + 1;
    ll res[s + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
            if (j >= v[i - 1])
                dp[i][j] = (dp[i][j] + res[j - v[i - 1]]) % MOD2;
        for (int j = 1; j <= s; j++)
            res[j] = (res[j] + dp[i][j]) % MOD2;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= s; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + (dp[i][s] * (n - i + 1))) % MOD2;
    cout << ans;
    return 0;
}
