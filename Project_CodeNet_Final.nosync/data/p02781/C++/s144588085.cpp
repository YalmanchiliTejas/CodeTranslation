#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int ctoi(char c) { return int(c - '0'); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string str;
    int k;
    cin >> str >> k;

    int n = str.size();

    // dp[i][j][0]: 頭からi桁目まで決めて，0でない桁がj個あり，strより小さいことが確定していない個数．
    // dp[i][j][1]: 頭からi桁目まで決めて，0でない桁がj個あり，strより小さいことが確定している個数．
    vector<vector<vll>> dp(n + 1, vector<vll>(k + 2, vll(2, 0)));
    dp[0][0][0] = 1;

    rep(i, 0, n) {
        rep(j, 0, k + 1) {
            if (str[i] == '0') {
                dp[i + 1][j][0] += dp[i][j][0];
                dp[i + 1][j][1] += dp[i][j][1];
                dp[i + 1][j + 1][1] += 9 * dp[i][j][1];
            } else {
                dp[i + 1][j][1] += dp[i][j][1];
                dp[i + 1][j][1] += dp[i][j][0];
                dp[i + 1][j + 1][0] += dp[i][j][0];
                dp[i + 1][j + 1][1] += 9 * dp[i][j][1];
                dp[i + 1][j + 1][1] += (ctoi(str[i]) - 1) * dp[i][j][0];
            }
        }
    }

    cout << dp[n][k][0] + dp[n][k][1] << endl;

    return 0;
}