#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,mod,C[3030][3030],S[3030][3030],pom[3030],po[3030],ans;
int main()
{
	scanf("%d %d",&n,&mod);
	for(int i=0;i<=n;++i)
	{
		S[i][0]=1;
		for(int j=1;j<=n;++j)S[i][j]=(S[i-1][j-1]+1ll*S[i-1][j]*(j+1))%mod;
	}
	for(int i=0;i<=n;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)(C[i][j]=C[i-1][j-1]+C[i-1][j])>=mod?C[i][j]-=mod:0;
	}
	pom[0]=2,po[0]=1;
	for(int i=1;i<=n;++i)pom[i]=1ll*pom[i-1]*pom[i-1]%mod,po[i]=(po[i-1]<<1)%mod;
	for(int i=0;i<=n;++i)
	{
		int res=0,w=1;
		for(int j=0;j<=n;++j)res=(res+1ll*S[i][j]*pom[n-i]%mod*w)%mod,w=1ll*w*po[n-i]%mod;
		if(i&1)ans=(ans+1ll*(mod-res)*C[n][i])%mod;
		else ans=(ans+1ll*res*C[n][i])%mod;
	}
	printf("%d",ans);
	return 0;
}