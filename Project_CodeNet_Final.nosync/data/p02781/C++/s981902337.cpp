#include <bits/stdc++.h>
using namespace std;
using Int = long long;
Int dp[3][100][4]; // any,eql,small ndigit k
int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    string N; cin >> N;
    int sz = N.size();
    int K; cin >> K;
    for (int i = 0; i < sz; i++) {
        for (int k = 0; k < 4; k++) {
            for (int t = 0; t <= 9; t++) {
                if (k + (t != 0) >= 4) continue;
                if (i == 0 && t == 0) continue;
                dp[0][i][k + (t != 0)] += (i > 0 ? dp[0][i - 1][k] : k==0);
                if (t == N[i] - '0') {
                    dp[1][i][k + (t != 0)] += (i > 0 ? dp[1][i - 1][k] : k==0);
                }
                if (t < N[i] - '0') {
                    dp[2][i][k + (t != 0)] += (i > 0 ? dp[1][i - 1][k] : k==0);
                }
                dp[2][i][k + (t != 0)] += (i > 0 ? dp[2][i - 1][k] : 0);
            }
        }
    }
    Int ans = 0;
    for (int i = 0; i < sz - 1; i++) {
        ans += dp[0][i][K];
    }
    ans += dp[1][sz-1][K] + dp[2][sz-1][K];
    cout << ans << endl;
    return 0;
}
