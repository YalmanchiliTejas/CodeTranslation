#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int mod = 1e9+7;

void solve()
{
    int n; cin >> n;
    vector<int> v(n);
    vector<ll> suffix(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        suffix[i] = (v[i] + suffix[i + 1]) % mod;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = ((ans % mod) + (v[i] * suffix[i + 1] % mod) % mod);
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