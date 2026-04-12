#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using namespace std;

ll D;
string N;
ll dp[101010][101][2];
ll mod = 1e9 + 7;

ll solve(int i, int md, bool b) {
    if (i >= N.size()) {
        return md == 0;
    }
    ll& ret = dp[i][md][b];

    if (~ret) return ret;
    ret = 0;

    int x = N[i] - '0';
    for (int d=0; d<=(b ? 9 : x); ++d) {
        ret += solve(i+1, (md + (d % D)) % D, (b or d < x));
        ret %= mod;
    }

    return ret;
}

int main() {
    cin >> N >> D;
    //rep(i, 101010) rep(j, 101) rep(k, 2) dp[i][j][k] = -1;
    dp[0][0][0] = 1;
    rep(i, N.size()) rep(j, 101) rep(k, 2) {
        int x = N[i] - '0';
        for (int d=0; d<=(k ? 9 : x); ++d) {
            dp[i+1][(j + (d % D))%D][k or d < x] += dp[i][j][k];
            dp[i+1][(j + (d % D))%D][k or d < x] %= mod;
        }
    }

    cout << ( (dp[N.size()][0][1] % mod) + (dp[N.size()][0][0] % mod) - 1 + mod) % mod << endl;
}
