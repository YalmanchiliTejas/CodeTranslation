#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3010;
const ll INF=1e18;
int a[N];
ll dp[N][N][2];
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch&15),ch=getchar();
	return x*f;
}
int main()
{
	int n=read();
	for (register int i=1;i<=n;++i) a[i]=read();
	for (register int i=1;i<=n;++i) dp[i][i][0]=a[i],dp[i][i][1]=-a[i];
	for (register int i=n;i>=1;--i)
	  for (register int j=i+1;j<=n;++j)
	  {
	  	  dp[i][j][0]=max(dp[i+1][j][1]+a[i],dp[i][j-1][1]+a[j]);
	  	  dp[i][j][1]=min(dp[i+1][j][0]-a[i],dp[i][j-1][0]-a[j]);
	  }
	printf("%lld\n",dp[1][n][0]);
	return 0;
}