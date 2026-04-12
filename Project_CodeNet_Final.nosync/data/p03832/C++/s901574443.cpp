#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
#define RF(x) freopen(x,"r",stdin)
#define WF(x) freopen(x,"w",stdout)
typedef long long LL;
using namespace std;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
const LL MOD = 1e9+7;
const int SIZE = 1e6+5;
const LL INF = 1LL<<60;
const double eps = 1e-4;
const double PI=3.1415926535897932;

LL dp[1009][1009];
LL f[1009],inv[1009];

LL expo(LL a,LL b){
	if(b==0)return 1;
	LL h=expo(a,b/2);
	h=(h*h)%MOD;
	if(b%2)h=(h*a)%MOD;
	return h;
}

LL nPk(int n,int k){
	return (f[n]*inv[n-k])%MOD;
}

int main(){
	f[0]=1;
	REPP(i,1,1009){
		f[i]=(f[i-1]*i)%MOD;
	}
	REP(i,1009)inv[i]=expo(f[i],MOD-2);
	DRIII(n,a,b);DRII(c,d);
	dp[a-1][0]=1;
	REPP(i,a,b+1){
		REP(j,n+1){
			dp[i][j]=dp[i-1][j];
			REPP(k,c,d+1){
				if(j<k*i)break;
				LL coeff=((nPk(j,k*i)*expo(inv[i],k))%MOD*inv[k])%MOD;
				dp[i][j]=(dp[i][j]+(dp[i-1][j-k*i])*coeff)%MOD;
			}
		}
	}
	/*REPP(i,a-1,b+1){
		REP(j,n+1){
			printf("%lld ",dp[i][j]);
		}puts("");
	}*/
	printf("%lld",dp[b][n]);
}
