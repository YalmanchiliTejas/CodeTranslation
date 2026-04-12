#include <iostream>

using namespace std;

void solve()
{
	int n;
	cin>>n;
	long dp[n][n],arr[n];
	for(int i=0;i<n;i++) {cin>>arr[i];}
	int l,r;
	for(r=0;r<n;r++)
	{
		for(l=r;l>=0;l--)
		{
			if(l==r) dp[l][l]=arr[l];
			else
			    dp[l][r]=max(arr[l]-dp[l+1][r],arr[r]-dp[l][r-1]);
		}
	}
	cout<<dp[0][n-1]<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// int t;
	// cin>>t;
	// while(t--)
		solve();
	return 0;
}
