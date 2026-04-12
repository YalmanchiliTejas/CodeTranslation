#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define se second
#define fi first
#define rep(i, l, r) for (ll i = (ll)(l); i < (ll)(r); i++)
#define print(v) for (const auto itr : v){cout << itr << ' ';} cout << endl;
long long int powermod(long long int x, unsigned long long int y, long long int p){long long int res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}

#define mod 1000000007
using namespace std;
#define inf 1e18
const ll INF = 1e18L + 5;
const ll maxn = 1e5 + 5;
ll ceel(ll a, ll b)
{
   if (a % b == 0)
       return a / b;
   return a / b + 1;
}
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); };


int main()
{

    ll n;
    cin >> n;
    vector <ll> a(n + 1);
    rep(i, 1, n + 1)
    {
        cin >> a[i];
    }
    vector<ll> dp(n + 1, 0);
    dp[1] = 0;
    vector<ll> prefix(n + 1);
    prefix[1] = a[1];
    for (ll i = 3; i <= n; i += 2)
    {
        prefix[i] = prefix[i - 2] + a[i];
    }
    for (ll i = 2; i <= n; i++)
    {
        if (i & 1)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        }
        else
        {
            dp[i] = a[i] + dp[i - 2];
            dp[i] = max(dp[i], prefix[i - 1]);
        }
    }
    cout << dp[n];
return 0;
}
