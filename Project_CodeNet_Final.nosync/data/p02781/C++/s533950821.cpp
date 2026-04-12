#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dp[102][5][2];
// 前からI桁目までで、0じゃない数字がJ個ある
// N未満が確定して入れば1、Nと同じになりそうなら0

int main() {
    cout << fixed << setprecision(10);
    
    string S; cin >> S;
    int n = S.size();
    int K; cin >> K;
    dp[0][0][0] = 1;
    rep(i, n) rep(j, K+1) rep(k, 2) {
        rep(d, 10) {
            int nx = S[i] - '0';
            int ni = i+1, nj = j, nk = k;
            if (d != 0) {
                nj++;
            }
            if (k == 0) {
                if (d > nx) {
                    continue;
                }
                if (d < nx) {
                    nk = 1;
                }
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    int ans = dp[n][K][0] + dp[n][K][1];

    cout << ans << endl;
    return 0;
}