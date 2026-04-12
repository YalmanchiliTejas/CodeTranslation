#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, P> PP;

struct edge {
	int from,to,cost;
	edge(int f,int t,int c):from(f),to(t),cost(c) {}
};

int n;
map<ll,int> xs,ys;
vector<P> vx,vy;
vector<edge> es;
vector<int> data;

int root(int);

void UnionFind() {
	data.resize(n);
	REP(i,n) data[i]=-1;
}

bool unite(int x,int y) {
	x=root(x),y=root(y);
	if(x!=y) {
		if(data[y]<data[x]) swap(x,y);
		data[x]+=data[y],data[y]=x;
	}
	return x!=y;
}

bool same(int x,int y) {
	return root(x)==root(y);
}

int root(int x) {
	return data[x]<0?x:data[x]=root(data[x]);
}

int size(int x) {
	return -data[root(x)];
}

bool comp(const edge& e1,const edge& e2) {
	return e1.cost<e2.cost;
}

void kruskal() {
	sort(ALL(es),comp);
	UnionFind();
	ll ans=0;
	REP(i,es.size()) {
		edge e=es[i];
		if(!same(e.from,e.to)) {
			unite(e.from,e.to);
			ans+=e.cost;
		}
	}
	cout<<ans<<endl;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>n;
	REP(i,n) {
		ll x,y; cin>>x>>y;
		vx.pb(P(x,i));
		vy.pb(P(y,i));
	}
	sort(ALL(vx));
	sort(ALL(vy));
	REP(i,n-1) {
		es.pb(edge(vx[i].se,vx[i+1].se,abs(vx[i].fi-vx[i+1].fi)));
		es.pb(edge(vy[i].se,vy[i+1].se,abs(vy[i].fi-vy[i+1].fi)));
	}

	kruskal();

	return 0;
}
