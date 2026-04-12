#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll MAX = 1e9+1;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector< vector<ll> > dp(n+1, vector<ll>(n+1, 0));
    // dp[i][j] ~ X-Y for a[i:j]
    // dp[i][j] = max(a[i] - dp[i+1][j], a[j-1] - dp[i][j-1])

    for (int layer = 0; layer < n; layer++) {
        for (int i = 0; i < n; i++) {
            if (layer == 0)
                dp[i][i+layer] = a[i];
            else if (i + layer < n) {
                dp[i][i+layer] = max(a[i] - dp[i+1][i+layer], a[i+layer] - dp[i][i+layer-1]);
            }
        }
    }

    cout.precision(20);
    cout << dp[0][n-1] << endl;
}


int main() {
    solve();
	return 0;
}


