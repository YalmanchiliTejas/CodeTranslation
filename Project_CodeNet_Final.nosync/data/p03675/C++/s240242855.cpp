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

const int MAXN=200000;

int n;
int a[MAXN];

int dir; // 0=from end of c to start of c to start of b to end of b, 1=opposite
int b[MAXN],nb;
int c[MAXN],nc;
int ret[MAXN],nret;


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	nb=nc=dir=0;
	REP(i,n) {
		if(dir==0) b[nb++]=a[i]; else c[nc++]=a[i]; dir=1-dir;
	}
	nret=0;
	if(dir==0) { for(int i=nc-1;i>=0;--i) ret[nret++]=c[i]; REP(i,nb) ret[nret++]=b[i]; }
	if(dir==1) { for(int i=nb-1;i>=0;--i) ret[nret++]=b[i]; REP(i,nc) ret[nret++]=c[i]; }
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}
