#include<bits/stdc++.h>
using namespace std;
long long dp[200010][3];
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto & a : A) cin >> a;
    dp[0][0] = A[0];
    dp[1][1] = A[1];
    for (int i = 2; i < n; ++i) {
        dp[i][0] = dp[i-2][0]+A[i];
        dp[i][1] = dp[i-2][1]+A[i];
        dp[i][2] = dp[i-2][2]+A[i];
        if (i > 2) {
            dp[i][1] = max(dp[i][1], dp[i-3][0]+A[i]);
            dp[i][2] = max(dp[i][2], dp[i-3][1]+A[i]);
        }
        if (i > 3) {
            dp[i][2] = max(dp[i][2], dp[i-4][0]+A[i]);
        }
    }
    long long ans = max(dp[n-1][1+n%2], dp[n-2][0+n%2]);
    if (n > 2 && n%2 == 1) ans = max(ans, dp[n-3][0]);
    printf("%lld\n", ans);
    return 0;
}
