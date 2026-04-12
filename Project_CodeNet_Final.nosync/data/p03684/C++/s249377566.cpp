#include <bits/stdc++.h>
using namespace std;

#define pb         push_back

typedef long long ll;
const ll INF = 1000000000000000000ll;
const ll MOD = 1000000007ll;
const double EPS = 1e-8;

// Union Find
const int MAX_N = 200002;
int par[MAX_N], tree_rank[MAX_N];
void init_union_find(int n){
	for(int i=0; i<n; i++){
		par[i] = i;
		tree_rank[i] = 0;
	}
}

int root(int x){
	return par[x] == x ? x : par[x] = root(par[x]);
}

bool same(int x, int y){
	return root(x) == root(y);
}

void unite(int x, int y){
	x = root(x);
	y = root(y);
	if(x == y) return;

	if(tree_rank[x] < tree_rank[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(tree_rank[x] == tree_rank[y]) tree_rank[x]++;
	}
}

// Kruskal
struct edge{int u, v, cost;};
bool comp(const edge& e1, const edge& e2){
	return e1.cost < e2.cost;
}

const int MAX_E = 200002;
vector<edge> es;
int kruskal(int node_n){
	sort(es.begin(), es.end(), comp);
	init_union_find(node_n);
	int res = 0;
	for(int i=0; i<es.size(); i++){
		edge e = es[i];
		if(!same(e.u, e.v)){
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}

int main(void) {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	
	int n;
	cin >> n;

	int en = 0;
	vector<pair<int, int> > x;
	vector<pair<int, int> > y;
	for(int i=0; i<n; i++){
		int tx, ty;
		cin >> tx >> ty;

		x.pb(make_pair(tx, i));
		y.pb(make_pair(ty, i));
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	for(int i=0; i<n-1; i++){
		int x1 = x[i].first;
		int x2 = x[i+1].first;
		int i1 = x[i].second;
		int i2 = x[i+1].second;

		es.pb(edge{i1, i2, x2 - x1});
	}

	for(int i=0; i<n-1; i++){
		int y1 = y[i].first;
		int y2 = y[i+1].first;
		int i1 = y[i].second;
		int i2 = y[i+1].second;

		es.pb(edge{i1, i2, y2 - y1});
	}

	cout << kruskal(n) << endl;
	
	return 0;
}
