#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<vector<ll>> dp(n, vector<ll>(2));
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = a[0];
    dp[1][1] = a[1];
    for (int i = 2; i < n; i++) {
        if (i & 1) {
            dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + a[i];
            dp[i][0] = dp[i - 2][0] + a[i - 1];
        }
        else {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + a[i];
        }
    }
    //dump(dp);
    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
    return 0;
}