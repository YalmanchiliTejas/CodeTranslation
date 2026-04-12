#include <bits/stdc++.h>
#define  pb push_back
#define nl "\n"
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
#define int long long int
using namespace std;
int dp[3234][3234];
int s[3324];
signed main()
{
	fastScan;
	int n,sum=0;cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		sum+=s[i];
	}
	for(int l=1;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			int x=0,y=0,z=0;
			if(i+2<=j)
				x=dp[i+2][j];
			if(i+1<=j-1)
				y=dp[i+1][j-1];
			if(i<=j-2)
				z=dp[i][j-2];
			dp[i][j]=max(min(x,y)+s[i],min(y,z)+s[j]);
		}
	}
	cout<<2*dp[0][n-1]-sum<<nl;
}
