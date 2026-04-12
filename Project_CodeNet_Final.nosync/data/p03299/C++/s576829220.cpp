#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
inline int pl(int x,int y){return (x+=y)>=mod?x-mod:x;}
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n,h[110],dp[110][110],d[110],m,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&h[i]),d[i]=h[i];
	sort(d+1,d+1+n);
	m=unique(d+1,d+1+n)-d-1;
	for(int i=1;i<=n;++i)h[i]=lower_bound(d+1,d+1+m,h[i])-d;
	for(int i=0;i<=h[1];++i)dp[1][i]=kpow(2,d[h[1]]-d[i])*(1+(i>0))%mod;
	for(int i=0;i<=h[1];++i)add(dp[1][i],mod-dp[1][i+1]);
	for(int i=2;i<=n;++i)
	{
		for(int j=0;j<=h[i-1]&&j<=h[i];++j)dp[i][j]=dp[i-1][j];
		if(h[i-1]>=h[i])
		{
			for(int j=h[i]+1;j<=h[i-1];++j)add(dp[i][h[i]],dp[i-1][j]);
			for(int j=h[i];j<=h[i-1];++j)add(dp[i][h[i]],dp[i-1][j]);
		}
		else
		{
			int res=pl(dp[i][h[i-1]],dp[i-1][h[i-1]]);
			for(int j=h[i-1];j<=h[i];++j)dp[i][j]=1ll*res*kpow(2,d[h[i]]-d[j])%mod;
			for(int j=h[i-1];j<=h[i];++j)add(dp[i][j],mod-dp[i][j+1]);
			res=kpow(2,d[h[i]]-d[h[i-1]]);
			for(int j=0;j<h[i-1];++j)dp[i][j]=1ll*dp[i][j]*res%mod;
		}
	}
//	for(int i=1;i<=n;++i)
//	{
//		for(int j=0;j<=h[i];++j)printf("%d ",dp[i][j]);
//		printf("\n");
//	}
	for(int j=0;j<=h[n];++j)add(ans,dp[n][j]);
	printf("%d",ans);
	return 0;
}
