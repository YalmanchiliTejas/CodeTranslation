#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL

ll fac[10000010],ifac[10000010],bin[10000010];
int n;

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

inline void pre_gao()
{
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n]=ksm(fac[n],mod-2);
	for (int i=n-1;~i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	bin[0]=1;
	for (int i=1;i<=n;i++) bin[i]=bin[i-1]*2%mod;
}

int main()
{
	n=rd();pre_gao();
	ll ans=0;
	for (int i=n/2+1;i<=n;i++) ans=pls(ans,ifac[i]*ifac[n-i]%mod*bin[n-i+1]%mod);
	printf("%lld\n",mns(ksm(3,n),ans*fac[n]%mod));
	return 0;
}