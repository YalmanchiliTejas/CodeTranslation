#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,o;
ll dp[3009][3009],a[3009];
int main()
{
    cin>>n;
    o=n%2;
    int x=1;
    if(n%2==0)x=-1;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)dp[i][i]=a[i]*x;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i%2==o)
            {
                dp[j][j+i]=min(dp[j][j+i-1]-a[j+i],dp[j+1][j+i]-a[j]);
            }
            else dp[j][j+i]=max(dp[j][j+i-1]+a[j+i],dp[j+1][j+i]+a[j]);
        }
    }
    cout<<dp[0][n-1]<<"\n";
   /* for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cout<<dp[i][j]<<" ";cout<<"\n";
    }*/
}
