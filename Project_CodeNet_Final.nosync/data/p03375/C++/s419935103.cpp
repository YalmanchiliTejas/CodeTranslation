#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1; char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
int n,mod;
ll fac[3010],ifac[3010],f[3010][3010];
ll C(int n,int m){return fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
ll fp(ll a,ll k,ll mod){
	ll ans=1;
	for(;k;k>>=1,a=a*a%mod)
		if(k&1) ans=a*ans%mod;
	return ans;
}
int main(){
	read(n);read(mod);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n]=fp(fac[n],mod-2,mod);
	for(int i=n;i;i--) ifac[i-1]=ifac[i]*i%mod;
	for(int i=0;i<=n;i++) f[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			f[i][j]=(f[i-1][j]*(j+1)+f[i-1][j-1])%mod;
	ll ans=0;
	for(int i=0;i<=n;i++){
		ll now=0,tmp=fp(2,n-i,mod),cef=fp(2,fp(2,n-i,mod-1),mod),k=1;
		for(int j=0;j<=i;j++){
			now=(now+f[i][j]*k)%mod;
			k=k*tmp%mod;
		}
		now=now*cef%mod;
		ans=(ans+(i&1?-1:1)*now*C(n,i))%mod;
	}
	cout<<(ans+mod)%mod<<'\n';
	return 0;
}
