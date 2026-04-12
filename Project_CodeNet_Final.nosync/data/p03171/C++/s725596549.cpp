#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=3005;
long long a[N],sum[N],dp[N][N];
void dfs(int l,int r)
{
	if(r-l==1)
	{
		dp[l][r]=max(a[l],a[r]);
		return;
	}
	if(!dp[l+1][r])
		dfs(l+1,r);
	if(!dp[l][r-1])
		dfs(l,r-1);
	dp[l][r]=max(a[l]+sum[r]-sum[l]-dp[l+1][r],a[r]+sum[r-1]-sum[l-1]-dp[l][r-1]);
}
main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		dp[i][i]=a[i];
		sum[i]=sum[i-1]+a[i];	
	} 
	if(n==1)
	{
		printf("%lld\n",a[1]);
		return 0;
	}
	dfs(1,n);
	int sum1=dp[1][n],sum2=sum[n]-dp[1][n];
	printf("%lld\n",sum1-sum2);
	return 0;
}
