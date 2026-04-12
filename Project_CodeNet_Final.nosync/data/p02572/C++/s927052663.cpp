#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> wa(n + 1);
    rep(i, n)
    {
        wa[i + 1] = wa[i] + a[i];
    }
    ll ans = 0;
    rep(i, n)
    {
        ll sum = (wa[n] - wa[i + 1]) % MOD;
        ans += (ll)a[i] * sum;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}