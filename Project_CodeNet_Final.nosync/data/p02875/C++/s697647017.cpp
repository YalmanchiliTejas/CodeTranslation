#include <cstdio>
#define Maxn 10000000
#define Mod 998244353
int n;
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
int frac[Maxn+5],inv[Maxn+5];
void init(){
	frac[0]=1;
	for(int i=1;i<=n;i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv[n]=ksm(frac[n],Mod-2);
	for(int i=n-1;i>=0;i--){
		inv[i]=1ll*inv[i+1]*(i+1)%Mod;
	}
}
int C(int n,int m){
	return 1ll*frac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
int main(){
	scanf("%d",&n);
	init();
	int ans=ksm(3,n);
	for(int i=(n>>1)+1;i<=n;i++){
		ans-=C(n,i)*2ll%Mod*ksm(2,n-i)%Mod;
		ans=(ans+Mod)%Mod;
	}
	printf("%d\n",ans);
	return 0;
}
