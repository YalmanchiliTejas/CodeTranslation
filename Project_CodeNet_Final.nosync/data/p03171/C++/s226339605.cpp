#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    int n;
    cin>>n;
    ll a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    ll dp[n+1][n+1][2];
    for(int i=0; i<=n; i++) dp[i][0][0] = dp[i][0][1] = 0;
    for(int l=1; l<=n; l++) {
        for(int i=0; i+l<=n; i++) {
            dp[i][l][0] = min(dp[i+1][l-1][1] - a[i], dp[i][l-1][1] - a[i+l-1]);
            dp[i][l][1] = max(dp[i+1][l-1][0] + a[i], dp[i][l-1][0] + a[i+l-1]);
        }
    }
    cout<< dp[0][n][1] <<endl;
    return 0;
}
