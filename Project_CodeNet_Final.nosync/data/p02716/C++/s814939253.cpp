#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define MIN -1000000000000000

int main()
{
	int n;cin>>n;
	vector<int> a(n);
	int i,j,k;
	rep(i,n) cin>>a[i];
	vector<vector<ll>> dp(n+1,vector<ll>(3,MIN));
	rep(i,3) dp[0][i]=0;
	rep(j,3)
	{
		for(i=j+1;i<=n;i++)
		{
			if(i==j+1) dp[i][j]=a[i-1];
			else if((i-j-1)%2==0)
			{
				rep(k,j+1)
				{
					dp[i][j]=max(dp[i][j],dp[i-(2+j-k)][k]);
				}
				dp[i][j]+=a[i-1];
			}
			else dp[i][j]=dp[i-1][j];
		}
	}
	dp[n][0]=dp[n-1][0];
	ll ans=MIN;
	rep(i,2+n%2)ans=max(ans,dp[n][i]);
	cout<<ans<<endl;
}
