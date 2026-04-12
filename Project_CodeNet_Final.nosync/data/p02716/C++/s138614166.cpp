#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for (int64_t i = 0; i < N; i++) {
        cin >> A[i];
    }

    constexpr int64_t STATE_NUM = 3;

    //また、直前で選んだかどうかで更に2倍の状態
    //dp[i][j][k] := iまでで、選んだ数がj = MIN or MAXであり、k = (直前で選んだ)場合の最大値
    vector<vector<vector<int64_t>>> dp(N + 1, vector<vector<int64_t>>(STATE_NUM, vector<int64_t>(2, LLONG_MIN / 2)));
    dp[0][0][0] = 0;

    for (int64_t i = 0; i < N; i++) {
        //選んでいる数として可能な最小値、最大値を計算
        const int64_t curr_min_num = max(N / 2 - (N - i + 1) / 2, (int64_t)0);
        const int64_t next_min_num = N / 2 - (N - i) / 2;

        //状態がSTATE_NUM×2通り
        for (int64_t j = 0; j < STATE_NUM; j++) {
            for (int64_t k : { 0, 1 }) {
                //遷移が2通り
                for (int64_t add : { 0, 1 }) {
                    if (k == 1 && add == 1) {
                        //連続して選ぶのは不可
                        continue;
                    }
                    const int64_t num = curr_min_num + j + add;
                    const int64_t diff = num - next_min_num;

                    if (0 <= diff && diff < STATE_NUM) {
                        dp[i + 1][diff][add] = max(dp[i + 1][diff][add], dp[i][j][k] + A[i] * add);
                    }
                }
            }
        }
    }

    cout << max({ dp[N][0][0], dp[N][0][1] }) << endl;
}