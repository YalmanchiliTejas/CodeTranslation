#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	int n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
    
    ll dp[n][n];
    memset(dp,0LL,sizeof dp);
    
    for(int i=0;i<n;i++)
    {
    dp[i][i]=a[i];
    if(i!=n-1)
    dp[i][i+1]=abs(a[i]-a[i+1]);
    }

    for(int gap=3;gap<=n;gap++)
    {
    for(int l=0;l<=n-gap;l++)
    {
    int r=l+gap-1;
    dp[l][r]=max(a[l]+min(dp[l+2][r]-a[l+1],dp[l+1][r-1]-a[r]),
    	         a[r]+min(dp[l+1][r-1]-a[l],dp[l][r-2]-a[r-1]));
    }
    }


    cout<<dp[0][n-1];
	return 0;

}