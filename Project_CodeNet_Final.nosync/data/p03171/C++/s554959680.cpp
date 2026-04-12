#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<long long> A(n+1);
	for(int i=0;i<n;i++) cin>>A[i+1];
	vector<vector<long long>> dp(n+1,vector<long long>(n+1,-1e18-5));
	for(int i=1;i<=n;i++) dp[i][i]=A[i];
	for(int j=1;j<=n;j++)
	{
		for(int i=j;i>1;i--)
		{
			dp[i-1][j]=max({dp[i-1][j],A[i-1]-dp[i][j],A[j]-dp[i-1][j-1]});
		}
	}
	for(int i=n;i>0;i--)
	{
		for(int j=i;j<n;j++)
		{
			dp[i][j+1]=max({A[i]-dp[i+1][j+1],dp[i][j+1],A[j+1]-dp[i][j]});
		}
	}

	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=n;j++)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	
	cout<<dp[1][n]<<endl;	
}