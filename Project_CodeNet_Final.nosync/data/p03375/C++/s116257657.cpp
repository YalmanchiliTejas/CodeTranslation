#include<bits/stdc++.h>
#define inv(x) power(x,Mod-2)
#define upd(a,b) a=add(a,b)
using namespace std;
typedef long long ll;
ll Mod;
ll add(ll a,const ll b){a+=b;if(a>=Mod)a-=Mod;return a;}
ll sub(ll a,const ll b){a-=b;if(a<0)a+=Mod;return a;}
ll mul(const ll a,const ll b){return (ll)a*b%Mod;}
ll power(ll x,ll cs)
{
	ll ras=1;
	while(cs)
	{
		if(cs&1) ras=mul(ras,x);
		x=mul(x,x);cs>>=1;
	}
	return ras;
}
ll fpwr(ll x,ll cs)
{
	ll ret;
	Mod--;ret=power(x,cs);Mod++;
	return ret;
}
const ll N=3050;
ll n,ans=0;
ll g[N][N],f[N],cf[N],zp[N],fp[N];
int C(int a,int b){return mul(zp[a],mul(fp[b],fp[a-b]));}
int main()
{
	ll i,j,K,w;
	cin>>n>>Mod;
	cf[0]=1;
	for(i=1;i<=n;i++) cf[i]=mul(cf[i-1],2);
	zp[0]=fp[0]=1;
	for(i=1;i<=n;i++) zp[i]=mul(zp[i-1],i);
	fp[n]=inv(zp[n]);
	for(i=n-1;i>=1;i--) fp[i]=mul(fp[i+1],i+1);
	for(i=0;i<=n;i++)
	{
		g[i][0]=1;
		for(j=1;j<=i;j++)
		{
			g[i][j]=add(g[i-1][j-1],mul(j+1,g[i-1][j]));
		}
	}
	for(K=1;K<=n;K++)
	{
		for(i=0,w=1;i<=K;i++,w=mul(w,cf[n-K]))
		{
			upd(f[K],mul(g[K][i],w));
		}
		f[K]=mul(f[K],C(n,K));
		f[K]=mul(f[K],power(2,fpwr(2,n-K)));
	}
	f[0]=power(2,fpwr(2,n));
	for(i=0;i<=n;i++)
	{
		//printf("#%lld  %lld\n",i,f[i]);
		if(i&1ll) ans=sub(ans,f[i]);
		else ans=add(ans,f[i]);
	}
	cout<<ans;
	return 0;
}