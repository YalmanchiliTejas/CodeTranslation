#include <bits/stdc++.h>
#define rep(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
using namespace std;
using ll = int64_t;
const int MOD = 1000000007; // 10^9+7

int main() {
    string N;
    cin >> N;
    int K;
    cin >> K;

    vector<vector<vector<int>>> dp(N.size(), vector<vector<int>>(2, vector<int>(K+1)));

    int D = N[0] - '0';
    // (0 0 0), (0 1 0), ..., (0 0 K), (0 1 K) <- 2*(K+1) 個の初期条件
    dp[0][0][0] = 0;        // 存在しない
    dp[0][1][0] = 1;        // 0----- のとき
    dp[0][0][1] = 1;        // D----- のとき
    dp[0][1][1] = D - 1;    // A----- (A=1...D-1)のとき
    // これ以降は「０桁目まで決めた時、０でない数字がi(i>1)個ある」という条件なので、存在しない

    for (int i = 1; i < N.size(); i++)
    {
        D = N[i] - '0';
        for (int less = 0; less < 2; less++)
        {
            for (int d = 0; d < (less ? 10 : D + 1); d++)
            {
                for (int k = 0; k < K+1; k++)
                {
                    if (k == K && d != 0) continue;
                    dp[i][((less || d < D) ? 1 : 0)][(d ? k+1 : k)] += dp[i-1][less][k];
                }
            }
        }
    }

    cout << dp[N.size() - 1][0][K] + dp[N.size() - 1][1][K] << endl;
}
