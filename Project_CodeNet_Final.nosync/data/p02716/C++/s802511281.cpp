#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sp = n % 2 == 0 ? 1 : 2;

    ll dp[n][sp+1];
    fill(&dp[0][0], &dp[n][0], -3e14);
    for (int i = 0; i < n; i++) {
        if (i <= sp) {
            dp[i][i] = a[i];
        }
        for (int j = 0; j <= sp; j++) {
            for (int k = 0; k <= j && i - 2 - (j - k) >= 0; k++) {
                dp[i][j] = max(dp[i][j], dp[i-2-(j-k)][k] + a[i]);
            }
        }
    }

    ll ans = -3e14;
    for (int j = 0; j <= sp && n - 1 - j >= 0; j++) {
        ans = max(ans, dp[n-1-sp+j][j]);
    }

    cout << ans << endl;

    return 0;
}
