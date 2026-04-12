/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
 #pragma GCC target("avx", "avx2")*/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define int long long
// #define double ld
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void accell() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}
const int N = 300;
int dp[N][10][4][2];

signed main() {
    accell();
    string s;
    cin >> s;
    int tk;
    cin >> tk;
    for (int i = 0; i < (s[0] - '0'); ++i) {
        dp[0][i][i != 0][0] = 1;
    }
    int n = s.size();
    dp[0][s[0] - '0'][(s[0] - '0') != 0][1] += 1;
    for (int i = 1; i < n; ++i) {
        int c = (s[i] - '0');
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                for (int p = 0; p <= 3; ++p) {
                    if (p + (j != 0) <= tk) {
                        dp[i][j][p +(j != 0)][0] += dp[i - 1][k][p][0];
                    }
                }
            }
        }
        for (int j = 0; j < c; ++j) {
            for (int p = 0; p <= 3; ++p) {
                if (p + (j != 0) <= tk)
                    dp[i][j][p + (j != 0)][0] += dp[i - 1][(s[i - 1] - '0')][p][1];
            }
        }
        for (int p = 0; p <= 3; ++p) {
            if (p + (c != 0) <= tk) {
                // cout << dp[i - 1][(int)(s[i - 1] - '0')][p][1] << ' ' << p + (c != 0) << "   ";
                dp[i][c][p + (c != 0)][1] += dp[i - 1][(int)(s[i - 1] - '0')][p][1];
            }
        }
       /* for (int j = 0; j <= 3; ++j) {
            cout << dp[i][c][j][1] << ' ';
        }*/
       //  cout << endl;
    }
    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 2; ++j) {
            ans += dp[n - 1][i][tk][j];
            // cout << dp[n - 1][i][tk][j] << endl;
            // cout << endl;
        }
    }
    cout << ans;
    return 0;
}
