#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N; cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector< vector<int64_t> > dp(N, vector<int64_t>(N, 0));
    for (int i = 0; i < N; ++i)
        dp[i][i] = A[i];

    for (int L = 1; L < N; ++L)
        for (int i = 0; i + L < N; ++i)
            dp[i][i + L] = max(A[i] - dp[i + 1][i + L], A[i + L] - dp[i][i + L - 1]);

    cout << dp[0][N - 1] << "\n";
}
