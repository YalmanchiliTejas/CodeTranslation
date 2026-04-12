
#include<bits/stdc++.h>
#define size 3000
#define ll long long
using namespace std;
ll dp[size+1][size+1];
ll a[size+1];

ll solve(int i,int j,int n)
{
    if(i>n || j<=0)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];

    dp[i][j]=max(a[i]-solve(i+1,j,n),a[j]-solve(i,j-1,n));
    
    return dp[i][j];
}

int main()
{
	int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        dp[i][i]=a[i];
    }
    cout<<solve(1,n,n);
	return 0;
}
