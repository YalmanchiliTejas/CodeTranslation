#include <stdio.h>
#include <algorithm>
#define il inline
#define int long long
#define N 8001
using namespace std;
const int gi=3,mod=998244353;

int n,m,inv,ans;
int base=1,l,rev[4*N];
int fac[N+2],iac[N+2];
int f[N][N/40+1],F[4*N],G[4*N];

il int ksm(int a,int b)
{
	int res=1;
	for ( ; b; b>>=1,a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}

il void NTT(int *Z,int opt)
{
	int i,j,k;
	for (i=1; i<base; i++) if (i<rev[i]) swap(Z[i],Z[rev[i]]);
	for (i=1; i<base; i<<=1)
	{
		int Wn=ksm(gi,(mod-1)/(i<<1));
		for (j=0; j<base; j+=(i<<1))
		{
			int W=1;
			for (k=0; k<i; W=W*Wn%mod,k++)
			{
				int X=Z[j+k],Y=W*Z[j+i+k]%mod;
				Z[j+k]=(X+Y)%mod,Z[j+i+k]=(X-Y+mod)%mod;
			}
		}
	}
	if (opt==1) return;
	reverse(Z+1,Z+base);
	for (i=0; i<base; i++) Z[i]=Z[i]*inv%mod;
}

signed main()
{
	scanf("%lld%lld",&n,&m);
	int i,j;
	for (i=fac[0]=1; i<=n+2; i++) fac[i]=fac[i-1]*i%mod;
	for (i=n+2,iac[i]=ksm(fac[i],mod-2); i>=1; i--) iac[i-1]=iac[i]*i%mod;
	while (base<=n+n+2) base<<=1,l++;
	for (i=1,inv=ksm(base,mod-2); i<base; i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	
	for (i=1; i<=n; i++) G[i]=iac[i+2];
	f[0][0]=1,NTT(G,1);
  	for (j=1; j<=m; j++)
	{
    	for (i=0; i<=n; i++) F[i]=f[i][j-1]*iac[i];
    	for (i=n+1; i<base; i++) F[i]=0;
    	NTT(F,1);
    	for (i=0; i<base; i++) F[i]=F[i]*G[i]%mod;
    	NTT(F,-1);
    	for (i=0; i<=n; i++) f[i][j]=(F[i]*fac[i+2]%mod+f[i][j-1]*(1ll+i*(i+1)/2)%mod)%mod;
  	}
  	for (i=0; i<=n; i++) ans=(ans+f[i][m]*fac[n]%mod*iac[i]%mod*iac[n-i]%mod)%mod;
  	printf("%lld",ans);
	
	return 0;
}