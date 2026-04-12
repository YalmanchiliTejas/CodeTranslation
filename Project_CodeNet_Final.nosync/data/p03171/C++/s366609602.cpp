#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &&x : a) cin >> x;

    ll dp[n + 1][n + 1];
    for (int l = 0; l < n; ++l) dp[l][l] = a[l];

    for (int size = 2; size <= n; ++size) {
        for (int l = 0; l + size <= n; ++l) {
            int r = l + size - 1;
            dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}
