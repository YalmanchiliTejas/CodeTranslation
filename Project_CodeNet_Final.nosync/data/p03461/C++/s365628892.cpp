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

const int MAXXLIM = 10;
const int MAXYLIM = 10;

int xlim, ylim;
int d[MAXXLIM + 1][MAXYLIM + 1];

bool ok(int nx, int ny, int cnst) {
	FORE(x, 1, xlim) FORE(y, 1, ylim) {
		int cur = nx*x + ny*y + cnst;
		if (cur < d[x][y]) return false;
	}
	return true;
}

pair<int, int> search(int cx, int cy) {
	for (int nx = 0; nx*cx <= d[cx][cy]; ++nx) for (int ny = 0; nx*cx + ny*cy <= d[cx][cy]; ++ny) {
		int cnst = d[cx][cy] - nx*cx - ny*cy;
		if (ok(nx, ny, cnst)) return MP(nx, ny);
	}
	return MP(-1, -1);
}

map<pair<int, int>, int> e;

void run() {
	scanf("%d%d", &xlim, &ylim); FORE(cx, 1, xlim) FORE(cy, 1, ylim) scanf("%d", &d[cx][cy]);
	FORE(cx, 1, xlim) FORE(cy, 1, ylim) {
		pair<int, int> p = search(cx, cy);
		if (p.first == -1 || p.second == -1) { printf("Impossible\n"); return; }
		int cnst = d[cx][cy] - cx*p.first - cy*p.second;
		if (e.count(p)) assert(e[p] == cnst); else e[p] = cnst;
	}
	int mxx = 0, mxy = 0; for (auto it = e.begin(); it != e.end(); ++it) { int nx = it->first.first, ny = it->first.second; mxx = max(mxx, nx); mxy = max(mxy, ny); }
	vector<int> xid(mxx + 1), yid(mxy + 1); int nid = 0; REPSZ(i, xid) xid[i] = ++nid; REPSZ(i, yid) yid[i] = ++nid;
	printf("Possible\n");
	printf("%d %d\n", nid, mxx + mxy + SZ(e));
	REP(i, mxx) printf("%d %d X\n", xid[i], xid[i + 1]);
	REP(i, mxy) printf("%d %d Y\n", yid[i + 1], yid[i]);
	for (auto it = e.begin(); it != e.end(); ++it) printf("%d %d %d\n", xid[it->first.first], yid[it->first.second], it->second);
	printf("%d %d\n", xid[0], yid[0]);
}

int main() {
	run();
	return 0;
}
