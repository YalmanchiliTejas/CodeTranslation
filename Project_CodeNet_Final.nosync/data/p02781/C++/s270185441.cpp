#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {

    string S;
    int N, K;
    cin >> S >> K;
    N = S.size();

    ll dp[101][4][2] = {0};
    dp[0][0][0] = 1;

    rep(i, N) rep(j, 4) rep(k, 2) {
        int now = S[i] - '0';
        rep(d, 10) {
            int ni = i + 1, nj = j, nk = k;
            if (d != 0)
                nj++;
            if (nj > K)
                continue;
            if (k == 0) {
                if (d > now)
                    continue;
                if (d < now)
                    nk = 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }

    cout << dp[N][K][0] + dp[N][K][1] << endl;

    return 0;
}