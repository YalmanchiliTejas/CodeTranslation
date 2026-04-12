#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    using ll = long long;

    vector<vector<ll>> dp(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        dp[0][i] = (n % 2 ? 1 : -1) * a[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j + i < n; j++) {
            if ((n - i) % 2) {
                dp[i][j] = max(dp[i - 1][j] + a[j + i], dp[i - 1][j + 1] + a[j]);
            } else {
                dp[i][j] = min(dp[i - 1][j] - a[j + i], dp[i - 1][j + 1] - a[j]);
            }
        }
    }

    cout << dp[n - 1][0] << endl;
}
