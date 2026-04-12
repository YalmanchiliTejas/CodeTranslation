#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
vector<vector<long long>> dp(3000,vector<long long>(3000,INF));
int n;
vector<long long> a(3000);
long long res(int l, int r)
{
	if(l>r)
		return 0;
	if(dp[l][r]!=INF)
		return dp[l][r];
	int length = r - l + 1;
	if(length%2 == n%2)
	{
		return (dp[l][r] = max(res(l+1,r)+a[l],res(l,r-1)+a[r]));
	}
	else
	{
		return (dp[l][r] = min(res(l+1,r)-a[l],res(l,r-1)-a[r]));
	}
}
int main()
{	
	cin>>n;
	for(int i = 0;i<n;i++)
		cin>>a[i];
	long long ans = res(0,n-1);
	cout<<ans<<'\n';
}
