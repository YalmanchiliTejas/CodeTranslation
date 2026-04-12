#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define ll long long
ll f[3005],inv[3005],S[3005][3005],mi1[3005],mi2[3005],n,mod,ans;
ll ksm(ll x,ll y,ll mod){
	ll anss=1,t=x;
	while(y){
		if(y&1) anss=anss*t%mod;
		t=t*t%mod;
		y>>=1;
	}
	return anss;
}
ll C(ll n,ll m){
	return f[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	scanf("%lld%lld",&n,&mod);
	for(ll i=0;i<=n;i++) mi1[i]=ksm(2,ksm(2,i,mod-1),mod);
	for(ll i=0;i<=n;i++) mi2[i]=ksm(2,i,mod);
	f[0]=1;
	for(ll i=1;i<=n;i++) f[i]=f[i-1]*i%mod;
	inv[n]=ksm(f[n],mod-2,mod);
	for(ll i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	S[0][0]=1;
	for(ll i=1;i<=n+1;i++){
		for(ll t=1;t<=i;t++){
			S[i][t]=(S[i-1][t]*t+S[i-1][t-1])%mod;
		}
	}
	for(ll i=0;i<=n;i++){
		ll now=0,qwq=1;
		for(ll t=0;t<=i;t++){
			now=(now+S[i+1][t+1]*qwq)%mod;
			qwq=qwq*mi2[n-i]%mod;
		}
//		cout<<ans<<endl;
		ans=(ans+((i&1)?mod-1:1)*mi1[n-i]%mod*C(n,i)%mod*now)%mod;
	}
	printf("%lld",ans);
}