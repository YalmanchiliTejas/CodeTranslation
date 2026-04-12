#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int>s(N);
    for (int i = 0; i < N; ++i) {
      cin >> s[i];
    }

    ll ans = 0; // A = N-1 のとき, 下限
    // A - B = C の値で全探索
    // C < A, A + C <= N-1 より, C <= N/2 - 1
    ll dp[N-1]; // DP[j]はCをj回やってからAでゴール
    for (int i = 1; i <= N/2 -1; ++i) {
        // ll dp[(N-1)/i]; // DP[j]はCをj回やってからAでゴール
        dp[0] = 0;
        for (int j = 1; j < (N-1)/i; ++j) {
            if((N-1-i*j == i*j) || (N-1-i*j == i*(j-1))) break;
            dp[j] = dp[j-1] + s[N-1-i*j] + s[i*j];
            ans = max(ans, dp[j]);
        }
    }
    cout << ans;
    return 0;
}