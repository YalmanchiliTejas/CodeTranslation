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

const int MAXN=50;

int n;
ll a[MAXN];

bool ok(ll K) {
	ll need=0;
	REP(i,n) {
		// a[i]-x*N+(K-x)<=N-1 -> x>=(a[i]+K-(N-1))/(N+1)
		ll x=(a[i]+K-(n-1)+n)/(n+1);
		need+=x;
	}
	return need<=K;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%lld",&a[i]);
	ll ret=LLONG_MAX;
	REPE(off,n) {
		ll l=-1,h=(ll)100000001*100000000;
		while(l+1<h) { 
			ll m=l+(h-l)/2; 
			if(ok(m*(n+1)+off)) h=m; else l=m;
		}
		ll cur=h*(n+1)+off;
		//printf("%d: %lld\n",off,cur);
		ret=min(ret,cur);
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}
