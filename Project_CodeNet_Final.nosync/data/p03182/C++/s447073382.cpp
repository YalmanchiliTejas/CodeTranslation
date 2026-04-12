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

const int MAXLEN=200000;
const int MAXZ=200000;
const int MAXS=(MAXLEN+1)*4;
struct Z { int l,r,val; };

int len,nz;
Z z[MAXZ];

ll dp[MAXLEN];

ll sval[MAXS],slazy[MAXS];
void sapply(int x,ll BY) { sval[x]+=BY; slazy[x]+=BY; }
void spull(int x) { sval[x]=slazy[x]+max(sval[2*x+1],sval[2*x+2]); }
void spush(int x) { if(slazy[x]!=0) sapply(2*x+1,slazy[x]),sapply(2*x+2,slazy[x]),slazy[x]=0; }
void sinit(int x,int l,int r) {
	slazy[x]=0;
	if(l==r) {
		sval[x]=0;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		spull(x);
	}
}
void smod(int x,int l,int r,int L,int R,ll BY) {
	//if(x==0) printf("smod(%d,%d..%d,%d..%d,%lld)\n",x,l,r,L,R,BY);
	if(L<=l&&r<=R) {
		sapply(x,BY);
	} else {
		int m=l+(r-l)/2; spush(x);
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
		spull(x);
	}
}
ll sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return sval[x];
	} else {
		int m=l+(r-l)/2; spush(x);
		ll ret=LLONG_MIN;
		if(L<=m) ret=max(ret,sget(2*x+1,l,m,L,R));
		if(m+1<=R) ret=max(ret,sget(2*x+2,m+1,r,L,R));
		spull(x);
		return ret;
	}
}

vector<int> startat[MAXLEN];
vector<int> endat[MAXLEN];

ll solve() {
	REP(i,len) startat[i].clear(),endat[i].clear();
	REP(i,nz) startat[z[i].l].PB(i),endat[z[i].r].PB(i);
	sinit(0,0,len);
	REP(i,len) {
		REPSZ(j,startat[i]) { int zi=startat[i][j]; smod(0,0,len,0,z[zi].l,+z[zi].val); }
		dp[i]=sget(0,0,len,0,i);
		//printf("dp[%d]=%lld\n",i,dp[i]);
		smod(0,0,len,i+1,i+1,dp[i]);
		REPSZ(j,endat[i]) { int zi=endat[i][j]; smod(0,0,len,0,z[zi].l,-z[zi].val); }
	}
	ll ret=0; REP(i,len) ret=max(ret,dp[i]); return ret;
}

void run() {
	scanf("%d%d",&len,&nz);
	REP(i,nz) scanf("%d%d%d",&z[i].l,&z[i].r,&z[i].val),--z[i].l,--z[i].r;
	printf("%lld\n",solve());

}

int main() {
	run();
	return 0;
}
