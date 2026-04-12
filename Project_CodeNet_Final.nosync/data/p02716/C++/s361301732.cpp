#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處
const int MAXN = 2e5 + 2;
LL A[MAXN];
LL dp[MAXN][2];  // /2, /2+1

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[N-1][0] = 0;
    dp[N-1][1] = A[N-1];
    for (int i = N-2; i >= 0; --i) {
        int left = N-1-i+1;
        if (left % 2) {
            dp[i][0] = max(A[i] + dp[i+2][0], dp[i+1][0]);
            dp[i][1] = A[i] + dp[i+2][1];
        } else {
            dp[i][0] = max(A[i] + dp[i+2][0], dp[i+1][1]);
            dp[i][1] = 0;
        }
    }
    // for (int i = 0; i < N; ++i) {
    //     cout << dp[i][0] << ' ' << dp[i][1] << endl;
    // }
    cout << dp[0][0] << endl;
    return 0;
}
