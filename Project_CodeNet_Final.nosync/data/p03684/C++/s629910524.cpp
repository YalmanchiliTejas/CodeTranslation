#include <bits/stdc++.h>
using namespace std;

#define pb         push_back

typedef long long ll;
const ll INF = 1000000000000000000ll;
const ll MOD = 1000000007ll;
const double EPS = 1e-8;

const int MAX_N = 100005;
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

const int MAX_E = 1000000;
struct edge{int u, v, cost;};

bool comp(const edge& e1, const edge& e2){
	return e1.cost < e2.cost;
}

edge es[MAX_E];
int n, E;

int kruskal(){
	sort(es, es + E, comp);
	init_union_find(n);
	int res = 0;
	for(int i=0; i<E; i++){
		edge e = es[i];
		if(!same(e.u, e.v)){
			//printf("%d %d %d connect\n", e.u, e.v, e.cost);
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}

typedef pair<int, int> P;

int main(void) {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	cin >> n;
	vector< P >  p1, p2;
	for(int i=0; i<n; i++){
		int x, y;
		cin >> x >> y;
		p1.pb(make_pair(x, i));
		p2.pb(make_pair(y, i));
	}

	sort(p1.begin(), p1.end());
	sort(p2.begin(), p2.end());

	E = 0;
	for(int i=0; i<n-1; i++){
		int x1 = p1[i].first;
		int x2 = p1[i+1].first;
		int i1 = p1[i].second;
		int i2 = p1[i+1].second;

		//printf("%d : %d %d %d\n", E, x1, x2, x2 - x1);
		es[E] = edge{i1, i2, x2 - x1};
		E++;
	}

	for(int i=0; i<n-1; i++){
		int x1 = p2[i].first;
		int x2 = p2[i+1].first;
		int i1 = p2[i].second;
		int i2 = p2[i+1].second;

		//printf("%d : %d %d %d\n", E, x1, x2, x2 - x1);
		es[E] = edge{i1, i2, x2 - x1};
		E++;
	}

	cout << kruskal() << endl;
	
	return 0;
}
