/*
f(l, r) {
    if (l==r) dp[l][r] = a[l]
    dp[l][r] = max(a[l]-dp[l+1][r], a[r]-dp[l][r-1])
}
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3005;
ll dp[N][N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++) cin >> a[i];
    for (int l = n-1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            if (l==r) dp[l][r] = a[l];
            else dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
        }
    }
    cout << dp[0][n-1] << "\n";
    return 0;
}