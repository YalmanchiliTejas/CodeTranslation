#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;    
    cin >> n;
    vi a(n);
    vector<vll> dp(n, vll(n));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (n & 1)
            dp[i][i] = a[i];
        else
            dp[i][i] = -a[i];
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            int j = i + len - 1;
            if ((n - len) & 1) {
                dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j]);
            }
            else {
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j]);
            }
        }
    }
    cout << dp[0][n - 1] << '\n';

    return 0;
}