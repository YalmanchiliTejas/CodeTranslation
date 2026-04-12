#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
inline int pl(int x,int y){return (x+=y)>=mod?x-mod:x;}
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n,m,ans,dp[8080][210],jc[8080],jcv[8080],f[16384],g[16384];
int w[14][8192];
void init()
{
	jc[0]=1;
	for(int i=1;i<=n+2;++i)jc[i]=1ll*jc[i-1]*i%mod;
	jcv[n+2]=kpow(jc[n+2],mod-2);
	for(int i=n+2;i;--i)jcv[i-1]=1ll*jcv[i]*i%mod;
	for(int len=1,i=0;len<16384;len<<=1,++i)
	{
		int tmp=kpow(3,(mod-1)/len/2);
		w[i][0]=1;
		for(int j=1;j<len;++j)w[i][j]=1ll*w[i][j-1]*tmp%mod;
	}
}
void ntt(int f[],int opt,int lim)
{
	static int r[16384],now;
	if(now!=lim)
	{
		now=lim;
		for(int i=1;i<lim;++i)r[i]=(r[i>>1]>>1)|(i&1?lim>>1:0);
	}
	for(int i=1;i<lim;++i)if(i<r[i])swap(f[i],f[r[i]]);
	int x,y;
	for(int len=1,i=0;len<lim;len<<=1,++i)
		for(int j=0;j<lim;j+=len<<1)
			for(int k=0;k<len;++k)
			{
				x=f[j+k],y=1ll*f[j+k+len]*w[i][k]%mod;
				f[j+k]=pl(x,y);
				f[j+k+len]=pl(x,mod-y);
			}
	if(opt==-1)
	{
		reverse(f+1,f+lim);
		int inv=kpow(lim,mod-2);
		for(int i=0;i<lim;++i)f[i]=1ll*f[i]*inv%mod;
	}
}
int C(int a,int b)
{
	if(a<b)return 0;
	return 1ll*jc[a]*jcv[b]%mod*jcv[a-b]%mod;
}
int main()
{
	scanf("%d %d",&n,&m);
	init();
	int lim=1;
	while(lim<=2*n)lim<<=1;
	dp[0][0]=1;
	for(int j=1;j<=m;++j)
	{
		for(int i=0;i<=n;++i)dp[i][j]=1ll*dp[i][j-1]*(1+C(i+1,2))%mod;
		memset(f,0,lim<<2),memset(g,0,lim<<2);
		for(int i=0;i<=n;++i)f[i]=1ll*dp[i][j-1]*jcv[i]%mod,g[i]=jcv[i+2];
		g[0]=0;
		ntt(f,1,lim),ntt(g,1,lim);
		for(int i=0;i<lim;++i)f[i]=1ll*f[i]*g[i]%mod;
		ntt(f,-1,lim);
		for(int i=0;i<=n;++i)dp[i][j]=(dp[i][j]+1ll*f[i]*jc[i+2])%mod;
	//	for(int i=0;i<=n;++i)printf("%d ",dp[i][j]);printf("\n");
	}
	for(int i=0;i<=n;++i)ans=(ans+1ll*dp[i][m]*C(n,i))%mod;
	printf("%d",ans);
	return 0;
}
