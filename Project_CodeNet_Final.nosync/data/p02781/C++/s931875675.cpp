#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

#define rep(i, a) for (int i = 0; i < (int)(a); ++i)

i64 solve(string s, int K) {
    i64 dp[102][2][5][2] = {1};
    rep(i, s.size()) rep(j, 2) rep(k, 4) rep(l, 2) {
        int lim = j ? 9 : s[i] - '0';
        rep(d, lim + 1) {
            dp[i+1][j || d < lim][k + (d != 0)][l || d != 0] += dp[i][j][k][l];
        }
    }
    i64 ans = 0;
    rep(j, 2){
        //cerr << dp[s.size()][j][K][1] << endl;
        ans += dp[s.size()][j][K][1];
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << solve(s, k) << endl;

    return 0;
}