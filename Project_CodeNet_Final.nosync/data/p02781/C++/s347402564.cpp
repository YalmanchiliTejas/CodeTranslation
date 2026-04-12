#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dp[105][4][2];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int k;
    cin >> k;
    dp[0][0][0] = 1;
    rep(i,n) rep(j,k+1) rep(l,2) {
        int a = s[i] - '0';
        rep(m, 10) {
            int ni = i+1, nj = j, nl = l;
            if (m != 0) nj++;
            if (nj > k) continue;
            if (l == 0) {
                if (m > a) continue;
                if (m < a) nl = 1;
            }
            dp[ni][nj][nl] += dp[i][j][l];
        }
    }
    int ans = dp[n][k][0] + dp[n][k][1];
    cout << ans << endl;
    return 0;
}