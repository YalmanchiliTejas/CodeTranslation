#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string N;
    int K;
    cin >> N >> K;
    
    long long dp[200][2][200];
    rep(i, 200) rep(j, 2) rep(k, 200) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    rep(i, N.size()) {
        rep(j, 2) {
            rep(k, 200) {
                rep(x, j ? 10 : N[i] - '0' + 1) {
                    dp[i + 1][j || x < N[i] - '0'][k + (x != 0)] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[N.size()][0][K] + dp[N.size()][1][K] << endl;
    return 0;
}
