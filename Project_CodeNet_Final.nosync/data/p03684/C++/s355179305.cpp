//marico el que lo lea
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

#define FOR(i,f,t) for(int i=f; i<(int)t; i++)
#define FORR(i,f,t) for(int i=f; i>(int)t; i--)
#define pb push_back
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ms2(obj, val, sz) memset(obj, val, sizeof(obj[0])*sz)
#define ri(x) scanf("%d",&x)
#define rl(x) scanf("%lld",&x)
#define rii(x,y) ri(x), ri(y)
#define rll(x,y) rl(x), rl(y)

#define fst first
#define snd second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;

const int MAXN = 1e5+5;

int N;
pair<pair<ll, ll>, int> p[MAXN];
vector<pair<ll, ii> > E;

int rep[MAXN];
int find(int v){
	if(rep[v] == v) return v;
	return rep[v] = find(rep[v]);
}

ll kruskal(){
	sort(E.begin(), E.end());
	FOR(i,0,N) rep[i]=i;
	ll ret = 0;
	FOR(i,0,E.size()){
		int v = E[i].snd.fst, u = E[i].snd.snd;
		ll c = E[i].fst;
		v = find(v); u = find(u);
		if(v!=u){
			rep[u] = v;
			ret += c;
		}
	}
	return ret;
}

int main(){
	ri(N);
	FOR(i,0,N) rll(p[i].fst.fst, p[i].fst.snd);
	FOR(i,0,N) p[i].snd = i;
	sort(p, p+N);
	FOR(i,0,N-1){
		E.pb({p[i+1].fst.fst - p[i].fst.fst, {p[i].snd, p[i+1].snd}});
	}
	FOR(i,0,N) swap(p[i].fst.fst, p[i].fst.snd);
	sort(p, p+N);
	FOR(i,0,N-1){
		E.pb({p[i+1].fst.fst - p[i].fst.fst, {p[i].snd, p[i+1].snd}});
	}
	printf("%lld\n",kruskal());
}