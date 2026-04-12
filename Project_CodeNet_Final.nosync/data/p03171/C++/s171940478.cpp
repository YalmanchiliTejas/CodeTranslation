#include<bits/stdc++.h>
#define debug(x) cout<<#x<<"::"<<x<<endl;
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin>>n;
	vector<ll> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	vector<vector<ll>>dp(n,vector<ll>(n,0));
	for(int i=0;i<n;i++)
	{
		dp[i][i]=v[i];
	}
	for(int len=2;len<=n;len++)
	{
		for(int i=0;i<=n-len;i++)
		{
			dp[i][i+len-1]=max(v[i+len-1]-dp[i][i+len-2],v[i]-dp[i+1][i+len-1]);
		}
	}
	cout<<dp[0][n-1]<<'\n';
}

int main()
{
	int t;
	t=1;
	while(t--)
		solve();
	return 0;
}
