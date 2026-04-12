#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long int64;

int64 dp[110][2][4];

int main() {
    string S; cin >> S;
    int K; cin >> K;
    int N = S.size();
    dp[0][0][0] = 1;
    rep(i, N) rep(j, 2) rep(k, 4) {
        int64 pre = dp[i][j][k];
        if(pre == 0) continue;
        int x = j ? 9 : S[i] - '0';
        if(k == K) {
            dp[i + 1][1][k] += pre;
        } else {
        rep(d, x + 1) {
            int nk = d ? k + 1 : k;
            dp[i + 1][j || d < x][nk] += pre;
        }
        }
    }
    int64 ans = dp[N][0][K] + dp[N][1][K];
    cout << ans << '\n';
    return 0;
}

// overflow
// corner cases
