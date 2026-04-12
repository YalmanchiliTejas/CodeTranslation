#include<cstdio>
#include<algorithm>
using namespace std;
long long n,a[3005],dp[3005][3005];
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		dp[i][i]=a[i];
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
		}
	}
	printf("%lld\n",dp[1][n]);
}