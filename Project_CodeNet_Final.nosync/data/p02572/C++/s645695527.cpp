#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (ll i = (ll)(start); i < (ll)(n); ++i)
static const ll INFTY = 1L << 62L;
static const ll MAX = 1000000007;
ll solver(ll *a, ll n)
{
    ll sum[n + 1] = {};
    rep(i, 0, n)
    {
        sum[i + 1] = sum[i] + a[i];
    }
    ll ans = 0;
    rep(i, 0, n)
    {
        ll tmp = (sum[n] - sum[i + 1]) % MAX;
        ans += a[i] * tmp;
        ans %= MAX;
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll a[n];
    rep(i, 0, n) cin >> a[i];
    cout << solver(a, n) << endl;
}