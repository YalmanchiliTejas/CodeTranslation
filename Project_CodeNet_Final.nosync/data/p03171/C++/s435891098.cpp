#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e+6;
const int mod = 1000000007;
int v[3005];
int dp[3005][3005];
int helper(int s,int e)
{
	if(s==e)
	{
		return v[s];
	}

	if(dp[s][e]!=INT_MIN)
	{
		return dp[s][e];
	}

	return dp[s][e] = max(v[s] - helper(s+1,e),v[e]-helper(s,e-1));
}
int32_t main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(int i=0;i<3005;i++)
	{
		for(int j = 0;j<3005;j++)
		{
			dp[i][j] = INT_MIN;
		}
	}

	cout<<helper(0,n-1)<<endl;

	return 0;
}