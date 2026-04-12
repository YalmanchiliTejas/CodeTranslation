#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
const int mod=998244353;
int n,ans,i,fac[10000005],inv[10000005],fi[10000005];
int qp(int x,int y){
	int z=1;
	while(y){
		if(y&1){
			z=1ll*z*x%mod;
		}
		x=1ll*x*x%mod;
		y/=2;
	}return z;
}
int c(int x,int y){
	return 1ll*fac[x]*fi[y]%mod*fi[x-y]%mod;
}
int main(){
	fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;
	for(i=2;i<=10000000;i++){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		fi[i]=1ll*fi[i-1]*inv[i]%mod;
	}
	cin>>n;
	ans=qp(3,n);
	for(i=n/2+1;i<=n;i++){
		ans=(ans+2ll*(mod-c(n,i))*qp(2,n-i))%mod;
	}
	cout<<ans<<endl;
	return 0;
}