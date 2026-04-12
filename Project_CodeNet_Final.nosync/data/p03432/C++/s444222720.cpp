#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5,mod=998244353;
int w[N],lim,f[N],n,m,g[N],h[N],rev[N],fac[N],ifac[N],inv[N];
void NTT(int a[])
{
	for(int i=0;i<lim;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			for(int k=0;k<i;k++)
			{
				int x=a[j+k],y=1ll*a[i+j+k]*w[i+k]%mod;
				a[j+k]=(x+y)%mod,a[i+j+k]=(x-y)%mod;
			} 
}
int qpower(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
void make(int n)
{
	lim=1;while(lim<=n*2)lim<<=1;
	for(int i=1;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)?(lim>>1):0);
	fac[0]=1;
	for(int i=1;i<=n+2;i++)
		fac[i]=1ll*fac[i-1]*i%mod,
		inv[i]=i==1?1:1ll*(mod-mod/i)*inv[mod%i]%mod;
	ifac[0]=1;
	for(int i=1;i<=n+2;i++)ifac[i]=1ll*ifac[i-1]*inv[i]%mod;
	for(int i=1;i<lim;i<<=1)
	{
		int g=qpower(3,(mod-1)/(i<<1));
		w[i]=1;
		for(int j=1;j<i;j++)w[i+j]=1ll*w[i+j-1]*g%mod;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	make(n);f[0]=1;
	for(int i=0;i<=n;i++)h[i]=ifac[i+2];
	NTT(h);
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++)g[j]=1ll*f[j]*ifac[j]%mod;
		for(int j=n+1;j<lim;j++)g[j]=0;
		NTT(g);
		for(int j=0;j<lim;j++)g[j]=1ll*g[j]*h[j]%mod;
		reverse(g+1,g+lim);NTT(g);int ivl=mod-(mod-1)/lim;
		for(int j=0;j<=n;j++)f[j]=(-1ll*f[j]*j+1ll*g[j]*ivl%mod*fac[j+2])%mod;
	}
	int C=1,ans=0;
	for(int i=0;i<=n;i++)ans=(ans+1ll*C*f[i])%mod,C=1ll*C*(n-i)%mod*inv[i+1]%mod;
	cout<<(ans+mod)%mod<<endl;
}