#include <bits/stdc++.h>

#define mod 1000000007
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<ll> v(n), pre(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    pre[n-1] = v[n-1];
    for (int i = n-2; i >= 0; --i) {
        pre[i] = v[i] + pre[i+1];
        pre[i] %= mod;
    }

    ll ans = 0;
    for (int i = 0; i < n-1; ++i) {
        ans += v[i] * pre[i+1];
        ans %= mod;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}
