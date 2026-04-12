#include<cstdio>
#define int long long
int fac[3010],inv[3010],S[3010][3010],mod,n,f[3010],ans;
int quickpow(int x,int y,int mod){
	int res=1;
	for(;y;y>>=1){
		if(y&1)res=res*x%mod;
		x=x*x%mod;
	}
	return res;
}
int C(int x,int y){
	if(x<y||y<0)return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int sgn(int x){
	if(x%2==0)return 1;
	else return mod-1;
}
signed main(){
	scanf("%lld%lld",&n,&mod);
	S[0][0]=1;
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=i;j++)
			S[i][j]=(j*S[i-1][j]%mod+S[i-1][j-1])%mod;
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%mod;
	inv[n]=quickpow(fac[n],mod-2,mod);
	for(int i=n-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%mod;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++)
			(f[i]+=S[i+1][j+1]*quickpow(2,(n-i)*j,mod)%mod)%=mod;
		(f[i]*=quickpow(2,quickpow(2,n-i,mod-1),mod))%=mod;
	}
	for(int i=0;i<=n;i++)
		(ans+=sgn(i)*C(n,i)%mod*f[i]%mod)%=mod;
	printf("%lld\n",ans);
}