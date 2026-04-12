#include <stdio.h>
#include <string.h>
#include <algorithm>
#define rep(i,st,ed) for (register int i=st;i<=ed;++i)

typedef long long LL;
const int N=3005;

LL f[N],s[N][N];
LL fac[N],ny[N];

LL ksm(LL x,LL dep,int MOD) {
	LL res=1;
	for (;dep;dep>>=1) {
		(dep&1)?(res=res*x%MOD):0;
		x=x*x%MOD;
	}
	return res;
}

LL C(int n,int m,int MOD) {
	return fac[n]*ny[m]%MOD*ny[n-m]%MOD;
}

void upd(LL &x,int MOD) {
	(x>=MOD)?(x-=MOD):0;
}

int main(void) {
	int n,MOD; scanf("%d%d",&n,&MOD);
	fac[0]=1; rep(i,1,N-1) fac[i]=fac[i-1]*i%MOD;
	ny[0]=ny[1]=1; rep(i,2,N-1) ny[i]=ny[MOD%i]*(MOD-MOD/i)%MOD;
	rep(i,1,N-1) ny[i]=ny[i-1]*ny[i]%MOD;
	s[0][0]=1;
	rep(i,1,n) {
		s[i][0]=1;
		rep(j,1,i) {
			s[i][j]=s[i-1][j-1]+s[i-1][j]*(j+1)%MOD;
			upd(s[i][j],MOD);
		}
	}
	LL ans=0;
	rep(i,0,n) {
		rep(j,0,i) upd(f[i]+=s[i][j]*ksm(2,1LL*(n-i)*j%(MOD-1),MOD)%MOD,MOD);
		f[i]=f[i]*ksm(2,ksm(2,n-i,MOD-1),MOD)%MOD;
		if (i&1) ans+=MOD-C(n,i,MOD)*f[i]%MOD;
		else ans+=C(n,i,MOD)*f[i]%MOD;
		upd(ans,MOD);
	}
	printf("%lld\n", ans);
	return 0;
}