#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3005;
int n,mod,inv[N],bin[N],pw[N],g[N][N],ans;
int main(){
	scanf("%d%d",&n,&mod);
	inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
	bin[0]=1;pw[0]=2;
	for(int i=1;i<=n;++i){
		bin[i]=(bin[i-1]<<1)%mod;
		pw[i]=1ll*pw[i-1]*pw[i-1]%mod;
	}
	for(int i=g[0][0]=1;i<=n;++i)
		for(int j=0;j<=i;++j)
			g[i][j]=((j?g[i-1][j-1]:0)+1ll*g[i-1][j]*(j+1))%mod;
	for(int i=0,C=1;i<=n;++i,C=1ll*C*(n-i+1)%mod*(mod-inv[i])%mod){
		int res=0;
		for(int j=0,k=1;j<=i;++j,k=1ll*k*bin[n-i]%mod)
			res=(res+1ll*g[i][j]*k)%mod;
		ans=(ans+1ll*res*pw[n-i]%mod*C)%mod;
	}
	printf("%d\n",ans);
	return 0;
}
