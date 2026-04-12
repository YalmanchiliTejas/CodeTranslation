#include <bits/stdc++.h>
using namespace std;
#define N 3005
#define MOD 998244353
int n,m,ans,a[N],s[N],dp[N][N];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		for(int j=a[i];j<=m;++j) {dp[i][j]=s[j-a[i]];if(j==a[i]) dp[i][j]=(dp[i][j]+i)%MOD;}
		for(int j=a[i];j<=m;++j) s[j]=(s[j]+dp[i][j])%MOD;
	}
	for(int i=1;i<=n;++i) ans=(ans+1ll*dp[i][m]*(n-i+1)%MOD)%MOD;
	printf("%d\n",ans);return 0;
}