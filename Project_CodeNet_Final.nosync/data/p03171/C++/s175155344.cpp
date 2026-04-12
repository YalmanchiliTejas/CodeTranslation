#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i += 1)
        cin >> a[i];
    
    vector<vector<int64_t>> dp(2, vector<int64_t> (n + 1, 0));
    
    dp[1] = vector<int64_t> (a.begin(), a.end());

    for (int len = 2; len <= n; len += 1)
        for (int start = 0; start + len - 1 < n; start += 1)
            dp[len & 1][start] = max(-dp[1 - (len & 1)][start] + a[start + len - 1], -dp[1 - (len & 1)][start + 1] + a[start]);

    cout << dp[n % 2][0] << "\n";
}