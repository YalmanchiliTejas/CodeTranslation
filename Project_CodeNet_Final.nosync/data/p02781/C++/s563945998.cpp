#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string N;
    cin>>N;
    int K;
    cin>>K;

    int s = N.size();
    vector<vector<vector<ll>>> dp(s + 1, vector<vector<ll>>(K + 2, vector<ll>(2)));
    dp[0][0][0] = 1;    // ケタ、0以外の回数、=N or !N
    rep(i, s) {
        rep(j, K + 1) {
            if (N[i] == '0') {
                dp[i + 1][j][0] += dp[i][j][0];
                dp[i + 1][j][1] += dp[i][j][1];
                dp[i + 1][j + 1][1] += 9 * dp[i][j][1];
            }
            else {
                dp[i + 1][j + 1][0] += dp[i][j][0];
                dp[i + 1][j][1] += dp[i][j][0];
                dp[i + 1][j + 1][1] += (N[i] - '0' - 1) * dp[i][j][0];
                dp[i + 1][j][1] += dp[i][j][1];
                dp[i + 1][j + 1][1] += 9 * dp[i][j][1];
            }
        }
    }

    cout<<dp[s][K][0] + dp[s][K][1]<<endl;
}