#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,mod;
int s[3005][3005],C[3005][3005];
inline ll qpow(ll x,int k,int mod,ll r=1){
	for(;k;k>>=1,x=x*x%mod) if(k&1) r=r*x%mod;
	return r;
}
int main(){
	scanf("%d%d",&n,&mod); ll ans=0;
	for(int i=0;i<=n+1;++i) for(int j=C[i][0]=1;j<=i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	for(int i=s[0][0]=1;i<=n+1;++i) for(int j=1;j<=i;++j) s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j)%mod;
	for(int i=0;i<=n;++i){
		ll v=qpow(2,qpow(2,n-i,mod-1),mod)*(i&1?mod-1:1)%mod*C[n][i]%mod;
		for(int j=0;j<=i;++j) (ans+=v*qpow(2,(n-i)*j,mod)%mod*s[i+1][j+1])%=mod;
	}
	return printf("%lld\n",ans),0;
}