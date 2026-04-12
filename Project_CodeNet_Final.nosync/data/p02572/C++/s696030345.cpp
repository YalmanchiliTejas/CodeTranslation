#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> wa(n + 1);
    rep(i, n) wa[i + 1] = wa[i] + a[i];
    // rep(i, n + 1) cout << wa[i] << endl;
    ll ans = 0;
    rep(i, n)
    {
        ans += (wa[n] - wa[i + 1]) % mod * a[i];
        ans %= mod;
        // cout << ans << endl;
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}