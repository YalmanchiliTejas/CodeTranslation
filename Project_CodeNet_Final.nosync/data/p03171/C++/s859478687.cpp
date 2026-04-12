#include <bits/stdc++.h>

using namespace std;

long long dp[3001];
long long a[3001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(12);
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - i + 1; ++j) {
            dp[j] = max(a[j]-dp[j+1], a[j+i-1]-dp[j]);
        }
    }
    cout << dp[1] << endl;
    return 0;
}