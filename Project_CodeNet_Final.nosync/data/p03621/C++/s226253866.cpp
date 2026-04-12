#include<cstdio>
#include<cstring>
const int maxn=10010,mod=998244353;
char a[maxn],b[maxn];
int len,n,m;
int iv[maxn],fc[maxn],ifc[maxn];
int f[maxn][maxn];
int ans;
int main() {
	scanf("%s%s",a+1,b+1),len=strlen(a+1);
	for(register int i=1;i<=len;++i) {
		if(a[i]=='1'&&b[i]=='1') ++n;
		else if(a[i]=='1') ++m;
	}
	iv[1]=1;
	for(register int i=2;i<=len;++i)iv[i]=1ll*iv[mod%i]*(mod-mod/i)%mod;
	fc[0]=ifc[0]=1;
	for(register int i=1;i<=len;++i)fc[i]=1ll*fc[i-1]*i%mod,ifc[i]=1ll*ifc[i-1]*iv[i]%mod;
	f[0][0]=1;
	for(register int i=1;i<=m;++i)f[0][i]=1ll*f[0][i-1]*i*i%mod;
	for(register int i=1;i<=n;++i)for(register int j=1;j<=m;++j)f[i][j]=(1ll*f[i-1][j]*i*j+1ll*f[i][j-1]*j*j)%mod;
	for(register int i=0;i<=n;++i)ans=(ans+1ll*f[i][m]*fc[n]%mod*ifc[i]%mod*fc[n+m]%mod*ifc[m+i])%mod;
	printf("%d\n",ans);
	return 0;
}