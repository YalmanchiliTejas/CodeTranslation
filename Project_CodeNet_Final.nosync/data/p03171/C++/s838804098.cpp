#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 3'001;

ll dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + i < n; ++j) {
            if ((n - i) % 2) {
                dp[i + 1][j] = max(dp[i][j] + a[j + i], dp[i][j + 1] + a[j]);
            } else {
                dp[i + 1][j] = min(dp[i][j] - a[j + i], dp[i][j + 1] - a[j]);
            }
        }
    }

    cout << dp[n][0] << endl;

    return 0;
}
