#include <bits/stdc++.h>
#define pii pair <int, int>
#define pb push_back
#define mp make_pair
using namespace std;
const long long MOD = 1e9 + 7;
int N;
int A[3003];
long long dp[3003][3003][2];

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; ++i) {
        dp[i][i][0] = dp[i][i][1] = A[i]; //0 MIN 1 MAX
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int sign = (j) % 2 == 0 ? 1 : -1;
            if (i + j <= N) {
                dp[i][i + j][0] = min(dp[i + 1][i + j][1] + sign * A[i], dp[i][i + j - 1][1] + sign * A[i + j]);
                dp[i][i + j][1] = max(dp[i + 1][i + j][0] + sign * A[i], dp[i][i + j - 1][0] + sign * A[i + j]);
            }
            if (i - j > 0) {
                dp[i - j][i][0] = min(dp[i - j][i - 1][1] + sign * A[i], dp[i - j + 1][i][1] + sign * A[i - j]);
                dp[i - j][i][1] = max(dp[i - j][i - 1][0] + sign * A[i], dp[i - j + 1][i][0] + sign * A[i - j]);
            }
        }
    }
    /*for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j)
            cout << dp[i][j][0] << ' ' << dp[i][j][1] << "         ";
        cout << '\n';
    }*/
    if (N % 2 == 0) cout << -1 * dp[1][N][0];
    else cout << dp[1][N][1];
    return 0;
}
