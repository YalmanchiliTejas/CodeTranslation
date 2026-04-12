#include <bits/stdc++.h>
using namespace std;

constexpr long long INF = 2e18;

int main() {
    int N; cin >> N;
    vector<long long> A(N); for (auto &x : A) cin >> x;
    long long sum = 0;
    for (int i = 0; i < N; i++) sum += A[i];
    if (N % 2 == 0) {
        vector<vector<long long>> memo(2, vector<long long>(N, -INF));
        memo[0][0] = A[0];
        for (int i = 2; i < N; i += 2) memo[0][i] = A[i] + memo[0][i-2];
        memo[1][1] = A[1]; memo[1][2] = A[2];
        for (int i = 3; i < N; i++) memo[1][i] = max(memo[0][i-3] + A[i], memo[1][i-2] + A[i]);
        cout << max(memo[0][N-2], memo[1][N-1]) << endl;
    } else {
        vector<vector<long long>> memo(3, vector<long long>(N, -INF));
        memo[0][0] = A[0];
        for (int i = 2; i < N; i += 2) memo[0][i] = A[i] + memo[0][i-2];
        memo[1][1] = A[1]; memo[1][2] = A[2];
        for (int i = 3; i < N; i++) memo[1][i] = max(memo[0][i-3] + A[i], memo[1][i-2] + A[i]);
        memo[2][2] = A[2];
        for (int i = 4; i < N; i++) memo[2][i] = max({memo[0][i-4] + A[i], memo[1][i-3] + A[i], memo[2][i-2] + A[i]});
        cout << max({memo[0][N-3], memo[1][N-2], memo[2][N-1]}) << endl;
    }
}
