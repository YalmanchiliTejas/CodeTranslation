#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define N 1050
int n,A,B,C,D;
ll f[N][N],fac[N],inv[N],ii[N];
void upd(ll &x,ll y) {
	x+=y; if(x>=mod) x-=mod;
}
ll qp(ll x,ll y) {
	ll re=1;
	for(;y;y>>=1,x=x*x%mod) if(y&1) re=re*x%mod; return re;
}
int main() {
	scanf("%d%d%d%d%d",&n,&A,&B,&C,&D);
	int i,j,k;
	f[A-1][0]=1;
	for(i=1;i<=n;i++) ii[i]=qp(i,mod-2);
	for(fac[0]=i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=qp(fac[n],mod-2);
	for(i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	for(i=A-1;i<B;i++) {
		for(j=0;j<=n;j++) if(f[i][j]) {
			upd(f[i+1][j],f[i][j]);
			ll tmp=1;
			for(k=1;k<=D&&j+(i+1)*k<=n;k++) {
				tmp=tmp*fac[n-j-(i+1)*(k-1)]%mod*inv[n-j-(i+1)*k]%mod*inv[i+1]%mod*ii[k]%mod;
				if(k>=C) {
					upd(f[i+1][j+(i+1)*k],f[i][j]*tmp%mod);
				}
			}
		}
	}
	printf("%lld\n",f[B][n]);
}
