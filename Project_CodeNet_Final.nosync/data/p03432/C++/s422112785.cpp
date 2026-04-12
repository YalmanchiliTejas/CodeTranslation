#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int N=20010,M=210;
const int mod=998244353;
int f[M][N];int a[N],b[N],cj[N],inv[N],Root[N],IRoot[N],bitrev[N];
int INV,curn,L;int ans;int n,m;

int power(int x,int y){
	int ret=1;
	for(;y;y>>=1,x=1ll*x*x%mod){
		if(y&1)	ret=1ll*ret*x%mod;
	}
	return ret;
}

void init(){
	int i;
	cj[0]=1;rep(i,1,n)	cj[i]=1ll*cj[i-1]*i%mod;
	inv[n]=power(cj[n],mod-2);inv[0]=1;
	for(i=n-1;i;i--)	inv[i]=1ll*inv[i+1]*(i+1)%mod;
	for(curn=1,L=0;curn<2*n;curn<<=1,L++);
	rep(i,0,curn-1)	bitrev[i]=bitrev[i>>1]>>1|((i&1)<<L-1);
	Root[0]=IRoot[0]=1;
	Root[1]=power(3,(mod-1)/curn);IRoot[1]=power(Root[1],mod-2);
	rep(i,2,curn)	Root[i]=1ll*Root[i-1]*Root[1]%mod;
	rep(i,2,curn)	IRoot[i]=1ll*IRoot[i-1]*IRoot[1]%mod;
	INV=power(curn,mod-2);
}
	
void DFT(int a[],int n,int w[]){
	int i,j,k,x,y;
	rep(i,0,n-1)	if(i<bitrev[i])	swap(a[i],a[bitrev[i]]);
	for(i=1;i<n;i<<=1){
		for(j=0;j<n;j+=(i<<1)){
			for(k=0;k<i;k++){
				x=a[j+k];y=1ll*a[j+k+i]*w[curn/(i<<1)*k]%mod;
				a[j+k]=(x+y)%mod;a[j+k+i]=(x-y+mod)%mod;
			}
		}
	}
}

int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	register int i,j;
	scanf("%d%d",&n,&m);
	init();
	rep(j,0,n-2)	b[j]=inv[j+2];
	DFT(b,curn,Root);
	f[m+1][0]=1;
	for(i=m;i;i--){
		rep(j,0,n)	f[i][j]=1ll*(n-j+1)*f[i+1][j]%mod;
		rep(j,0,n)	a[j]=1ll*cj[n-j]*f[i+1][j]%mod;
		rep(j,n+1,curn-1)	a[j]=0;
		DFT(a,curn,Root);
		rep(j,0,curn-1)	a[j]=1ll*a[j]*b[j]%mod;
		DFT(a,curn,IRoot);
		rep(j,0,n-2) f[i][j]=(f[i][j]+1ll*a[j]*INV%mod*inv[n-j-2])%mod;
	}
	//for(i=m;i;i--)	rep(j,0,n)	printf("f[%d][%d]=%d\n",i,j,f[i][j]);
	rep(i,0,n)	ans=(ans+f[1][i])%mod;
	printf("%d\n",ans);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		