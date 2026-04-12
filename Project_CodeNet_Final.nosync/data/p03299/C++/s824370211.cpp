#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fi first
#define se second
const int maxn=105;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int n,h[maxn];
inline ll fpow(ll a,ll b)
{
	ll ret=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1) ret=ret*a%mod;
	return ret;
}
inline pll solve(int l,int r,int k)
{
	int mn=inf,cnt=0;
	for(int i=l;i<=r;i++)
		if(h[i]<mn) mn=h[i],cnt=1;
		else if(h[i]==mn) cnt++;
	if(cnt==r-l+1) return pll(fpow(2,r-l+1)-2,fpow(2,mn-k));
	int last=0; ll s0=1,s1=1; pll ret=pll(0,0);
	for(int i=l;i<=r+1;i++)
		if(!last && h[i]>mn) last=i;
		else if((i>r || h[i]==mn) && last)
		{
			pll tmp=solve(last,i-1,mn);
			(s0*=(tmp.fi+2*tmp.se))%=mod;
			(s1*=tmp.se)%=mod;
			last=0;
		}
	(s0-=s1)%=mod;
	ret.fi=(s0*fpow(2,cnt)+s1*(fpow(2,cnt)-2))%mod;
	ret.se=s1*fpow(2,mn-k)%mod;
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	ll ans=1;
	for(int i=1;i<=n;i++)
		if(h[i]>h[i-1] && h[i]>h[i+1])
			(ans*=fpow(2,h[i]-max(h[i-1],h[i+1])))%=mod,h[i]=max(h[i-1],h[i+1]);
	pll ret=solve(1,n,0);
	printf("%lld\n",(ans*(ret.fi+ret.se)%mod+mod)%mod);	
	return 0;
}