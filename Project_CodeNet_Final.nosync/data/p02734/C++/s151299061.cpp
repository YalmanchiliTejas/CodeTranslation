#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int mo=998244353;
const int maxn=3010;
int n,s,a[maxn];
long long dp[maxn][maxn],ans;
int main()
{
	scanf("%d%d",&n,&s);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<s;j++) dp[i][j]=dp[i-1][j];
		dp[i][a[i]]=(dp[i][a[i]]+i)%mo;
		for (int j=1;j<=s-a[i];j++) dp[i][j+a[i]]=(dp[i][j+a[i]]+dp[i-1][j])%mo;
		if (dp[i][s]) ans=(ans+dp[i][s]*(n-i+1)%mo)%mo;
	}
	printf("%lld\n",ans);
return 0;
}