#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
	
	int n;
	cin>>n;
	vector<int>a;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}

	vector<vector<ll>>dp(n,vector<ll>(n,0));
	for(int i=0;i<n;i++)
		dp[i][i]=a[i];
	for(int i=1;i<n;i++)
		dp[i-1][i]=abs(dp[i][i]-dp[i-1][i-1]);

	for(int g=2;g<n;g++)
	{
		for(int i=0,j=g;j<n;i++,j++)
		{
			dp[i][j]=max(dp[j][j]-dp[i][j-1],dp[i][i]-dp[i+1][j]);
		}
	}
	cout<<dp[0][n-1];
}