#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int dp[n+5][n+5];
    int a[n+5];
    for(int i=0;i<n;i++)
        cin>>a[i],dp[i][i]=a[i];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j+i<n;j++)
        {
            dp[j][i+j]=max(a[j]-dp[j+1][i+j],a[i+j]-dp[j][i+j-1]);
        }
    }
    cout<<dp[0][n-1];

}
