#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

LL n,a[200010],dp[200010][3];

int main()
{
	cin>>n;
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,200005) rep(j,3) dp[i][j]=-1e18;
	if(n%2==0)
	{
		dp[0][0]=a[0];
		dp[1][1]=a[1];
		rep(i,n-1)
		{
			rep(j,2)
			{
				if(dp[i][j]==-1e18) continue;
				if(i+2<n) dp[i+2][j]=max(dp[i+2][j],dp[i][j]+a[i+2]);
				if(i+3<n&&j==0) dp[i+3][j+1]=max(dp[i+3][j+1],dp[i][j]+a[i+3]);
			}
		}
		cout<<max(dp[n-1][1],dp[n-2][0])<<endl;
	}
	else
	{
		dp[0][0]=a[0];
		dp[1][1]=a[1];
		dp[2][2]=a[2];
		rep(i,n)
		{
			rep(j,3)
			{
				if(dp[i][j]==-1e18) continue;
				if(i+2<n) dp[i+2][j]=max(dp[i+2][j],dp[i][j]+a[i+2]);
				if(i+3<n&&j<2) dp[i+3][j+1]=max(dp[i+3][j+1],dp[i][j]+a[i+3]);
				if(i+4<n&&j==0) dp[i+4][j+2]=max(dp[i+4][j+2],dp[i][j]+a[i+4]);
			}
		}
		cout<<max(max(dp[n-1][2],dp[n-2][1]),dp[n-3][0])<<endl;
	}
	return 0;
}