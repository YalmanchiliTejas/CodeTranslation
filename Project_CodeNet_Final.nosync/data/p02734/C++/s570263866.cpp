#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
const int mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

ll dp[3030][3030][3];
ll A[3030];

void add(ll& a, ll b) { (a += b) %= mod; }

int main() {
    int N, S; cin >> N >> S;
    rep(i,N) cin >> A[i];
    dp[0][0][0] = 1;
    rep(i,N) {
        rep(j,S+1) {
            add(dp[i+1][j][0], dp[i][j][0]);
            add(dp[i+1][j][1], dp[i][j][0]+dp[i][j][1]);
            add(dp[i+1][j][2], dp[i][j][0]+dp[i][j][1]+dp[i][j][2]);
            if(j+A[i] > S) continue;
            add(dp[i+1][j+A[i]][1], dp[i][j][0]+dp[i][j][1]);
            add(dp[i+1][j+A[i]][2], dp[i][j][0]+dp[i][j][1]);
        }
    }
    cout << dp[N][S][2] << endl;
    return 0;
}
