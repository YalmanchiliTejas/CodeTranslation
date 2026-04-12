#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

ll dp[10010][110][2] = {1};
ll mod = 1e9 + 7;
string k;
int d;

int norm(int a, int b) {
    int r = a - b;
    while (r < 0)
        r += d;
    return r;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> k >> d;
    int n = k.size();

    rep(i, 0, n) {
        int c = k[i] - '0';
        rep(j, 0, d) {
            rep(l, 0, 10) dp[i + 1][j][1] += dp[i][norm(j, l)][1];
            rep(l, 0, c) dp[i + 1][j][1] += dp[i][norm(j, l)][0];
            dp[i + 1][j][1] %= mod;
            dp[i + 1][j][0] = dp[i][norm(j, c)][0];
        }
    }
    cout << (dp[n][0][0] + dp[n][0][1] + mod - 1) % mod << endl;
    return 0;
}