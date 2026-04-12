#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int f[205][8005],fac[8005],ifac[8005],a[16384],b[16384];
inline int power(int a,int b){
	int c=1;
	while(b){
		if(b&1)c=1ll*c*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return c;
}
int r[16384];
void fft(int *a,int n,int opt){
	for(int i=0;i<n;i++)if(i<r[i])swap(a[i],a[r[i]]);
	for(int i=1;i<n;i<<=1){
		int wn=power(3,(mod-1)/i/2);
		if(opt==-1)wn=power(wn,mod-2);
		for(int j=0;j<n;j+=(i<<1)){
			int w=1;
			for(int k=0;k<i;k++,w=1ll*w*wn%mod){
				int x=a[j+k],y=1ll*a[j+k+i]*w%mod;
				a[j+k]=(x+y)%mod;
				a[j+k+i]=(x-y+mod)%mod;
			}
		}
	}
	if(opt==-1){
		int rev=power(n,mod-2);
		for(int i=0;i<n;i++)a[i]=1ll*a[i]*rev%mod;
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	fac[0]=1;
	for(int i=1;i<=n+2;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n+2]=power(fac[n+2],mod-2);
	for(int i=n+2;i>=1;i--)ifac[i-1]=1ll*ifac[i]*i%mod;
	for(int i=1;i<16384;i++)r[i]=(r[i>>1]>>1)|((i&1)*8192);
	for(int i=1;i<=n;i++)a[i]=ifac[i+2];
	// for(int i=1;i<=n;i++)printf("%d ",a[i]); puts("");
	fft(a,16384,1);
	f[0][0]=1;
	for(int i=0;i<m;i++){
		memset(b,0,sizeof(b));
		for(int j=0;j<=n;j++)b[j]=1ll*f[i][j]*ifac[j]%mod;
		// for(int j=0;j<=n;j++)printf("%d ",b[j]); puts("");
		fft(b,16384,1);
		for(int j=0;j<16384;j++)b[j]=1ll*b[j]*a[j]%mod;
		fft(b,16384,-1);
		// for(int j=0;j<=n;j++)printf("%d ",b[j]); puts("");
		for(int j=0;j<=n;j++)f[i+1][j]=(1ll*b[j]*fac[j+2]+1ll*f[i][j]*((j+1)*j/2+1))%mod;
	}
	// for(int i=0;i<=m;i++){
		// for(int j=0;j<=n;j++)printf("%d ",f[i][j]); puts("");
	// }
	int ans=0;
	for(int i=0;i<=n;i++)ans=(ans+1ll*f[m][i]*fac[n]%mod*ifac[i]%mod*ifac[n-i])%mod;
	printf("%d\n",ans);
	return 0;
}