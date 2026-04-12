#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
const int mod=998244353;

int gi() {
	int x=0,o=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') o=-1,ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*o;
}

int n,pw2[N],pw3[N],fac[N],inv[N],ifac[N];

int C(int n,int m) {
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

int main() {
	n=gi();
	pw2[0]=pw3[0]=1;
	for(int i=1;i<=n;i++) {
		pw2[i]=2ll*pw2[i-1]%mod;
		pw3[i]=3ll*pw3[i-1]%mod;
	}
	fac[0]=fac[1]=ifac[0]=ifac[1]=inv[1]=1;
	for(int i=2;i<=n;i++) {
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		ifac[i]=1ll*ifac[i-1]*inv[i]%mod;
	}
	int ans=pw3[n],sum=0;
	for(int i=n/2+1;i<=n;i++)
		sum=(sum+1ll*C(n,i)*pw2[n-i])%mod;
	cout<<(ans-2ll*sum%mod+mod)%mod;
	return 0;
}
