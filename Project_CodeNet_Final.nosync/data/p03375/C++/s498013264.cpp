#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+5;
int n,p,ans=0,po[maxn*maxn],pp[maxn],f[maxn][maxn],g[maxn],fac[maxn],inv[maxn];
int qpow(int i,int x,int p){
	int res=1;
	while(i){
		if(i&1){res=1ll*res*x%p;}
		x=1ll*x*x%p;i/=2;
	}
	return res;
}
int C(int x,int y,int p){return 1ll*fac[x]*inv[y]%p*inv[x-y]%p;}
int main(){
	scanf("%d%d",&n,&p);
	fac[0]=1;for(int i=1;i<=n;i++){fac[i]=1ll*fac[i-1]*i%p;}
	inv[n]=qpow(p-2,fac[n],p);for(int i=n;i>=1;i--){inv[i-1]=1ll*inv[i]*i%p;}
	po[0]=1;for(int i=1;i<=n*n;i++){po[i]=1ll*po[i-1]*2%p;}
	pp[0]=1;for(int i=1;i<=n;i++){pp[i]=1ll*pp[i-1]*2%(p-1);}
	for(int i=0;i<=n;i++){pp[i]=qpow(pp[i],2,p);}
	for(int i=0;i<=n;i++){f[i][0]=1;}
	for(int i=1;i<=n;i++){for(int j=1;j<=i;j++){f[i][j]=(1ll*f[i-1][j]*(j+1)%p+f[i-1][j-1])%p;}}
	for(int i=0;i<=n;i++){for(int j=0;j<=i;j++){g[i]=(g[i]+1ll*f[i][j]*po[j*(n-i)]%p*pp[n-i]%p)%p;}}
	for(int i=0,opt=1;i<=n;i++,opt*=-1){ans=(ans+p+1ll*opt*g[i]*C(n,i,p)%p)%p;}
	printf("%d\n",ans);
	return 0;
}
