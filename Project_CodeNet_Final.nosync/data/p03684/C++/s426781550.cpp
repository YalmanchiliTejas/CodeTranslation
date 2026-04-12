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

const int MAXN=100000;

int n;
int x[MAXN],y[MAXN];

pair<int,int> ox[MAXN];
pair<int,int> oy[MAXN];
int xind[MAXN],yind[MAXN];

bool done[MAXN];
ll d[MAXN];
priority_queue<pair<ll,int> > q;

ll solve() {
	REP(i,n) ox[i]=MP(x[i],i); sort(ox,ox+n); REP(i,n) xind[ox[i].second]=i;
	REP(i,n) oy[i]=MP(y[i],i); sort(oy,oy+n); REP(i,n) yind[oy[i].second]=i;
	REP(i,n) d[i]=LLONG_MAX,done[i]=false; q=priority_queue<pair<ll,int> >();
	d[0]=0,q.push(MP(-d[0],0));
	while(!q.empty()) {
		ll dat=-q.top().first; int at=q.top().second; q.pop();
		if(dat>d[at]) continue; else done[at]=true;
		for(int dx=-1;dx<=+1;dx+=2) {
			int idx=xind[at]+dx; if(idx<0||idx>=n) continue;
			int to=ox[idx].second;
			ll dto=min(abs(x[at]-x[to]),abs(y[at]-y[to]));
			if(!done[to]&&dto<d[to]) {
				//printf("%d->%d = %lld (x)\n",at,to,dto);
				d[to]=dto,q.push(MP(-d[to],to));
			}
		}
		for(int dy=-1;dy<=+1;dy+=2) {
			int idx=yind[at]+dy; if(idx<0||idx>=n) continue;
			int to=oy[idx].second;
			ll dto=min(abs(x[at]-x[to]),abs(y[at]-y[to]));
			if(!done[to]&&dto<d[to]) {
				//printf("%d->%d = %lld (y)\n",at,to,dto);
				d[to]=dto,q.push(MP(-d[to],to));
			}
		}
	}
	ll ret=0; REP(i,n) ret+=d[i]; return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&x[i],&y[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}
