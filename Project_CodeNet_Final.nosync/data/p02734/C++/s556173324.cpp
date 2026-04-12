#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, S;
    cin >> N >> S;
    vector<int64_t> A(N);
    for (int64_t& a : A) {
        cin >> a;
    }

    constexpr int64_t MOD = 998244353;

    //dp[i][j][k] := i番目まで見て、選んだ要素の和がjで、決めた感じがkのとき
    vector<vector<vector<int64_t>>> dp(N + 1, vector<vector<int64_t>>(S + 1, vector<int64_t>(3, 0)));
    dp[0][0][0] = 1;

    for (int64_t i = 0; i < N; i++) {
        for (int64_t j = 0; j <= S; j++) {
            //A[i]を選ぶ
            if (j + A[i] <= S) {
                //Lを決める
                (dp[i + 1][j + A[i]][1] += dp[i][j][0] + dp[i][j][1]) %= MOD;
                //LもRも決める
                (dp[i + 1][j + A[i]][2] += dp[i][j][0] + dp[i][j][1]) %= MOD;
            }

            //A[i]を選ばない
            //Lを決めない
            (dp[i + 1][j][0] += dp[i][j][0]) %= MOD;
            //Lを決める
            (dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1]) %= MOD;
            //LもRも決める
            (dp[i + 1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) %= MOD;
        }
    }

    cout << dp[N][S][2] << endl;
}