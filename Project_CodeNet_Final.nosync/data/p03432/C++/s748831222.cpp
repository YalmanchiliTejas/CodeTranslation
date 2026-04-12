#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL
#define pow DCXISSOHANDSOME

ll pow[20][16384],fac[10010],ifac[10010];
ll f[210][10010],h1[32768],h2[32768];
int n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }
inline ll C(const int &x,const int &y) { return (x<0||y<0||x<y)?0:fac[x]*ifac[y]%mod*ifac[x-y]%mod; }

inline void pre_gao()
{
	fac[0]=1;
	for (int i=1;i<=10000;i++) fac[i]=fac[i-1]*i%mod;
	ifac[10000]=ksm(fac[10000],mod-2);
	for (int i=9999;~i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	for (int w=2,hh=1;w<=16384;w<<=1,hh++)
	{
		ll now=ksm(3,(mod-1)/w);
		pow[hh][0]=1;
		for (int j=1;j<(w>>1);j++) pow[hh][j]=pow[hh][j-1]*now%mod;
	}
}

inline void ntt(ll *a,int n,int on)
{
	static int rev[32768];
	for (int i=1;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)?(n>>1):0);
	for (int i=1;i<n;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int w=2,hh=1;w<=n;w<<=1,hh++) for (int k=0;k<n;k+=w) for (int j=k;j<k+(w>>1);j++)
	{
		ll u=a[j],t=a[j+(w>>1)]*pow[hh][j-k]%mod;
		a[j]=pls(u,t);a[j+(w>>1)]=mns(u,t);
	}
	if (on==-1)
	{
		reverse(a+1,a+n);
		ll Inv=ksm(n,mod-2);
		for (int i=0;i<n;i++) a[i]=a[i]*Inv%mod;
	}
}

int main()
{
	n=rd();m=rd();pre_gao();
	for (int i=1;i<=n;i++) f[1][i]=1;
	int len=1;
	for (;len<=n*2;len<<=1);
	for (int i=2;i<=m;i++)
	{
		for (int j=0;j<=n;j++) h1[j]=f[i-1][j]*ifac[j]%mod;
		memset(h1+n+1,0,sizeof(ll)*(len-n-1));
		h2[0]=0;
		for (int j=1;j<=n;j++) h2[j]=ifac[j+2];
		memset(h2+n+1,0,sizeof(ll)*(len-n-1));
		ntt(h1,len,1);ntt(h2,len,1);
		for (int j=0;j<len;j++) h1[j]=h1[j]*h2[j]%mod;
		ntt(h1,len,-1);
		for (int j=1;j<=n;j++) f[i][j]=pls(h1[j]*fac[j+2]%mod,f[i-1][j]*pls(C(j+1,2),1)%mod);
		for (int j=1;j<=n;j++) f[i][j]=pls(f[i][j],1);
	}
	ll ans=0;
	for (int i=1;i<=n;i++) ans=pls(ans,f[m][i]*C(n,i)%mod);
	printf("%lld\n",pls(ans,1));
	return 0;
}