#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
typedef long long ll;
inline ll qpow(ll x,ll y,ll m)
{ll r=1;for(;y;y>>=1,(x*=x)%=m)if(y&1)(r*=x)%=m;return r;}
ll mod;
int n;
ll C[3333][3333],S2[3333][3333],R[3333];
int main()
{
	scanf("%d%lld",&n,&mod);
	register int i,ii;
	for(i=0;i<=n;i++)C[i][i]=S2[i][0]=C[i][0]=1;
	for(i=1;i<=n;i++)
		for(ii=1;ii<i;ii++)
			C[i][ii]=(C[i-1][ii]+C[i-1][ii-1])%mod;
	for(i=1;i<=n;i++)
		for(ii=1;ii<=i;ii++)
			S2[i][ii]=(S2[i-1][ii-1]+(ii+1)*S2[i-1][ii])%mod;
	ll w,wi;
	for(i=0;i<=n;i++)
		for(ii=0,w=qpow(2,n-i,mod),wi=1;ii<=i;ii++,(wi*=w)%=mod)
			(R[i]+=S2[i][ii]*wi)%=mod;
	ll ans=0;
	for(i=0;i<=n;i++)
	{
		ll k=qpow(2,qpow(2,n-i,mod-1),mod);
		(ans+=(((i&1)?-1:1)*k*R[i])%mod*C[n][i])%=mod;
	}printf("%lld\n",(ans+mod)%mod);
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/