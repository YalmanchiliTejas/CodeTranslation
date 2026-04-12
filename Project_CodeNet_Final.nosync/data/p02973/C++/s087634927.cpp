#include <bits/stdc++.h>
using namespace std;
const long long N=100010;
long long n;
long long d[N];
long long ans,dp[N];
const long long INF=99999999999;
struct cmp
{
	bool operator()(int a,int b)
	{
		return a>b;
	}
};
void LIS()
{
	ans=1;
	dp[1]=d[1];
	for(int k=2;k<=n;k++)
		dp[k]=INF;
	for(int k=2;k<=n;k++)
		if(d[k]<=dp[ans])
			dp[++ans]=d[k];
		else
		{
			int wz=upper_bound(dp+1,dp+1+ans,d[k],cmp())-dp;
			dp[wz]=d[k];
		}
	printf("%lld\n",ans);
}
int main()
{
	scanf("%lld",&n);
	for(long long k=1;k<=n;k++)
		scanf("%lld",&d[k]);
	LIS();
	return 0;
}