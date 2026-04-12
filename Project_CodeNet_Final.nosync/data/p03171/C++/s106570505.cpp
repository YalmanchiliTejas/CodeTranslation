#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n;
long long a[3005];
long long dp[3005][3005];
bool done[3005][3005];
void dfs(int s,int l,int r)
{
	done[l][r]=1;
	if(l==r)
	{
		if(s==1) dp[l][r]=a[l];
		else dp[l][r]=-a[l];
		return;
	}
	int t=!s;
	if(!done[l][r-1]) dfs(t,l,r-1);
	if(!done[l+1][r]) dfs(t,l+1,r);
	if(s==1) dp[l][r]=max(a[l]+dp[l+1][r],a[r]+dp[l][r-1]);
	else dp[l][r]=min(-a[l]+dp[l+1][r],-a[r]+dp[l][r-1]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,1,n);
	printf("%lld",dp[1][n]);
	return 0;
}

