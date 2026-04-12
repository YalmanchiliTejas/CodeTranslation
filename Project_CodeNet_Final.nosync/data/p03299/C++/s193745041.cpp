#include<bits/stdc++.h> 
#define ll long long
#define N 105
#define mod 1000000007
using namespace std;
ll n,f[N][N],h[N],w[N],tot;
inline ll ksm(ll x,ll p){
	if(p<0)return 1;
	ll ret=1;
	while(p){
		
		if(p&1)ret=ret*x%mod;
		x=x*x%mod;
		p>>=1;
	}
	return ret;
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;++i)scanf("%lld",&h[i]),w[++tot]=h[i];
	sort(w+1,w+tot+1);
	tot=unique(w+1,w+tot+1)-w-1;
	for(ll i=1;i<=n;++i)h[i]=lower_bound(w+1,w+tot+1,h[i])-w;
	f[0][0]=1;
	for(ll i=1;i<=n;++i){
		for(ll j=h[i]+1;j<=h[i-1];++j)(f[i][0]+=f[i-1][j]*2%mod)%=mod;
		(f[i][0]+=f[i-1][0]*2%mod)%=mod;
		for(ll j=1;j<=h[i];++j){
			f[i][j]=(ll)f[i-1][j]*ksm(2,w[h[i]]-w[h[i-1]])%mod;
			if(h[i-1]>=j)continue;
			if(j>1)(f[i][j]+=(ll)f[i-1][0]*(ksm(2,w[j]-w[j-1])-1)%mod*2%mod*ksm(2,w[h[i]]-w[j])%mod)%=mod;
			else (f[i][j]+=(ll)f[i-1][0]*(ksm(2,w[j])-2)%mod*ksm(2,w[h[i]]-w[j])%mod)%=mod;
		}
	}
	ll ans=0;
	for(ll i=0;i<=tot;++i)(ans+=f[n][i])%=mod;
	printf("%lld",ans);
	return 0;
}