#include<bits/stdc++.h>

using namespace std;

#define N 3030
#define LL long long

LL n,p,ans,f[N],g[N][N],C[N][N];

LL pw(LL k,LL mod){
	if (k==0) return 1;
	LL tmp=pw(k>>1,mod);
	return k&1?tmp*tmp*2%mod:tmp*tmp%mod;
}

LL inv(LL x){return x==1?1:(p-p/x)*inv(p%x)%p;}

int main(){
	scanf("%lld%lld",&n,&p);
	g[0][0]=1;
	for (int i=1;i<=n;++i){
		g[i][0]=1;
		for (int j=1;j<=i;++j)
			g[i][j]=(g[i-1][j]*(j+1)+g[i-1][j-1])%p;
	}
	f[0]=pw(pw(n,p-1),p);
	for (int i=1;i<=n;++i){
		for (int j=0;j<=i;++j){
			g[i][j]=g[i][j]*pw(j*(n-i)%(p-1),p)%p;
			f[i]=(f[i]+g[i][j])%p;
		}
		f[i]=f[i]*pw(pw(n-i,p-1),p)%p;
	}
	C[0][0]=1;
	for (int i=1;i<=n;++i){
		C[i][0]=1;
		for (int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
	}
	for (int i=0;i<=n;++i)
		ans=(ans+(i&1?p-1:1)*f[i]%p*C[n][i])%p;
	printf("%lld\n",ans);
	
	return 0;
}
			