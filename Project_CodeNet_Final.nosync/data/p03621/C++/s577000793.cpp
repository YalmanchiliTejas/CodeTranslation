#include <bits/stdc++.h>
using namespace std;
#define MAXN 32768
#define MOD 998244353
#define rint register int
#define gc() getchar()
inline int read(int r=0,int s=0,int c=gc()){for(;c<48||c>57;s=c,c=gc());for(;c>=48&&c<=57;(r*=10)+=c-48,c=gc());return s^'-'?r:-r;}
inline int fxp(int s, int n=MOD-2){int a=1; for(; n; n&1 ? a = 1ll*a*s%MOD : 0, s = 1ll*s*s%MOD, n >>= 1); return a;}
int A[MAXN+5], B[MAXN+5], Rv[MAXN+5], fac[MAXN+5], efac[MAXN+5], Gw[40], m, n, x, y, Ans; char S[MAXN+5], T[MAXN+5];
inline void RV(int n){for(rint i = 1, l = ~-ilogb(n); i < n; Rv[i] = Rv[i>>1]>>1|(i&1)<<l, i++);}
void NTT(int R[], int n, int z)
{
	static int root, per, t; for(rint i = 0; i < n; i<Rv[i]?swap(R[i],R[Rv[i]]),0:0, i++);
	for(rint d = 0, i, j, m; (m=1<<d) < n; d++) for(i = 0, per = Gw[d]; i < n; i += m<<1) for(j = 0, root = 1; j < m; j++)
		t = 1ll*R[i+j+m]*root%MOD, (R[i+j+m]=R[i+j]-t)<0?R[i+j+m]+=MOD:0, (R[i+j]+=t)<MOD?:R[i+j]-=MOD, root = 1ll*root*per%MOD;
	if(z<0){t = fxp(n); for(rint i = 0; i < n; R[i] = 1ll*t*R[i]%MOD, i++); reverse(R+1,R+n);}
}
int main()
{
	for(rint i = 0; i < 20; Gw[i] = fxp(3,~-MOD/(1<<-~i)), i++); scanf("%s%s",S+1,T+1), m = strlen(S+1);
	for(rint i = 1; i <= m; x += S[i]^'0'&&T[i]^'0', y += S[i]^'0'&&T[i]^'1', i++); for(n = 1; n <= x; n <<= 1); RV(n<<=1); m = x+y+1;
	for(rint i = fac[0] = 1; i <= m; fac[i] = 1ll*i*fac[i-1]%MOD, i++); efac[m] = fxp(fac[m]); for(rint i = m; i; efac[i-1] = 1ll*i*efac[i]%MOD, i--);
	for(rint i = 0; i <= x; B[i] = efac[i+1], i++); A[0] = 1;
	for(rint i, t = y; t; t >>= 1)
	{
		if(NTT(B,n,1), t&1){NTT(A,n,1); for(i = 0; i < n; A[i] = 1ll*A[i]*B[i]%MOD, i++); NTT(A,n,-1); for(i = x+1; i < n; A[i++] = 0);}
		for(i = 0; i < n; B[i] = 1ll*B[i]*B[i]%MOD, i++); NTT(B,n,-1); for(i = x+1; i < n; B[i++] = 0);
	}	for(rint i = 0; i <= x; (Ans+=A[i])<MOD?:Ans-=MOD, i++); printf("%d\n",1ll*fac[x]*fac[y]%MOD*fac[x+y]%MOD*Ans%MOD); return 0;
}