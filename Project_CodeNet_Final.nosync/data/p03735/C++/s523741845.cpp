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
int v[2*MAXN];
pair<int,int> p[2*MAXN];
int cnt[MAXN];

ll solve() {
	int mx=v[0],mn=v[0],mxi=0,mni=0; FOR(i,1,2*n) { if(v[i]>mx) mx=v[i],mxi=i; if(v[i]<mn) mn=v[i],mni=i; }
	if(mn==mx) return 0;
	ll ret=LLONG_MAX;
	{
		int maxr=mx,minb=mn,minr=mx,maxb=mn;
		REP(i,n) { int b=min(v[2*i],v[2*i+1]),r=v[2*i]+v[2*i+1]-b; if(b>maxb) maxb=b; if(r<minr) minr=r; }
		ll cur=(ll)(maxr-minr)*(maxb-minb); if(cur<ret) ret=cur;
	}
	if(mxi!=(mni^1)) {
		int maxr=mx,minr=mn;
		REP(i,2*n) p[i]=MP(v[i],i/2); sort(p,p+2*n);
		memset(cnt,0,sizeof(cnt));
		int l=0,r=0,have=0;
		while(true) {
			if(have<n) {
				if(r>=2*n) break;
				if(cnt[p[r++].second]++==0) ++have;
			} else {
				int minb=p[l].first,maxb=p[r-1].first;
				ll cur=(ll)(maxr-minr)*(maxb-minb); if(cur<ret) ret=cur;
				if(--cnt[p[l++].second]==0) --have;
			}
		}
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,2*n) scanf("%d",&v[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}
