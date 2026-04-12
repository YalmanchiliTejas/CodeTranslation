#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define llint long long

using namespace std;

struct edge{
	llint to, cost;
	edge(llint a, llint b){
		to = a, cost = b;
	}
};

llint parent[4005];
llint N, M, Q;
vector< pair<llint, pair<llint, llint> > > vec;
vector<edge> G[4005];
llint dist[4005][4005];

void init(){
	for(llint i = 1; i <= N; i++){
		parent[i] = i;
	}
}

llint root(llint i){
	if(parent[i] == i) return i;
	return parent[i] = root(parent[i]);
}

bool same(llint i, llint j)
{
	return root(i) == root(j);
}

void unite(llint i, llint j)
{
	llint root_i = root(i), root_j = root(j);
	if(root_i == root_j) return;
	parent[root_i] = root_j;
}

void dfs(llint v, llint prev, llint s, llint val)
{
	dist[s][v] = val;
	for(llint i = 0; i < G[v].size(); i++){
		if(G[v][i].to == prev) continue;
		dfs(G[v][i].to, v, s, max(val, G[v][i].cost));
	}
}

int main(void)
{
	cin >> N >> M;
	llint a, b, c;
	for(llint i = 0; i < M; i++){
		cin >> a >> b >> c;
		vec.push_back( make_pair(c, make_pair(a, b) ) );
	}
	sort(vec.begin(), vec.end());
	
	init();
	llint cost = 0;
	for(llint i = 0; i < vec.size(); i++){
		a = vec[i].second.first, b = vec[i].second.second;
		if(same(a, b)) continue;
		unite(a, b);
		cost += vec[i].first;
		G[a].push_back(edge(b, vec[i].first));
		G[b].push_back(edge(a, vec[i].first));
	}
	
	for(llint i = 1; i <= N; i++){
		dfs(i, -1, i, 0);
	}
	
	cin >> Q;
	llint S, T;
	for(llint q = 0; q < Q; q++){
		cin >> S >> T;
		cout << cost - dist[S][T] << endl;
	}
	return 0;
}