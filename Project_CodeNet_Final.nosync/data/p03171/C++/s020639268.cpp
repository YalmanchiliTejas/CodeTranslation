#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    vector< int > a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector< vector< ll > > dp(3000, vector< ll > (3000));
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            if (l == r) dp[l][r] = (ll) a[l];
            else dp[l][r] = max((ll) a[l] - dp[l + 1][r], (ll) a[r] - dp[l][r - 1]);
        }
    }
    cout << dp[0][n - 1] << "\n";
}