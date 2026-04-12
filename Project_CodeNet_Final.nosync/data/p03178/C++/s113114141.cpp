#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int dp[10010][10][110][2];

int mod = 1e9 + 7;

void clear() {
    for (int a = 0; a < 10010; a++) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 110; c++) {
                for (int z = 0; z < 2; z++) {
                    dp[a][b][c][z] = 0;
                }
            }
        }
    }
}

inline int md(int a, const int &mod) {
    while (a >= mod) {
        a -= mod;
    }
    return a;
}

ll solve(string &k, int m) {
    clear();
    for (int i = 1; i < 10; i++) {
        if (k[0] - '0' > i) {
            dp[0][i][i % m][0] = 1;
        } else if (k[0] - '0' == i) {
            dp[0][i][i % m][1] = 1;
        }
    }
    for (int i = 1; i < k.size(); i++) {
        for (int d = 0; d < 10; d++) {
            for (int ld = 0; ld < 10; ld++) {
                for (int ost = 0; ost < m; ost++) {
                    if (k[i] - '0' > d) {
                        dp[i][d][md(ost + d, m)][0] = md(dp[i][d][md(ost + d, m)][0] + md(dp[i - 1][ld][ost][0] + dp[i - 1][ld][ost][1], mod), mod);
                    } else if (k[i] - '0' == d) {
                        dp[i][d][md(ost + d, m)][0] = md(dp[i][d][md(ost + d, m)][0] + dp[i - 1][ld][ost][0], mod);
                        dp[i][d][md(ost + d, m)][1] = md(dp[i][d][md(ost + d, m)][1] + dp[i - 1][ld][ost][1], mod);
                    } else {
                        dp[i][d][md(ost + d, m)][0] = md(dp[i][d][md(ost + d, m)][0] + dp[i - 1][ld][ost][0], mod);
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        ans = (ans + dp[k.size() - 1][i][0][0] + dp[k.size() - 1][i][0][1]) % mod;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    cout.precision(20); cout << fixed;
    string k;
    int d;
    cin >> k >> d;
    ll ans = solve(k, d);
    if (k.size() != 1) {
        string s = "";
        for (int i = 1; i < k.size(); i++) {
            s += '9';
        }
        solve(s, d);
        for (int t = 0; t < k.size() - 1; t++) {
            for (int i = 0; i < 10; i++) {
                ans = (ans + dp[t][i][0][0] + dp[t][i][0][1]) % mod;
            }
        }
    }
    cout << ans << endl;
}
