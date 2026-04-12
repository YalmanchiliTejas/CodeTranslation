#include<bits/stdc++.h>
using namespace std;

int n,mod,ans;
inline int qpow(int d,int z,int t=0,int a=1){
	for(;z;z>>=1,d=1ll*d*d%(mod-t))
		if(z&1) a=1ll*a*d%(mod-t); return a;
}
int fac[3009],inv[3009];
inline int c(int n,int m){return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}

int g[3009][3009];
inline int f(int i){
	int ret=0;
	for(int j=0;j<=i;++j)
		ret=(ret+1ll*g[i][j]*qpow(2,(n-i)*j)%mod*qpow(2,qpow(2,n-i,1)))%mod;
	return ret;
}
int main(){
	scanf("%d%d",&n,&mod);
	for(int i=fac[0]=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n;i;--i) inv[i-1]=1ll*inv[i]*i%mod;
	g[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=i;++j)
			g[i][j]=(g[i-1][j-1]+g[i-1][j]*(j+1ll))%mod;
	for(int i=0;i<=n;++i) ans=(ans+(i&1?mod-1ll:1ll)*c(n,i)%mod*f(i))%mod;
	printf("%d\n",ans);
	return 0;
}