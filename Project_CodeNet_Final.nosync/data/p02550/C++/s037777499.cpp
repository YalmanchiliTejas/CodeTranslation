#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX = 1001001;
const ll MOD = 1000000007;
int main()
{
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> d(m, -1);
    vector<ll> a;
    ll len = 0;
    while (d[x] == -1)
    {
        d[x] = len;
        a.push_back(x);
        len++;
        x = x * x % m;
    }
    ll ans = 0;
    if (n <= len)
    {
        rep(i, n)
        {
            ans += a[i];
        }
    }
    else
    {
        rep(i, len)
        {
            ans += a[i];
        }
        n -= len;
        ll r = 0;
        rep2(i, d[x], len)
        {
            r += a[i];
        }
        ans += n / (len - d[x]) * r;
        n %= (len - d[x]);
        rep(i, n)
        {
            ans += a[d[x] + i];
        }
    }
    cout << ans << endl;
}