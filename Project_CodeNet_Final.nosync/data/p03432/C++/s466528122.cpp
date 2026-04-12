#include<cassert>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#define inver(a) power(a,mod-2)
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;
const int mod=998244353;
const int maxm=200+50;
const int maxn=8000+50; 
const int maxlog=20;
const int maxnode=maxn<<2;
int n,m;
int a[maxnode];
int b[maxnode];
int fac[maxn];
int fac_inv[maxn];
int f[maxm][maxn];
inline int add(int x)
{
	return x>=mod?x-mod:x;
}
inline int dec(int x)
{
	return x<0?x+mod:x;
} 
ll power(ll x,ll y)
{
	ll re=1;
	while(y)
	{
		if(y&1) re=re*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return re;
}
ll C(int x,int y)
{
	return (ll)fac[x]*fac_inv[y]%mod*fac_inv[x-y]%mod;
}
void init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;++i)
	{
		fac[i]=(ll)fac[i-1]*i%mod;
	}
	fac_inv[n]=inver(fac[n]);
	for(int i=n;i>=1;--i)
	{
		fac_inv[i-1]=(ll)fac_inv[i]*i%mod;
	}
}
namespace pol
{
	const int g=3;
	vector<int> w[2][maxlog];
	void init()
	{
		int g_inv=inver(g);
		for(int i=1,s=0;i<maxnode;i<<=1,++s)
		{
			ll w0=power(g,(mod-1)/(i<<1));
			ll w1=power(g_inv,(mod-1)/(i<<1));
			w[0][s].push_back(1);
			w[1][s].push_back(1);
			for(int k=1;k<i;++k)
			{
				w[0][s].push_back(w[0][s][k-1]*w0%mod);
				w[1][s].push_back(w[1][s][k-1]*w1%mod);
			}
		}
	}
	void FFT(int *a,int n,int f)
	{
		int d=f==-1;
		for(int i=0,j=0;i<n;++i)
		{
			if(i<j) swap(a[i],a[j]);
			for(int l=n>>1;(j^=l)<l;l>>=1);
		}
		for(int i=1,s=0;i<n;i<<=1,++s)
		{
			for(int j=0,p=i<<1;j<n;j+=p)
			{
				int *u=a+j;
				int *v=a+j+i;
				for(int k=0;k<i;++k,++u,++v)
				{
					int x=*u;
					int y=(ll)*v*w[d][s][k]%mod;
					*u=add(x+y);
					*v=dec(x-y);
				}
			}
		}
		if(f==-1)
		{
			int r=inver(n);
			for(int i=0;i<n;++i)
			{
				a[i]=(ll)a[i]*r%mod;
			}
		}
	}
}
int solve()
{
	for(int i=0;i<=n;++i)
	{
		f[1][i]=1;
	}
	init(n+2);
	pol::init();
	for(int i=1;i<=n;++i)
	{
		b[i]=fac_inv[i+2];
	}
	int deg=1;
	while(deg<=n*2) deg<<=1;
	pol::FFT(b,deg,1);
	for(int k=1;k<m;++k)
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<=n;++i)
		{
			a[i]=(ll)f[k][i]*fac_inv[i]%mod;
			f[k+1][i]=f[k][i]*(C(i+1,2)+1)%mod;
		}
		pol::FFT(a,deg,1);
		for(int i=0;i<deg;++i)
		{
			a[i]=(ll)a[i]*b[i]%mod;
		}
		pol::FFT(a,deg,-1);
		for(int i=0;i<=n;++i)
		{
			f[k+1][i]=(f[k+1][i]+(ll)a[i]*fac[i+2])%mod;
		}
	}
	int an=0;
	for(int i=0;i<=n;++i)
	{
		an=(an+f[m][i]*C(n,i))%mod;
	}
	return an;
}
int main()
{
	scanf("%d%d",&n,&m);
	printf("%d\n",solve());
	return 0;
} 