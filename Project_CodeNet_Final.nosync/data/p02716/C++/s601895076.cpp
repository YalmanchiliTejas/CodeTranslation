#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long sum = a[0];
    vector<long long> dp(n + 1, 0);
    for (int i = 1; i < n; i++) {
        if (i&1) {
            dp[i + 1] = max(dp[i - 1] + a[i], sum);
        } else {
            dp[i + 1] = max(dp[i - 1] + a[i], dp[i]);
            sum += a[i];
        }
    }
    
    cout << dp[n] << '\n';
    return 0;
}