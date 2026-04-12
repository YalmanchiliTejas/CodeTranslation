#include<iostream>
#include<cstdio>
#define ll long long
#define mod 998244353
using namespace std;
int n;
ll p2[10000010],p3[10000010],inv[10000010],ifac[10000010],fac[10000010];
inline ll calc(int n,int m){
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
inline ll solve(){
	ll res=0;
	for(register int i=(n>>1)+1;i<=n;i++){
		res=(res+calc(n,i)*p2[n-i]%mod)%mod;
	}
	return res;
}
int main(){
	scanf("%d",&n);
	inv[1]=1;
	for(register int i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	p2[0]=p3[0]=fac[0]=ifac[0]=1;
	for(register int i=1;i<=n;i++){
		p2[i]=p2[i-1]*2%mod;
		p3[i]=p3[i-1]*3%mod;
		fac[i]=fac[i-1]*i%mod;
		ifac[i]=ifac[i-1]*inv[i]%mod;
	}
	printf("%lld",(p3[n]-2ll*solve()%mod+mod)%mod);
	return 0;
}