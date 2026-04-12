#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long int ll;
const int maxn=1E7+5; 
const int limit=10000000;
ll fac[maxn],inv[maxn],P2[maxn];
inline ll qpow(ll x,ll y)
{
	ll ans=1,base=x;
	while(y)
	{
		if(y&1)
			ans=ans*base%mod;
		base=base*base%mod;
		y>>=1;
	}
	return ans;
}
inline void init()
{
	fac[0]=1;
	for(int i=1;i<=limit;++i)
		fac[i]=fac[i-1]*i%mod;
	inv[limit]=qpow(fac[limit],mod-2);
	for(int i=limit-1;i>=0;--i)
		inv[i]=inv[i+1]*(i+1)%mod;
	P2[0]=1;
	for(int i=1;i<=limit;++i)
		P2[i]=P2[i-1]*2%mod;
}
inline ll C(int x,int y)
{
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
	ios::sync_with_stdio(false);
	init();
	int n;
	cin>>n;
	ll ans=qpow(3,n),s=0;
	for(int i=n/2+1;i<=n;++i)
		s=(s+P2[n-i]*C(n,i))%mod;
	cout<<((ans-s*2)%mod+mod)%mod<<endl;
	return 0;
}
