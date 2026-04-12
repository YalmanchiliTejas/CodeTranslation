#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int a[3005],dp[3005][3005];
int dpgame(int l,int r)
{
	if(dp[l][r]!=-1)
	return dp[l][r];
	if(l==r)
	return a[l];
	dp[l][r]=max(a[l]-dpgame(l+1,r),a[r]-dpgame(l,r-1));
	return dp[l][r];
}
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	memset(dp,-1,sizeof(dp));
	cout<<dpgame(1,n)<<"\n";
}