#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;

int dp[105][4][2] = {0};

int main() {
    string S;
    int K;
    cin >> S >> K;
    int N = S.size();
    dp[0][0][1] = 1;
    rep(i, N) rep(k, 4) rep(m, 2) {
        int nd = S[i] - '0';

        rep(d, 10) {
            int nk = (d == 0) ? k : k + 1;
            if(nk>3) continue;
            int nm = m;
            if(m==1){
              if(d > nd) continue;
              if(d < nd) nm = 0;
            }
            dp[i + 1][nk][nm] += dp[i][k][m];
        }
    }
    cout << dp[N][K][0] + dp[N][K][1] << endl;
}