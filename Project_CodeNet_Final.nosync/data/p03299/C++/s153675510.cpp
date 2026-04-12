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

const int MAXN=100;
const int MAXZ=MAXN;
const int MOD=1000000007;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int n;
int h[MAXN];

int z[MAXN],nz;

int dpalt[MAXN];
int dpdup[MAXN][MAXZ];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&h[i]);

	nz=0; REP(i,n) z[nz++]=h[i]; sort(z,z+nz); nz=unique(z,z+nz)-z;

	memset(dpalt,0,sizeof(dpalt)); memset(dpdup,0,sizeof(dpdup));
	REP(i,n) {
		int cz=lower_bound(z,z+nz,h[i])-z;
		if(i==0) {
			inc(dpalt[i],2);
			REPE(nj,cz) {
				int here=z[nj]-(nj==0?0:z[nj-1]),below=nj==0?0:z[nj-1],above=h[i]-z[nj];
				int ways=below==0?(ll)(pw(2,here)+MOD-2)*pw(2,above)%MOD:(ll)2*(pw(2,here)+MOD-1)*pw(2,above)%MOD;
				inc(dpdup[i][nj],ways);
			}
		} else {
			int pz=lower_bound(z,z+nz,h[i-1])-z;
			if(dpalt[i-1]!=0) {
				inc(dpalt[i],(ll)2*dpalt[i-1]%MOD);
				FORE(nj,pz+1,cz) {
					int here=z[nj]-z[nj-1],below=z[nj-1]-h[i-1],above=h[i]-z[nj];
					int ways=(ll)2*(pw(2,here)+MOD-1)*pw(2,above)%MOD;
					inc(dpdup[i][nj],(ll)dpalt[i-1]*ways%MOD);
				}
			}
			REP(j,nz) if(dpdup[i-1][j]!=0) {
				if(cz<j) {
					inc(dpalt[i],(ll)2*dpdup[i-1][j]%MOD);
				} else {
					int above=cz<=pz?0:h[i]-h[i-1];
					int ways=pw(2,above);
					inc(dpdup[i][j],(ll)dpdup[i-1][j]*ways%MOD);
				}
			}
		}
	}
	int ret=0;
	inc(ret,dpalt[n-1]);
	REP(j,nz) inc(ret,dpdup[n-1][j]);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
