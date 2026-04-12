#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

#define rep(i, a) for (int i = 0; i < (int)(a); ++i)

constexpr i64 MOD = 1e9 + 7;

i64 solve(string s, int d) {
    i64 dp[(int)s.size()+1][2][d];
    rep(i, s.size()+1)rep(j, 2)rep(k, d)dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    rep(i, s.size()) rep(j, 2) rep(k, d) {
        int lim = j ? 9 : s[i] - '0';
        rep(l, lim + 1) {
            dp[i + 1][j || l < lim][(k+l)%d] += dp[i][j][k];
            dp[i + 1][j || l < lim][(k+l)%d] %= MOD;
        }
    }
    i64 ans = 0;
    rep(j, 2){
        ans += dp[s.size()][j][0];
        ans %= MOD;
    }
    ans--;  // exclude zero
    if(ans < 0)ans += MOD;
    return ans;
}

int main(){
    string s;
    cin >> s;
    int d;
    cin >> d;

    cout << solve(s, d) << endl;

    return 0;
}
