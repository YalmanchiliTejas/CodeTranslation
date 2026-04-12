#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    int N;
    cin >> N;
    vector<int> q(N);
    vector<vector<long>> dp(N + 1, vector<long>(N + 1));
    for (int i = 0; i < N; i++) {
        cin >> q[i];
//        dp[i][i] = q[i];
    }
    vector<long> S(N);
    S[0] = q[0];
    for (int i = 1; i < N; i++) {
        S[i] = S[i - 1] + q[i];
    }
    auto sum = [&](int i, int j) -> long {
        if (i > j) return 0;
        return S[j] - (i == 0 ? 0 : S[i - 1]);
    };
    for (int i = N - 1; i >= 0; i--) {
        for (int j = i; j < N; j++) {
            dp[i][j] = max(q[i] + sum(i + 1, j) - dp[i + 1][j],
                           q[j] + sum(i, j - 1) - (j == 0 ? 0 : dp[i][j - 1]));
        }
    }
    cout << 2 * dp[0][N - 1] - sum(0, N - 1) << endl;
    return 0;
}
