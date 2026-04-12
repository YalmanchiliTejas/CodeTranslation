#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=3e3+5;

int n;
int a[N];
LL dp[N][N];
LL dfs(int l,int r,bool t)
{
	if(l==r+1) return 0;
	if(dp[l][r]) return dp[l][r];
	if(t) dp[l][r]=min(dfs(l+1,r,0)-a[l],dfs(l,r-1,0)-a[r]);
	else dp[l][r]=max(dfs(l+1,r,1)+a[l],dfs(l,r-1,1)+a[r]);
	return dp[l][r];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	printf("%lld\n",dfs(1,n,0));
	
	return 0;
}