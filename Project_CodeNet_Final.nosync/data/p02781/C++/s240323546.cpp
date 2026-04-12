#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF             2e9
#define INF_LL          1LL<<60
#define ll              long long
#define Ceil(x, n)      (((((x))+((n)-1))/n))
#define CeilN(x, n)     (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)    ((x)-(x)%(n))
#define ALL(x)          (x).begin(),(x).end()
typedef pair<ll, ll>    P;

int main() {
    string s;
    int k;
    cin >> s >> k;
    int keta = s.size();
    vector<int> n_keta(keta);
    REP(i, keta) n_keta[i] = (int)(s[i] - '0');

    ll dp[keta][4][2];
    REP(i, keta) REP(j, 4) REP(k, 2) dp[i][j][k] = 0;
    dp[0][1][0] = 1;
    dp[0][1][1] = (int)n_keta[0] - 1;
    dp[0][0][1] = 1;

    REP(i, keta-1) {
        /* ぴったりからぴったり */
        if(n_keta[i+1] == 0) {
            REP(j, 4) dp[i+1][j][0] += dp[i][j][0];
        } else {
            REP(j, 3) dp[i+1][j+1][0] += dp[i][j][0];
        }

        /* ぴったりからより小さい */
        if(n_keta[i+1] != 0) {
            REP(j, 3) dp[i+1][j+1][1] += dp[i][j][0] * (n_keta[i+1] - 1);
            REP(j, 4) dp[i+1][j][1] += dp[i][j][0];
        }

        /* より小さいからより小さい */
        REP(j, 3) dp[i+1][j+1][1] += dp[i][j][1] * 9;
        REP(j, 4) dp[i+1][j][1] += dp[i][j][1];
    }

    cout << dp[keta-1][k][0] + dp[keta-1][k][1] << endl;

    return 0;
}