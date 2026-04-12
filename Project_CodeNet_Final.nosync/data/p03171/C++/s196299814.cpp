#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 3030;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& e : a) cin >> e;
    
    long long dp[MAX_N][MAX_N] = {};
    for (int s = 1; s <= n; s++) for (int l = 0; l < n; l++) {
        int r = l + s;
        if (n < r) continue;
        if ((n-(r-l)) % 2 == 0) {
            dp[l][r] = max(dp[l+1][r]+a[l], dp[l][r-1]+a[r-1]);
        } else {
            dp[l][r] = min(dp[l+1][r]-a[l], dp[l][r-1]-a[r-1]);
        }
    }
    
    cout << dp[0][n] << endl;
    return 0;
}