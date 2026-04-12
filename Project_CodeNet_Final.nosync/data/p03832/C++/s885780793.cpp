#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=1000;
const int MOD=1000000007;

int n,mnsz,mxsz,mncnt,mxcnt;

int dp[MAXN+1][MAXN+2];
int C[MAXN+1][MAXN+1];
int F[MAXN+1];
int inv[MAXN+1];
int Finv[MAXN+1];
int Finvp[MAXN+1][MAXN+1];

void run() {
	scanf("%d%d%d%d%d",&n,&mnsz,&mxsz,&mncnt,&mxcnt);
	
	REPE(i,n) { C[i][0]=C[i][i]=1; FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD; }
	F[0]=1; FORE(i,1,n) F[i]=(ll)F[i-1]*i%MOD;
	inv[1]=1; FORE(i,2,n) inv[i]=(ll)(MOD-(MOD/i))*inv[MOD%i]%MOD;
	Finv[0]=1; FORE(i,1,n) Finv[i]=(ll)Finv[i-1]*inv[i]%MOD;
	REPE(i,n) Finvp[i][0]=1; REPE(i,n) FORE(j,1,n) Finvp[i][j]=(ll)Finvp[i][j-1]*Finv[i]%MOD;
	
	REPE(i,n) dp[i][mxsz+1]=i==0?1:0;
	for(int sz=mxsz;sz>=0;--sz) REPE(i,n) {
		dp[i][sz]=dp[i][sz+1];
		if(sz>=mnsz) for(int cnt=mncnt;cnt<=mxcnt&&cnt*sz<=i;++cnt) {
			dp[i][sz]=(dp[i][sz]+(ll)C[i][cnt*sz]*F[cnt*sz]%MOD*Finvp[sz][cnt]%MOD*Finv[cnt]%MOD*dp[i-cnt*sz][sz+1])%MOD;
		}
	}
	printf("%d\n",dp[n][0]);
}

int main() {
	run();
	return 0;
}
