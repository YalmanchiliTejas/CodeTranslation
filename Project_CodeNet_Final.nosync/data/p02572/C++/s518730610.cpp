#include<bits/stdc++.h>
using namespace std; 
using ll = long long;

int md = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll& item : v) cin >> item;

    // LOGIC
    vector<ll> sum(n);
    sum[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        sum[i] = sum[i + 1] + v[i];
        sum[i] %= md;
    }

    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += v[i - 1] * sum[i];
        ans %= md;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while(t--) {
        solve();
    }
}
