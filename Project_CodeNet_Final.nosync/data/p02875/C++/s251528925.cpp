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

const int MAXN=10000000;
const int MOD=998244353;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int n;

int inv[MAXN+1];
int fac[MAXN+1];
int ifac[MAXN+1];
int p2[MAXN+1];

int twoexact[MAXN/2+1];
int oneexact[MAXN/2+1];
int twoatleast[MAXN/2+1];
int oneatleast[MAXN/2+1];

int choose(int n,int k) { if(k<0||k>n) return 0; return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD; }


int solvestupid() {
	int ret=0;
	REPE(x,n/2) REPE(y,n/2) {
		if(x<y) {
			FORE(z,y-x,n/2-x) {
				int cur=choose(n/2,x)*choose(n/2,y)*choose(n/2-x,z)*p2[n/2-y];
				printf("x=%d y=%d z=%d -> %d\n",x,y,z,cur);
				ret+=cur;
			}
		}
		if(y<x) {
			FORE(z,x-y,n/2-y) {
				int cur=choose(n/2,x)*choose(n/2,y)*choose(n/2-y,z)*p2[n/2-x];
				printf("x=%d y=%d z=%d -> %d\n",x,y,z,cur);
				ret+=cur;
			}
		}
		if(x==y) {
			int cur=choose(n/2,x)*choose(n/2,y)*p2[n-x-y];
			printf("x=%d y=%d -> %d\n",x,y,cur);
			ret+=cur;
		}
	}
	return ret;
}

int solve() {
	inv[1]=1; FORE(i,2,n) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,n) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,n) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;
	p2[0]=1; FORE(i,1,n) p2[i]=(ll)p2[i-1]*2%MOD;

	REPE(i,n/2) twoexact[i]=(ll)p2[i]*choose(n/2,i)%MOD;
	REPE(i,n/2) oneexact[i]=(ll)p2[n/2-i]*choose(n/2,i)%MOD;
	for(int i=n/2;i>=0;--i) twoatleast[i]=(twoexact[i]+(i+1<=n/2?twoatleast[i+1]:0))%MOD;
	for(int i=n/2;i>=0;--i) oneatleast[i]=(oneexact[i]+(i+1<=n/2?oneatleast[i+1]:0))%MOD;

	int ret=0;
	REPE(x,n/2) {
		int yzways=(twoatleast[x]+MOD-oneatleast[x])%MOD;
		//printf("%d: %d (%d-%d)\n",x,yzways,twoatleast[x],oneatleast[x]);
		int cur=(ll)yzways*choose(n/2,x)%MOD*p2[n/2-x]%MOD;
		inc(ret,cur);
		inc(ret,cur);
	}
	REPE(x,n/2) {
		int cur=(ll)choose(n/2,x)*choose(n/2,x)%MOD*p2[n-2*x]%MOD;
		inc(ret,cur);
	}
	return ret;
}


void run() {
	scanf("%d",&n);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
