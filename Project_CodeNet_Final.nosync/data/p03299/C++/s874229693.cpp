#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int Mod=1e9+7;
int n,h[110];
ll qpow(ll x,ll a){
	ll res=1;
	while (a){
		if (a&1) res=res*x%Mod;
		x=x*x%Mod; a>>=1;
	}
	return res;
}
inline ll calc(int l){
	return (qpow(2,l)+Mod-2)%Mod;
}
pii solve(int l,int r,int k){
	int mn=h[l],cnt=0;
	for (int i=l+1;i<=r;i++) mn=min(mn,h[i]);
	for (int i=l;i<=r;i++)
		if (h[i]==mn) cnt++;
	if (cnt==r-l+1) return pii(calc(r-l+1),qpow(2,mn-k-1));
	int tot=r-l+1,s0=1,s1=1,last=0;
	for (int i=l;i<=r+1;i++)
		if (!last&&h[i]>mn) last=i;
		else
			if (last&&(h[i]<=mn||i>r)){
				tot-=i-last;
				pii tmp=solve(last,i-1,mn);
				s0=(ll)s0*(tmp.first+4ll*tmp.second%Mod)%Mod;
				s1=(ll)s1*(2ll*tmp.second%Mod)%Mod;
				last=0;
			}
	s0=(s0+Mod-s1)%Mod; pii res;
	res.first=(ll)s0*qpow(2,tot)%Mod;
	res.first=(res.first+(ll)s1*calc(tot)%Mod)%Mod;
	res.second=(ll)s1*qpow(2,mn-k-1)%Mod;
	return res;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&h[i]);
	if (n==1){
		printf("%lld\n",qpow(2,h[1]));
		return 0;
	}
	ll mul=1;
	for (int i=1;i<=n;i++)
		if (h[i]>max(h[i-1],h[i+1])){
			mul=mul*qpow(2,h[i]-max(h[i-1],h[i+1]))%Mod;
			h[i]=max(h[i-1],h[i+1]);
		}
	pii ans=solve(1,n,0);
	printf("%lld\n",1ll*mul*(ans.first+2ll*ans.second)%Mod);
	return 0;
}
