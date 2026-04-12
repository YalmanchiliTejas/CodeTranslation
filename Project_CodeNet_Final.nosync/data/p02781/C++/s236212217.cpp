#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

string N;
int K;
int dp[110][3][5];

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> K;
    int L = N.size();
    dp[0][0][0] = 1;
    rep(i, L) {
        int D = N[i]-'0';
        rep(j, 2) rep(k, K+1) {
            int max_d = j==0 ? D+1:10;
            rep(d, max_d) {
                int nk = k+(d!=0 ? 1:0);
                if (nk>K) continue;
                dp[i+1][j|(d<D)][nk] += dp[i][j][k];
            }
        }
    }
    cout << dp[L][0][K]+dp[L][1][K] << endl;
}