#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main()
{  
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin>>n;
    ll a[n],dp[n][n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(i == j)dp[i][j]=a[i];
            else if(i+1 == j)dp[i][j]=abs(a[i]-a[i+1]);
           // else dp[i][j]=max(a[i]+min(dp[i+2][j]-a[i+1],dp[i+1][j-1]-a[j]),a[j]+min(dp[i][j-2]-a[j-1],dp[i+1][j-1]-a[i]));
            else dp[i][j]= max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1]<<"\n";
    return 0;
}