#include<iostream>
#include<algorithm>
using namespace std;
int n;
long dp[3333][3333],a[3333];
bool used[3333][3333];
long dfs(int l,int r)
{
	if(l>r)return 0;
	if(used[l][r])return dp[l][r];
	bool w=n+r-l&1;
	used[l][r]=1;
	long ret;
	if(w)
	{
		ret=max(a[l]+dfs(l+1,r),a[r]+dfs(l,r-1));
	}
	else
	{
		ret=min(-a[l]+dfs(l+1,r),-a[r]+dfs(l,r-1));
	}
	return dp[l][r]=ret;
}
main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<dfs(0,n-1)<<endl;
}