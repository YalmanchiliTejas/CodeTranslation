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

const int MAXN=200;
const int MAXM=MAXN-1;

int n,nq;
int locghead[MAXN],locgnxt[2*MAXM],locgto[2*MAXM];
bool local=false;

typedef struct QLOC {
	bool alive[MAXN];
	int state[MAXN];
	int q[MAXN],qhead,qtail,d[MAXN];
	int calc() {
		int ret=0;
		REP(i,n) state[i]=0;
		REP(i,n) if(state[i]==0&&alive[i]) {
			qhead=qtail=0; q[qhead++]=i,d[i]=0,state[i]=1;
			while(qtail<qhead) { int at=q[qtail++]; for(int x=locghead[at];x!=-1;x=locgnxt[x]) { int to=locgto[x]; if(!alive[to]||state[to]==state[at]) continue; q[qhead++]=to,d[to]=d[at]+1,state[to]=state[at]; } }
			int j=q[qhead-1];
			qhead=qtail=0; q[qhead++]=j,d[j]=0,state[j]=2;
			while(qtail<qhead) { int at=q[qtail++]; for(int x=locghead[at];x!=-1;x=locgnxt[x]) { int to=locgto[x]; if(!alive[to]||state[to]==state[at]) continue; q[qhead++]=to,d[to]=d[at]+1,state[to]=state[at]; } }
			int k=q[qhead-1],diam=d[k]; ret+=diam*diam;
		}
		return ret;
	}
} QLOC;
QLOC qloc;

bool inq[MAXN];
int query(const vector<int> &now) {
	++nq; REP(i,n) inq[i]=false; REPSZ(i,now) inq[now[i]]=true;
	if(local) {
		REP(i,n) qloc.alive[i]=inq[i]; return qloc.calc();
	} else {
		printf("? "); REP(i,n) printf("%d",inq[i]?1:0); puts(""); fflush(stdout);
		int ret; scanf("%d",&ret); return ret;
	}
	assert(false); return false;
}

bool can[MAXN][MAXN];
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM]; int m;


pair<int,int> ret[MAXM]; int nret;
void found(int a,int b) {
	//printf("found(%d,%d)\n",a,b);
	ret[nret++]=MP(min(a,b),max(a,b)); can[a][b]=can[b][a]=false;
	gnxt[2*m+0]=ghead[a],ghead[a]=2*m+0,gto[2*m+0]=b;
	gnxt[2*m+1]=ghead[b],ghead[b]=2*m+1,gto[2*m+1]=a;
	++m;
}
void clear(const vector<int> &now) {
	REPSZ(i,now) FORSZ(j,i+1,now) { int a=now[i],b=now[j]; can[a][b]=can[b][a]=false; }
}
int q[MAXN],qhead,qtail;
int col[MAXN];
void colorize() {
	REP(i,n) col[i]=-1; 
	REP(i,n) if(col[i]==-1) {
		qhead=qtail=0; col[i]=0; q[qhead++]=i;
		while(qtail<qhead) { int at=q[qtail++]; for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(col[to]!=-1) continue; col[to]=1-col[at]; q[qhead++]=to; } }
		REP(j,qhead) FOR(k,j+1,qhead) { int a=q[j],b=q[k]; can[a][b]=can[b][a]=false; }
	}
}

void solve() {
	nret=m=nq=0; REP(i,n) REP(j,n) can[i][j]=i!=j; REP(i,n) ghead[i]=-1;
	while(true) {
		colorize();
		int i=-1; int icnt;
		REP(ii,n) { int cnt=0; REP(j,n) if(can[ii][j]) ++cnt; if(cnt>0&&(i==-1||cnt>icnt)) i=ii,icnt=cnt; }
		if(i==-1) break;
		//REP(j,n) printf("%d ",col[j]); puts("");
		int curcol=-1; REP(j,n) if(can[i][j]) { curcol=col[j]; break; } assert(curcol!=-1);
		vector<int> opt; REP(j,n) if(can[i][j]&&col[j]==curcol) opt.PB(j);
		//printf("checking %d with",i); REPSZ(j,opt) printf(" %d",opt[j]); puts("");
		vector<int> one;
		{ vector<int> now=opt; now.PB(i); int cur=query(now); if(cur==0) { clear(now); continue; } else if(cur==1&&SZ(now)>SZ(one)) one=now; }
		int lst;
		{
			int l=-1,r=SZ(opt)-1;
			while(l+1<r) {
				int m=l+(r-l)/2;
				vector<int> now; REPE(j,m) now.PB(opt[j]); now.PB(i); int cur=query(now); if(cur==0) { clear(now); l=m; } else { r=m; if(cur==1&&SZ(now)>SZ(one)) one=now; }
			}
			lst=r;
		}
		{ vector<int> now; now.PB(i); now.PB(opt[lst]); if(lst>0&&!query(now)) clear(now); else { found(i,opt[lst]); clear(one); continue; } }
		int fst;
		{
			int l=0,r=lst;
			while(l+1<r) {
				int m=l+(r-l)/2;
				vector<int> now; FORE(j,m,lst) now.PB(opt[j]); int cur=query(now); if(cur==0) { clear(now); r=m; } else { l=m; if(cur==1&&SZ(now)>SZ(one)) one=now; }
			}
			fst=l;
		}
		found(opt[fst],opt[lst]); clear(one);
	}
	sort(ret,ret+nret);
}

void run() {
	scanf("%d",&n);
	solve();
	printf("!"); REP(i,nret) printf(" (%d,%d)",ret[i].first,ret[i].second); puts(""); fflush(stdout);
}

int locpar[MAXN];
int locperm[MAXN];
pair<int,int> want[MAXM]; int nwant;
bool check() {
	nwant=0; REP(i,n) for(int x=locghead[i];x!=-1;x=locgnxt[x]) if(i<locgto[x]) want[nwant++]=MP(i,locgto[x]); sort(want,want+nwant);
	if(nwant!=nret) return false; REP(i,nret) if(ret[i]!=want[i]) return false; return true;
}
int num=0,den=0;
bool verify() {
	if(check()) { num+=nq,den++; printf("%.0lf ",1.0*num/den); return true; }
	printf("have:"); REP(i,nret) printf(" %d-%d",ret[i].first,ret[i].second); puts("");
	printf("want:"); REP(i,n) for(int x=locghead[i];x!=-1;x=locgnxt[x]) if(i<locgto[x]) printf(" %d-%d",i,locgto[x]); puts("");
	return false;
}
void stress() {
	while(true) {
		local=true;
		n=200;
		locpar[0]=-1; FOR(i,1,n) locpar[i]=rand()%i;
		REP(i,n) locperm[i]=i; REP(i,n) { int j=i+rand()%(n-i); swap(locperm[i],locperm[j]); }
		REP(i,n) locghead[i]=-1;
		REP(i,n-1) {
			int a=locperm[i+1],b=locperm[locpar[i+1]]; 
			locgnxt[2*i+0]=locghead[a],locghead[a]=2*i+0,locgto[2*i+0]=b;
			locgnxt[2*i+1]=locghead[b],locghead[b]=2*i+1,locgto[2*i+1]=a;
		}
		solve();
		if(!verify()) break;
	}
}
void debug() {
	local=true;
	scanf("%d",&n);
	REP(i,n) locghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b);
		locgnxt[2*i+0]=locghead[a],locghead[a]=2*i+0,locgto[2*i+0]=b;
		locgnxt[2*i+1]=locghead[b],locghead[b]=2*i+1,locgto[2*i+1]=a;
	}
	solve();
	verify();
}

int main() {
	//stress();
	//debug();
	run();
	return 0;
}
