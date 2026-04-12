#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define rep2(i, m, n) for(int i=(int)m; i<(int)n; i++)
#define ALL(vec) vec.begin(), vec.end()
typedef long long ll;
typedef long double ld;

// 「上の桁から見る」「配るDP」．模範解答を参考にした．

int main(){
    string S;
    int K;
    cin >> S >> K;
    int L = S.size();

    ll dp[1000][4][2];
    rep(i, L+1) rep(j, K+1) rep(k, 2) dp[i][j][k] == 0;
    dp[0][0][0] = 1;

    rep(i, L) rep(j, K+1) rep(k, 2) rep(l, 10){
        int x = S[i] - '0';
        if(k == 0 && l > x) continue;

        int ii, jj, kk;
        ii = i + 1;
        jj = (l == 0) ? j : (j+1);
        kk = (k == 0 && l == x) ? 0 : 1;

        if(jj > K) continue;
        dp[ii][jj][kk] += dp[i][j][k];
    }
    cout << dp[L][K][0] + dp[L][K][1] << endl;
}