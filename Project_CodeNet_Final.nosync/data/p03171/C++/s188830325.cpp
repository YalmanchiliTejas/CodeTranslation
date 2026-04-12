#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    ll dp[n][n+1];
    for(int i = 0; i < n; ++i)
        dp[i][1] = a[i];
    for(int l = 2; l <= n; ++l) {
        for(int i = 0; i+l-1 < n; ++i) {
            dp[i][l] = max(a[i] - dp[i+1][l-1],
                            a[i+l-1] - dp[i][l-1]);
        }
    }
    cout << dp[0][n];
    return 0;
}
