#pragma gcc optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = __int128_t;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    vector<ll> ps(n);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ps[i] = (a[i] + (!i ? 0 : ps[i - 1]));
    }
    for (int i = 0; i < n; ++i) {
        ans += ((ps[n - 1] - ps[i]) * a[i]) % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}