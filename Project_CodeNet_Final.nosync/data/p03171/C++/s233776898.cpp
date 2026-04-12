#include <bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int vals[N];
    
    for(int i = 0; i < N; ++i) {
        cin >> vals[i];
    }
    long long DP[N][N]; // DP[i][j] = X-Y if vals[i..j] remains.
    for(int i = 0; i < N; ++i) {
        DP[i][i] = vals[i];
    }
    /* Transitions
    depending on i + j % 2
    if 1st guys turn
        DP[i][j] = max(DP[i - 1][j] + X[i], DP[i][j - 1] + X[j])
    else
        DP[i][j] = min(DP[i - 1][j] + X[i], DP[i][j - 1] + X[j])
    */ 
    for(int L = N - 1; L >= 0; --L) {
        for(int R = L + 1; R < N; ++R) {
            DP[L][R] = max(vals[L] - DP[L + 1][R], vals[R] - DP[L][R - 1]);
        }
    }
    cout << DP[0][N - 1] << endl;
}