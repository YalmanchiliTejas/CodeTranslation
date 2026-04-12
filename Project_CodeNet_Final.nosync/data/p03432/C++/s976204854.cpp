#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long ll;

const int N=(1<<14)+5,M=805,Mo=998244353;

ll pwr(ll x,ll y) {
	ll z=1;
	for(;y;y>>=1,x=x*x%Mo)
		if (y&1) z=z*x%Mo;
	return z;
}

int n,m,len,lg,rev[N];
ll f[M][N],fac[N],inv[N],W[2][N],t1[N],t2[N],ilen;

void pre(int N) {
	fac[0]=1;fo(i,1,N) fac[i]=fac[i-1]*i%Mo;
	inv[N]=pwr(fac[N],Mo-2);fd(i,N-1,0) inv[i]=inv[i+1]*(i+1)%Mo;
	for(int i=1;i<N;i<<=1) {
		ll wn=pwr(3,(Mo-1)/(i<<1));
		for(int j=0;j<i;j++) W[1][i+j]=j?W[1][i+j-1]*wn%Mo:1;
		wn=pwr(3,Mo-1-(Mo-1)/(i<<1));
		for(int j=0;j<i;j++) W[0][i+j]=j?W[0][i+j-1]*wn%Mo:1;
	}
}

void DFT(ll *a,int len,int flag) {
	for(int i=0;i<len;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=1;i<len;i<<=1)
		for(int j=0;j<len;j+=i<<1)
			for(int k=0;k<i;k++) {
				ll u=a[j+k],v=a[j+k+i]*W[flag][i+k]%Mo;
				a[j+k]=(u+v)%Mo;a[j+k+i]=(u-v)%Mo;
			}
	if (!flag) for(int i=0;i<len;i++) a[i]=a[i]*ilen%Mo;
}

int main() {
	pre(1<<14);
	scanf("%d%d",&n,&m);
	for(len=1,lg=0;len<=n<<1;len<<=1) lg++;
	fo(i,0,len-1) rev[i]=rev[i>>1]>>1|((i&1)<<lg-1);
	ilen=pwr(len,Mo-2);
	f[0][0]=1;
	fo(i,0,m-1) {
		fo(j,0,len-1) t1[j]=t2[j]=0;
		fo(j,0,n) t1[j]=f[i][j]*inv[j]%Mo;
		fo(j,1,n) t2[j]=inv[j+2];
		DFT(t1,len,1);DFT(t2,len,1);
		fo(j,0,len-1) t1[j]=t1[j]*t2[j]%Mo;
		DFT(t1,len,0);
		fo(j,0,n) f[i+1][j]=t1[j]*fac[j+2]%Mo;
		fo(j,0,n) (f[i+1][j]+=f[i][j]*(j*(j+1)/2+1)%Mo)%=Mo;
	}
	ll ans=0;
	fo(j,0,n) (ans+=f[m][j]*fac[n]%Mo*inv[j]%Mo*inv[n-j]%Mo)%=Mo;
	printf("%lld\n",(ans+Mo)%Mo);
	return 0;
}