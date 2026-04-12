#include <bits/stdc++.h>
using namespace std;

long long dp[3010][3010];

int main() {
    int n; cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < n; i++) {
            if (i+k > n) continue;
            if ((n-k)%2 == 0) {
                dp[i][i+k] = max(dp[i][i+k-1]+v[i+k-1], dp[i+1][i+k]+v[i]);
            } else {
                dp[i][i+k] = min(dp[i][i+k-1]-v[i+k-1], dp[i+1][i+k]-v[i]);
            }
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}