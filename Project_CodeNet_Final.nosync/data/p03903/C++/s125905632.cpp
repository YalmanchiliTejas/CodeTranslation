#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353
using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

struct edge{
	llint to, cost;
	edge(){}
	edge(llint a, llint b){
		to = a, cost = b;
	}
};

struct UnionFind{
	int size;
	vector<int> parent;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) parent[i] = i;
	}
	int root(int i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	void unite(int i, int j){
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j) return;
		parent[root_i] = root_j;
	}
};

llint n, m, Q;
vector<E> vec;
vector<edge> G[4005];
UnionFind uf(4005);
llint dist[4005][4005];

void dfs(int v, int p, llint m, llint s)
{
	dist[s][v] = m;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == p) continue;
		dfs(G[v][i].to, v, max(m, G[v][i].cost), s);
	}
}

int main(void)
{
	cin >> n >> m;
	llint u, v, w;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		vec.push_back(E(w, P(u, v)));
	}
	sort(vec.begin(), vec.end());
	
	llint ans = 0;
	for(int i = 0; i < vec.size(); i++){
		w = vec[i].first, u = vec[i].second.first, v = vec[i].second.second;
		if(uf.same(u, v)) continue;
		uf.unite(u, v);
		ans += w;
		G[u].push_back(edge(v, w));
		G[v].push_back(edge(u, w));
	}
	
	for(int i = 1; i <= n; i++) dfs(i, -1, 0, i);
	
	cin >> Q;
	llint s, t;
	for(int i = 1; i <= Q; i++){
		cin >> s >> t;
		cout << ans - dist[s][t] << endl;
	}
	
	return 0;
}
