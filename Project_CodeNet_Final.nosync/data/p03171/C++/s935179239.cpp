#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
ll n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[i][i] = a[i];
    }
    // dp[i+1][j], dp[i][j-1]
    for (int i = n-2; i >= 0; --i) {
        for (int j = i+1; j < n; ++j) {
            dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
        }
    }
    cout << dp[0][n-1];
  return 0;
}