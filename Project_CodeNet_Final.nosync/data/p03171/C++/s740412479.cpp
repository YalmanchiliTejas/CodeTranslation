#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int lli;
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    lli n;
    cin>>n;
    lli i,j,a[n],dp[n+1][n+1];
    memset(dp,0LL,sizeof(dp));
    
    for(i=0;i<n;i++) cin>>a[i];
    
    for(i=n-1;i>=0;i--)
        for(j=i+1;j<=n;j++)
            dp[i][j]=max(a[i]-dp[i+1][j], a[j-1]-dp[i][j-1]);
    
    cout<<dp[0][n]<<endl;
    return 0;
}