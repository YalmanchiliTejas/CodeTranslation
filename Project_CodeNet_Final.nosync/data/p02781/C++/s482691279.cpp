#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    int K;
    cin >> K;
    int dp[105][2][105];
    // i桁目に0でない数字がj個ある数字の数。
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        int ni = s[i] - '0';
        for (int j = 0; j < 105; j++) {
            dp[i + 1][1][j + 1] += dp[i][1][j] * 9;
            dp[i + 1][1][j] += dp[i][1][j];
            if (ni == 0) {
                dp[i + 1][0][j] += dp[i][0][j];
            } else if (ni != 0) {
                dp[i + 1][1][j + 1] += dp[i][0][j] * (ni - 1);
                dp[i + 1][1][j] +=
                    dp[i][0]
                      [j]; // i桁目が0でないのでi桁目が0の時必ず小さくなる。
                dp[i + 1][0][j + 1] += dp[i][0][j];
            }
        }
    }

    ll ans = dp[n][1][K] + dp[n][0][K];
    cout << ans << endl;
}