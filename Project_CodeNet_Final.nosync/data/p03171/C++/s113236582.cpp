//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


long long  dp[3005][3005];

void solve() {
    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    for (int i = 0; i <= N; i++) dp[i][i] = 0;

    for (int len = 1; len <= N; len++) {
        for (int l = 0; l + len <= N ; l++) {
            int r = l + len;

            if ((N - len) % 2 == 0) {
                dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r-1]);
            }
            else {
                dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r-1]);
            }
        }
    }

    cout << dp[0][N] << endl;
}


int main() {
    solve();
    return 0;
}