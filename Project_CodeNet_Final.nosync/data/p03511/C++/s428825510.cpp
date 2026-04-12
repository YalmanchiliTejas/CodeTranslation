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

const int MAXLEN = 200000;

int want;
char a[MAXLEN + 1]; int alen;
char b[MAXLEN + 1]; int blen;


char ret1[MAXLEN + 1];
char ret2[MAXLEN + 1];

// x*a+y*b=g
int egcd(int a, int b, int &x, int &y) {
	if (b == 0) { x = 1, y = 0; return a; }
	int g = egcd(b, a%b, y, x); y -= x*(a / b); return g;
}

void build(char *res, ll na, char *a, int alen, ll nb, char *b, int blen,int cmp) {
	if (cmp > 0) { swap(na, nb); swap(a, b); swap(alen, blen); cmp = -cmp; }
	REP(i, na) REP(j, alen) res[i*alen + j] = a[j];
	REP(i, nb) REP(j, blen) res[na*alen + i*blen + j] = b[j];
	res[na*alen + nb*blen] = '\0';
}

void run() {
	scanf("%d%s%s", &want, a, b); alen = strlen(a), blen = strlen(b);
	int gx, gy, g = egcd(alen, blen, gx, gy); // gx*alen+gy*blen=g
	assert(want%g == 0);
	ll x = (ll)gx*(want / g), y = (ll)gy*(want / g); // x*alen+y*blen=want
	ll period = (ll)alen*blen / g;
	if (x < 0) { int tmp = blen / g; ll t = (-x + tmp - 1) / tmp; x += t*tmp; y -= t*(alen / g); } // make x>=0
	if (y < 0) { int tmp = alen / g; ll t = (-y + tmp - 1) / tmp; y += t*tmp; x -= t*(blen / g); } // make y>=0
	assert(x >= 0 && y >= 0);

	int cmp = 0; // -1 -> ab<ba, +1 -> ab>ba
	REP(i, alen + blen) { char p = i < alen ? a[i] : b[i - alen], q = i < blen ? b[i] : a[i - blen]; if (p != q) { cmp = p < q ? -1 : +1; break; } }

	{ int tmp = blen / g; ll t = x / tmp; x -= t*tmp; y += t*(alen / g); } // minimize x (s.t. x>=0)
	build(ret1, x, a, alen, y, b, blen, cmp);
	{ int tmp = alen / g; ll t = y / tmp; y -= t*tmp; x += t*(blen / g); } // minimize y (s.t. y>=0)
	build(ret2, x, a, alen, y, b, blen, cmp);

	int retcmp = 0;
	REP(i, want) if (ret1[i] != ret2[i]) { retcmp = ret1[i] < ret2[i] ? -1 : +1; break; }
	printf("%s\n", retcmp <= 0 ? ret1 : ret2);
}

int main() {
	run();
	return 0;
}
