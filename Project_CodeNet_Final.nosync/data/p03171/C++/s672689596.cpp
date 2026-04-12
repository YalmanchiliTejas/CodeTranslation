#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, i, j;
    cin >> n;
    long long dp[n], a[n];
    for(i = 0; i < n; ++i) cin >> a[i], dp[i] = a[i];
    for(i = 1; i < n; ++i)
        for(j = 0; j < n-i; ++j)
            dp[j] = max(a[i+j] - dp[j], a[j] - dp[j+1]);
    cout << dp[0];
    return 0;
}