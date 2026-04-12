#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define fi first
#define se second
#define pi pair<LL,LL>
#define LL long long
using namespace std;
const LL inf=2e9;
const LL mod=1e9+7;
LL n,h[110];
LL pow(LL a,LL b)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;b>>=1;
	}
	return ans;
}
pi solve(LL l,LL r,LL k)//l r区间大于k的部分
{
	LL Min=inf,cnt=0;pi ans;
	for(LL i=l;i<=r;i++)
	{
		if(h[i]<Min) Min=h[i],cnt=1;
		else if(h[i]==Min) cnt++;
	}
	if(cnt==(r-l+1))
	{
		ans.fi=(pow(2,r-l+1)+mod-2)%mod;
		ans.se=pow(2,Min-k-1);
		//printf("1:%lld %lld %lld %lld\n",l,r,ans.fi,ans.se);
		return ans;
	}
	LL re=r-l+1,s0=1,s1=1,last=0;
	for(LL i=l;i<=r+1;i++) if(!last&&h[i]>Min) last=i;
	else if(last&&(h[i]<=Min||i>r))
	{
		re-=i-last;
		pi tmp=solve(last,i-1,Min);
		s0=s0*(tmp.fi+4*tmp.se%mod)%mod;
		s1=s1*(2*tmp.se%mod)%mod;
		last=0;
	}
	s0=(s0+mod-s1)%mod;
	//printf("s:%lld %lld\n",s0,s1);
	ans.fi=s0*pow(2,re)%mod;
	(ans.fi+=(s1*(pow(2,re)-2+mod)%mod)%mod)%=mod;
	ans.se=s1*pow(2,Min-k-1)%mod;
	//printf("2:%lld %lld %lld %lld\n",l,r,ans.fi,ans.se);
	return ans;
} 
int main()
{
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++) scanf("%lld",&h[i]);
	if(n==1)
	{
		printf("%lld",pow(2,h[1]));
		return 0;
	}
	LL tot=1;
	for(LL i=1;i<=n;i++) if(h[i]>h[i-1]&&h[i]>h[i+1])
	{
		(tot*=pow(2,h[i]-max(h[i-1],h[i+1])))%=mod;
		h[i]=max(h[i-1],h[i+1]);
	}
	pi ans=solve(1,n,0);
	printf("%lld",tot*((ans.fi+ans.se*2)%mod)%mod);
}