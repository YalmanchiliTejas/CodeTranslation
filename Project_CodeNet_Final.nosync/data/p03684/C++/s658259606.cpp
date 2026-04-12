#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
const ll mod = ll(1e9) + 7;
const int INF = int(1e9);

const int MAX_V = 100000;
const int MAX_E = 300000;

int par[MAX_V]; //parents
int rnk[MAX_V]; //depth of the tree
struct edge { int u, v; ll cost; };
edge es[MAX_E];
int V, E;//node,edge

bool comp(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}

//initialize with n elements
void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rnk[i] = 0;
	}
}
//find a root of the tree
int find(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}
//merge the sets contains x,y
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;

	if (rnk[x] < rnk[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rnk[x] == rnk[y])rnk[x]++;
	}
}
//the set contains x and y or not
bool same(int x, int y) {
	return find(x) == find(y);
}

ll kruskal() {
	sort(es, es + E, comp);
	init(V);
	int res = 0;
	for (int i = 0; i < E; i++) {
		edge e = es[i];
		if (!same(e.u, e.v)) {
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}

int main() {
	cin.sync_with_stdio(false);
	cin >> V;
	vector<ll>x(V), y(V);
	rep(i, V)cin >> x[i] >> y[i];
	vector<pair<ll, int>>ex, ey;
	rep(i, V) {
		ex.push_back({ x[i],i });
		ey.push_back({ y[i],i });
	}
	sort(ex.begin(), ex.end());
	sort(ey.begin(), ey.end());
	E = 0;
	reps(i,1, V) {
		es[E].u = ex[i].second;
		es[E].v = ex[i-1].second;
		es[E].cost = ex[i].first - ex[i - 1].first;
		E++;
		es[E].u = ey[i].second;
		es[E].v = ey[i - 1].second;
		es[E].cost = ey[i].first - ey[i - 1].first;
		E++;
	}
	
	cout << kruskal() << endl;





	return 0;
}