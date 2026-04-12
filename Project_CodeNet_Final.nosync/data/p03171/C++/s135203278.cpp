#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N; cin >> N;
    vector<int> A(N); for (int& a : A) cin >> a;
    vector<vector<long long>> dp(N+1, vector<long long>(N+1)); // dp[i][j]: score of A[i..j)
    for (int i = 0; i <= N; i++) {
        dp[i][i] = 0;
    }
    for (int n = 1; n <= N; n++) {
        for (int i = 0; i <= N - n; i++) {
            dp[i][i+n] = max(A[i] - dp[i+1][i+n], A[i+n-1] - dp[i][i+n-1]);
        }
    }
    cout << dp[0][N] << endl;
    return 0;
}