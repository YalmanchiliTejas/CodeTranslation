#include <bits/stdc++.h>
using namespace std;
#define int long long
// typedef long long ll;


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1; // cin >> t;
    for (; tt; tt--) {
    int n; cin >> n;
    int mod = 1e9 + 7;
    int dv = (mod + 1) / 2;
    vector<int> a(n); int sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
        sm %= mod;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int d = (sm + mod - a[i]) % mod;
        ans += (a[i] * d) % mod;
        ans %= mod;
    }
    cout << (ans * dv) % mod << "\n";
    }
    return 0;
}


