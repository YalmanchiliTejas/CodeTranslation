#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,i,j;
    cin>>n;
    ll a[n],pre[n+1]={0};
    pre[0]=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        pre[i+1]=pre[i]+a[i];
    }
    /*for(i=0;i<=n;i++)
    {
        cout<<pre[i]<<" ";
    }
    cout<<endl;*/
    ll dp[n+1][n+1],dp1[n+1][n+1];
    memset(dp,0,sizeof(dp));
    memset(dp1,0,sizeof(dp1));

    for(ll k=1;k<=n;k++)
    {
        for(i=1,j=k;i<=n && j<=n;i++,j++)
        {
            if(i==j)
            {
                dp[i][j]=a[i-1];
                dp1[i][j]=0;
            }
            else
            {
                dp[i][j]=max(a[i-1]+dp1[i+1][j],a[j-1]+dp1[i][j-1]);
                dp1[i][j]=pre[j]-dp[i][j]-pre[i-1];
            }
        }
    }
    cout<<dp[1][n]-dp1[1][n]<<endl;
}