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

const int MAXN = 200;
const int MAXRET = 100000;

int n;
int p[MAXN];

int ret[MAXRET], nret;
void addret(int x) { assert(nret < MAXRET); ret[nret++] = x; }

void run() {
	scanf("%d", &n); REP(i, n) scanf("%d", &p[i]);
	//n = 200; REP(i, n) p[i] = i; random_shuffle(p, p + n);

	int off = 0;
	for (int now = n - 1; now >= 0; --now) {
		REP(i, 1) {
			addret(1); off = (off + 1) % n;
			//printf("p:"); REP(j, n) printf(" %d", p[j]); printf(" (off=%d)\n", off);
		}
		REP(i, now) {
			int a = off, b = (off + n - 1) % n;
			if (p[a] < p[b]) { addret(n - 1); swap(p[a], p[b]); }
			addret(1); off = (off + 1) % n;
			//printf("p:"); REP(j, n) printf(" %d", p[j]); printf(" (off=%d)\n", off);
		}
		REP(i, n - now - 1) {
			addret(1); off = (off + 1) % n;
			//printf("p:"); REP(j, n) printf(" %d", p[j]); printf(" (off=%d)\n", off);
		}
	}
	//printf("p:"); REP(j, n) printf(" %d", p[j]); printf(" (off=%d,nret=%d)\n", off,nret);
	printf("%d\n", nret); REP(i, nret) printf("%d\n", ret[i]);

}

int main() {
	run();
	return 0;
}
