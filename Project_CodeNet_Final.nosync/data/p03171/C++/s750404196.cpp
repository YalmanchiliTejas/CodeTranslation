#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1e9+5;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    ll arr[n+1];
    ll sum = 0;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    ll dp[n+1][n+1];
    for (int gap = 0; gap<n; ++gap) {
        for (int i=1, j=gap+1; j<=n; ++i, ++j) {
            ll x = ((i + 2) <= j) ? dp[i + 2][j] : 0; 
            ll y = ((i + 1) <= (j - 1)) ? dp[i + 1][j - 1] : 0; 
            ll z = (i <= (j - 2)) ? dp[i][j - 2] : 0;
            dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y,z));
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    ll ans = dp[1][n]-(sum-dp[1][n]);
    cout << ans << endl;
    return 0;
}
