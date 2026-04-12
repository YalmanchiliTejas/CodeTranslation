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

const int MAXH=8;
const int MAXW=8;

int h,w;
char g[MAXH][MAXW+1];

bool ok() {
	int x=0,y=0;
	while(true) {
		if(g[x][y]!='#') return false; else g[x][y]='@';
		if(x==h-1&&y==w-1) break;
		if(x+1<h&&g[x+1][y]=='#') { ++x; continue; }
		if(y+1<w&&g[x][y+1]=='#') { ++y; continue; }
		return false;
	}
	REP(x,h) REP(y,w) if(g[x][y]=='#') return false;
	return true;
}

void run() {
	scanf("%d%d",&h,&w); REP(x,h) scanf("%s",g[x]);
	printf("%s\n",ok()?"Possible":"Impossible");
}

int main() {
	run();
	return 0;
}
