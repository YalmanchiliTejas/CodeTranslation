#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (ll i = (ll)(start); i < (ll)(n); ++i)
static const ll INFTY = 1L << 62L;
ll MAX = 1000000007;
ll solver(ll *a, ll n)
{
    ll sum = 0, ans = 0;
    rep(i, 0, n)
    {
        sum += a[i];
        sum %= MAX;
    }
    rep(i, 0, n - 1)
    {
        sum -= a[i];
        if (sum < 0)
            sum += MAX;
        ans += (a[i] * sum % MAX);
        ans %= MAX;
    }
    return ans;
}
int main()
{
    ll n;
    cin >> n;
    ll a[n];
    rep(i, 0, n) cin >> a[i];
    cout << solver(a, n) << endl;
}