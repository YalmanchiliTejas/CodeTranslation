#include <bits/stdc++.h>
#define int long long
using namespace std;

static const int MOD = 1e9 + 7;
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, *v;
    cin >> n;

    v = new int[n+1];
    v[0] = 0;

    int i;
    for (i = 1; i <= n; ++i) {
        cin >> v[i];
        (v[i] += v[i-1]) % MOD;
    }

    int ans = 0;
    for (i = 1; i < n; ++i)
        (ans += (v[i] - v[i-1]) * ((v[n] - v[i] + MOD) % MOD) % MOD) % MOD;
    
    cout << ans % MOD;
    return 0;
}