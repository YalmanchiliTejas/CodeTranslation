#include <bits/stdc++.h>
#define ll long long

using namespace std;

constexpr int ms = 3013;

ll dp[ms][ms];
bool seen[ms][ms];

void solve() {
    int n;
    cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    memset(dp, 0, sizeof(dp));
    memset(seen, false, sizeof(seen));

    function<ll(int, int)> calc_dp = [&] (int i, int j) {
        if (i > j) {
            return 0ll;
        }
        if (seen[i][j]) {
            return dp[i][j];
        }

        dp[i][j] = max(v[i] - calc_dp(i+1, j), v[j] - calc_dp(i, j-1));
        seen[i][j] = true;

        return dp[i][j];
    };

    cout << calc_dp(0, n-1) << endl;
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
