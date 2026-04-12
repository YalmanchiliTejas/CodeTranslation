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

const int MAXN=3000;

int n,MOD;

int C[MAXN+1][MAXN+1];


int p2[MAXN+1];
int p2p[MAXN+1];
int S[MAXN+1][MAXN+1]; // stirling number of second kind


int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }


void run() {
	scanf("%d%d",&n,&MOD);
	
	REPE(i,n) { C[i][0]=C[i][i]=1; FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD; }
	p2[0]=1; FORE(i,1,n) p2[i]=(ll)p2[i-1]*2%MOD;
	p2p[0]=1; FORE(i,1,n) p2p[i]=(ll)p2p[i-1]*2%(MOD-1);
	memset(S,0,sizeof(S)); S[0][0]=1; FORE(i,1,n) FORE(j,1,n) S[i][j]=((ll)j*S[i-1][j]+S[i-1][j-1])%MOD;
	//REPE(i,n) { printf("S%d:",i); REPE(j,n) printf(" %d",S[i][j]); puts(""); }

	int ret=0;
	REPE(nerr,n) {
		int nok=n-nerr,cur=0,mlt=1;
		REPE(nextra,nerr) {
			// no zero
			cur=(cur+(ll)S[nerr][nextra]*mlt)%MOD;
			// at least one zero
			cur=(cur+(ll)S[nerr][nextra+1]*mlt%MOD*(nextra+1))%MOD;
			mlt=(ll)mlt*p2[nok]%MOD;
		}
		cur=(ll)cur*C[n][nerr]%MOD*pw(2,p2p[nok])%MOD;
		//printf("nerr=%d: %d\n",nerr,cur);
		if(nerr%2==0) ret=(ret+cur)%MOD; else ret=(ret+MOD-cur)%MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
