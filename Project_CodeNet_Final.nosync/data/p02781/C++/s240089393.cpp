#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (a); i < n; i++)
#define print(x) cout << x << endl;
using namespace std;
typedef long long ll;

string N; int K;
ll dp[101][2][5];
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> N >> K;

    int n = N.length();

    dp[0][0][0] = 1;
    rep(dgt, 0, n) rep(isless, 0, 2) rep(k, 0, K + 1) {
        int c = N[dgt] - '0';
        rep(nxt, 0, 10) {
            if (c < nxt && isless == 0) continue;

            int dgt2 = dgt + 1;
            int isless2 = isless;
            if (nxt < c) isless2 = 1;
            int k2 = k;
            if (nxt != 0) k2++;

            dp[dgt2][isless2][k2] += dp[dgt][isless][k];
        }
    }
    ll ans = dp[n][0][K] + dp[n][1][K];
    cout << ans << endl;
    return 0;
}