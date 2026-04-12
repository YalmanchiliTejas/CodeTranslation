#include<map>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
const LL mod=1e9+7;
LL f[110][110][2],n,h[110];
bool vis[110][110];
LL Pow(LL a,LL b)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;b>>=1;
	}
	return ans;
}
void solve(LL l,LL r,LL s)
{
	//printf("solve:%lld %lld %lld\n",l,r,s);
	bool flag=true;
	for(LL i=l;i<r;i++) if(h[i]!=h[i+1]) flag=false;
	if(flag)
	{
		LL c=Pow(2,r-l+1);
		f[l][r][1]=(c-2+mod)%mod;
		f[l][r][0]=Pow(2,h[l]-s+1);
		//printf("f:%lld %lld\n",f[l][r][0],f[l][r][1]);
		return;
	}
	LL t=1e9+10,cnt=0;
	for(LL i=l;i<=r;i++)
	{
		if(h[i]<t) t=h[i],cnt=0;
		if(t==h[i]) cnt++;
	}
	LL p=l,g0=2,g1=1;
	//printf("t:%lld\n",t);
	while(p<=r)
	{
		while(p<=r&&h[p]==t) p++;
		LL q=p;
		while(q<=r&&h[q]!=t) q++;
		if(p<=r)
		{
			solve(p,q-1,t+1);
			(g0*=f[p][q-1][0])%=mod;
			(g1*=(f[p][q-1][0]*2+f[p][q-1][1])%mod)%=mod;
		}
		//printf("g0 g1:%lld %lld\n",g0,g1);
		p=q;
	}
	//printf("g1:%lld\n",g1);
	(g1*=Pow(2,cnt))%=mod;g1-=g0;(g1+=mod)%=mod;
	(g0*=Pow(2,t-s))%=mod;
	//printf("now:%lld %lld %lld %lld %lld\n",l,r,s,g0,g1);
	f[l][r][0]=g0;f[l][r][1]=g1;
}
int main()
{
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++) scanf("%lld",&h[i]);
	memset(vis,false,sizeof(vis));
	LL tot=1;
	for(LL i=1;i<=n;i++) if(h[i]>h[i-1]&&h[i]>h[i+1])
	{
		LL t=max(h[i-1],h[i+1]);
		(tot*=Pow(2,h[i]-t))%=mod;h[i]=t;
	}
	solve(1,n,1);
	printf("%lld",tot*(f[1][n][0]+f[1][n][1])%mod);
}