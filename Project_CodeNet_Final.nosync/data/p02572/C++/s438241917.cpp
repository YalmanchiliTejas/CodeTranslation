#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ll ans = 0, ss = v.front(), mod = 1e9+7;
    for (int i = 1; i < n; ++i) {
        ans = (ans + (v[i] * ss % mod)) % mod;
        ss = (ss + v[i]) % mod;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}