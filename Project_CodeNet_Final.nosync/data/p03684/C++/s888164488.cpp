#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <queue>
#include <cstdlib>
using namespace std;
#define pii pair<int,int>
#define ft first
#define sc second
#define INF 1000000006
#define INFLL 4000000000000000006ll
#define vi vector<int>
#define pb push_back
#define eb emplace_back
#define gc getchar_unlocked
#define getInt(x) while((_c=gc())<'0'); x=_c-'0'; while((_c=gc())>='0') x=x*10+_c-'0';
#define LL long long
#define DB double
#define PARAM int id, int l, int r
#define _L id*2,l,mid
#define _R id*2+1,mid+1,r
#define PREP int mid = (l+r)/2
#define MEMSET(x,y) memset(x,y,sizeof(x));
#define MOD 1000000007

int n;
vector<pii> ax, ay;
vector<pair<int,pii> > dx, dy;
int par[100005];

int parOf(int x){
	if(par[x]==x) return x;
	return par[x] = parOf(par[x]);
}

int main(){
	char _c; getInt(n);
	for(int i = 0; i < n; i++ ){
		par[i] = i;
		int x, y; getInt(x) getInt(y)
		ax.eb(x,i);
		ay.eb(y,i);
	}
	sort(ax.begin(),ax.end());
	sort(ay.begin(),ay.end());
	for(int i = 1; i < (int)ax.size(); i++ ){
		dx.pb({ax[i].ft-ax[i-1].ft,{ax[i-1].sc,ax[i].sc}});
	}
	for(int i = 1; i < (int)ay.size(); i++ ){
		dy.pb({ay[i].ft-ay[i-1].ft,{ay[i-1].sc,ay[i].sc}});
	}
	sort(dx.begin(),dx.end());
	sort(dy.begin(),dy.end());
	dx.pb({INF,{0,0}});
	dy.pb({INF,{0,0}});
	int px = 0, py = 0;
	LL res = 0;
	while(px<dx.size()-1 || py<dy.size()-1){
		pii comb; int diff;
		if(dx[px].ft < dy[py].ft){
			comb = dx[px].sc; diff = dx[px].ft; px++;
		}
		else comb = dy[py].sc, diff = dy[py].ft, py++;
		int u = parOf(comb.ft);
		int v = parOf(comb.sc);
		if(u==v) continue;
		par[v] = u;
		res += diff;
	}
	printf("%lld\n",res);
	return 0;
}
