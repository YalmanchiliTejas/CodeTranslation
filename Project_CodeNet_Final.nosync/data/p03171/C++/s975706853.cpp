#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> A(n);

    for (int &i : A) cin >> i;

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = A[i];
    }

    for (int d = 1; d < n; d++) {
        for (int i = 0; i < n - d; i++) {
            dp[i][i + d] = max(A[i] - dp[i + 1][i + d], A[i + d] - dp[i][i + d - 1]);
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}
