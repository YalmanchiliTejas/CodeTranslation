#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)

ll dp[3030][3030];

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    if(n % 2 == 0){
        rep(i, n) dp[i][i] = -A[i];
        rep(w, n) {
            if (w == 0) continue;
            rep(i, n - w) {
                if(w % 2 == 1) dp[i][i + w] = max(dp[i][i + w - 1] + A[i + w], dp[i + 1][i + w] + A[i]);
                else dp[i][i + w] = min(dp[i][i + w - 1] - A[i + w], dp[i + 1][i + w] - A[i]);
            }
        }
    }
    else {
        rep(i, n) dp[i][i] = A[i];
        rep(w, n) {
            if (w == 0) continue;
            rep(i, n - w) {
                if(w % 2 == 0) dp[i][i + w] = max(dp[i][i + w - 1] + A[i + w], dp[i + 1][i + w] + A[i]);
                else dp[i][i + w] = min(dp[i][i + w - 1] - A[i + w], dp[i + 1][i + w] - A[i]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}