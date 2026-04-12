#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

string K;
int D, n;
ll dp[2][100][10000];

ll solve(bool cap, int m, int i) {
    if (i == n)
        return m == 0;
    if (dp[cap][m][i] == -1) {
        dp[cap][m][i] = 0;
        if (cap) {
            for (int d = 0; d < K[i] - '0'; d++) {
                dp[cap][m][i] += solve(false, (m + d) % D, i + 1);
                dp[cap][m][i] %= MOD;
            }
            dp[cap][m][i] += solve(true, (m + K[i] - '0') % D, i + 1);
            dp[cap][m][i] %= MOD;
        } else {
            for (int d = 0; d <= 9; d++) {
                dp[cap][m][i] += solve(cap, (m + d) % D, i + 1);
                dp[cap][m][i] %= MOD;
            }
        }
    }
    return dp[cap][m][i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> K >> D;
    n = K.size();
    memset(dp, -1, sizeof dp);
    ll result = solve(true, 0, 0) - 1;
    if (result < 0)
        result += MOD;
    cout << result << endl;
}
