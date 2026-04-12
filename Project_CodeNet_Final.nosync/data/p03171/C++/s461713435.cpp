#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main()
{
    int n;
    cin>>n;
    int a[n+1];
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
    }

    int dp[n+1][n+1]={};
    for (int i = n; i >=1 ; --i) {
        dp[i][i]=a[i];

        for (int j = i+1; j <=n ; ++j) {
            dp[j][i]=max(a[i]-dp[j][i+1],a[j]-dp[j-1][i]);
        }
    }

    cout<<dp[n][1];
}