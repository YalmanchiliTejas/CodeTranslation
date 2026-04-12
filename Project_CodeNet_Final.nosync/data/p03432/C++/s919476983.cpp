#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<list>
#include<map>
using namespace std;
#define ll long long
#define mod 998244353
#define add(x) (x>=mod?x-mod:x)
#define jian(x) (x<0?x+mod:x)
ll n,m,inv2,inv6,f[205][8005],g[2005][2005],c[10005],inv[10005],anss,r[40005],gg=3,A[40005],B[40005],limit,l,CC[40005];
ll C(ll n,ll m){
	if(n<m||m<0) return 0;
	return c[n]*inv[m]%mod*inv[n-m]%mod; 
}
ll ksm(ll x,ll y){
	ll anss=1,t=x;
	while(y){
		if(y&1) anss=anss*t%mod;
		t=t*t%mod;
		y>>=1;
	}
	return anss;
}
void NTT(ll a[],ll limit,ll tp){
	for(ll i=0;i<limit;i++){
		if(i>r[i]) swap(a[i],a[r[i]]);
	}
	for(ll mid=1;mid<limit;mid<<=1){
		ll wc=ksm(gg,(mod-1)/(mid*2));
		if(tp==-1) wc=ksm(wc,mod-2);
		for(ll i=0;i<limit;i+=mid<<1){
			ll w=1;
			for(ll t=0;t<mid;t++,w=w*wc%mod){
				ll x=a[i+t],y=a[i+t+mid]*w%mod;
				a[i+t]=add(x+y);a[i+t+mid]=jian(x-y);
			}
		}
	}
	if(tp==-1){
		ll s=ksm(limit,mod-2);
		for(ll i=0;i<limit;i++){
			a[i]=a[i]*s%mod;
		}
	}
}
int main(){
//	freopen("wind.in","r",stdin);
//	freopen("wind.out","w",stdout);
	scanf("%lld%lld",&m,&n);
	inv2=ksm(2,mod-2);inv6=ksm(6,mod-2);
	c[0]=1;
	for(ll i=1;i<=n+m+20;i++) c[i]=c[i-1]*i%mod;
	inv[n+m+20]=ksm(c[n+m+20],mod-2);
	for(ll i=n+m+19;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	f[0][0]=1;
	for(ll i=1;i<=n;i++){
		for(ll t=0;t<=m;t++){
			f[i][t]=f[i-1][t]*(C(t+1,2)+1);
		}
		for(ll t=0;t<=4*m;t++) A[t]=B[t]=0;
		for(ll t=0;t<=m;t++) A[t]=f[i-1][t]*inv[t]%mod;
		for(ll t=0;t<=m;t++) B[t]=inv[t+3];
		limit=1,l=0;
		while(limit<=2*m) limit<<=1,l++;
		for(ll t=0;t<limit;t++) r[t]=(r[t>>1]>>1)|((t&1)<<(l-1)); 
		NTT(A,limit,1);NTT(B,limit,1);
		for(ll t=0;t<limit;t++) CC[t]=A[t]*B[t]%mod;
		NTT(CC,limit,-1);
		for(ll t=1;t<=m;t++){
			f[i][t]=(f[i][t]+CC[t-1]*c[t+2])%mod;
		}
	}
	for(ll i=0;i<=m;i++){
		anss=(anss+f[n][i]*C(m,i))%mod;
	}
	printf("%lld",anss);
}