#include<bits/stdc++.h>
#define FOR(i,a,b) for (register int i=(a);i<=(b);i++)
#define For(i,a,b) for (register int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
const int N=6e3+5;
int n,mod,fac[N],inv[N],ans=0,g[N][N],f[N],er[N],erer[N],two[N*N];
inline void upd(int &a,int b) {a=(1LL*a+b)%mod;return;}
inline int qpow(int x,int y,int m){int ret=1;for(;y;y>>=1,x=1LL*x*x%m)if(y&1)ret=1LL*ret*x%m;return ret;}
inline int C(int x,int y) {return 1LL*fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main()
{
	scanf("%d%d",&n,&mod);
	fac[0]=er[0]=1;
	FOR(i,1,n) er[i]=2LL*er[i-1]%(mod-1);
	FOR(i,1,n) fac[i]=1LL*fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2,mod);
	For(i,n-1,0) inv[i]=1LL*inv[i+1]*(i+1)%mod;
	FOR(i,0,n) g[i][0]=1;
	FOR(i,1,n) FOR(j,1,i) g[i][j]=(1LL*g[i-1][j-1]+1LL*g[i-1][j]*(j+1)%mod)%mod;
	FOR(i,0,n) erer[i]=qpow(2,er[i],mod);
	two[0]=1;
	FOR(i,1,n*n) two[i]=2LL*two[i-1]%mod;
	FOR(i,0,n) FOR(j,0,i) upd(f[i],1LL*g[i][j]*two[(n-i)*j]%mod*erer[n-i]%mod);
	FOR(i,0,n)
	{
		if (i&1) upd(ans,(mod-1LL*C(n,i)*f[i]%mod)%mod);
		else upd(ans,1LL*C(n,i)*f[i]%mod);
	}
	printf("%d\n",ans);
	return 0;
}