#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;

vector<int> vec;
int dp[3000][3000];

int solve(int i, int j)
{
if(i==j)
{
	return vec[i];
}
if(dp[i][j]!=-1)
	return dp[i][j];
int ans=max(vec[i]-solve(i+1,j),vec[j]-solve(i,j-1));	
return dp[i][j]=ans;	
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	vec.resize(n);
	for(int i=0; i<n; i++)
	{
		cin>>vec[i];
	}
	for(int i=0; i<3000; i++)
	{
		for(int j=0; j<3000; j++)
		{
			dp[i][j]=-1;
		}
	}
	cout<<solve(0,n-1);
	return 0;
}
