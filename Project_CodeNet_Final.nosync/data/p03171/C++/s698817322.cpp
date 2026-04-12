#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 3012;
ll n,a[MN],dp[MN][MN];
int main (void) {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n-1; i >= 0; i--) {
        for (int j = i; j < n; j++)
            dp[i][j] = (i == j) ? a[i] : max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
    }
    cout << dp[0][n-1] << '\n';
    return 0;
}

