#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[3001][3001],a[3001],n;
ll f(int i,int j)
{
    if(i>j)
    return 0;
    if(dp[i][j]!=0)return dp[i][j];
    else
    {
        if((j-i)%2==n%2)
            dp[i][j]=max(a[i]+f(i+1,j),a[j]+f(i,j-1));
        else
            dp[i][j]=min(-1*a[i]+f(i+1,j),-1*a[j]+f(i,j-1));
    }
}
int main()
{
    cin>>n;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)cin>>a[i];
    f(0,n-1);
    cout<<-1*dp[0][n-1];
}
