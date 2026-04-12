#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int dp[105][5][2];

int main() {
    string s;
    int K;
    cin >> s >> K;
    dp[0][0][0] = 1;
    int n=s.length();

    rep(i, n) rep(k, K+1) rep(t, 2) {
        int d=s[i]-'0';
        rep(j, 10) {
            if(t == 0 && j>d) continue;
            if(t == 0 && j==d) {
                dp[i+1][k+(j>0)][0] += dp[i][k][t];
            } else {
                dp[i+1][k+(j>0)][1] += dp[i][k][t];
            }
        }
    }
    cout << dp[n][K][0]+dp[n][K][1] << endl;
    return 0;
}
