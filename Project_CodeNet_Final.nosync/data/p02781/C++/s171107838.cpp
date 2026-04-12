#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {
    
    string N;
    int K;
    cin >> N >> K;

    long long dp[2][N.length()][K + 1];
    rep(i,2) rep(j,N.length()) rep(k,K+1) dp[i][j][k] = 0;
    dp[0][0][1] = 1;
    dp[1][0][0] = 1;
    dp[1][0][1] = N[0] - '1';

    for (int j = 1; j < N.length(); j++) {
        for (int k = 0; k <= K; k++) {
            if (N[j] == '0') {
                dp[0][j][k] = dp[0][j - 1][k];
            } else {
                dp[0][j][k] = (k == 0 ? 0 : dp[0][j - 1][k - 1]);
                dp[1][j][k] = (dp[1][j][k] + dp[0][j - 1][k] + (k > 0 ? dp[0][j - 1][k - 1] * (N[j] - '1') % MOD : 0)) % MOD;
            }
            dp[1][j][k] = (dp[1][j][k] + (k > 0 ? dp[1][j - 1][k - 1] * 9 % MOD : 0) + dp[1][j - 1][k]) % MOD;
        }
    }

    cout << (dp[0][N.length() - 1][K] + dp[1][N.length() - 1][K]) % MOD << endl;

    return 0;
}