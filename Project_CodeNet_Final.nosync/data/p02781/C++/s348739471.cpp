#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)
#define rrep(i, n) for(int i = ((int)n - 1); i >= 0; --i)

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;
const int Inf = 1e9;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(0);
    string s;
    int x;
    cin >> s >> x;
    int n = s.size();
    int dp[105][4][2] = {0};
    dp[0][0][0] = 1;
    rep (i, n) {
        rep (j, 4) {
            rep (k, 2) {
                int cur = s[i] - '0';
                rep (digit, 10) {
                    int ni, nj, nk;
                    ni = i + 1, nj = j, nk = k;
                    if (digit != 0) nj++;
                    if (nj > x) continue;
                    if (k == 0) {
                        if (digit > cur) continue;
                        if (digit < cur) nk = 1;
                    }
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[n][x][0] + dp[n][x][1] << endl;

    return 0;
}

