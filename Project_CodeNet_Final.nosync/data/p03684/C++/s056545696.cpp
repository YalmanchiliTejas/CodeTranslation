#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;
typedef pair< int, pair<int, int> > edge;

llint N;
llint x[100005], y[100005];
vector< pair<int, int> > vecx, vecy;
vector<edge> edges;

int parent[100005];

void init()
{
	for(int i = 0; i < N; i++) parent[i] = i;
}

int root(int i)
{
	if(parent[i] == i) return i;
	return parent[i] = root(parent[i]);
}

bool same(int i, int j)
{
	return root(i) == root(j);
}

void unite(int i, int j)
{
	int root_i = root(i);
	int root_j = root(j);
	if(root_i == root_j) return;
	parent[root_i] = root_j;
}

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> x[i] >> y[i];
	}
	init();
	
	for(int i = 0; i < N; i++){
		vecx.push_back( make_pair(x[i], i) );
		vecy.push_back( make_pair(y[i], i) );
	}
	sort(vecx.begin(), vecx.end());
	sort(vecy.begin(), vecy.end());
	
	for(int i = 0; i < N-1; i++){
		edges.push_back( make_pair( vecx[i+1].first - vecx[i].first, make_pair(vecx[i].second, vecx[i+1].second) ));
		edges.push_back( make_pair( vecy[i+1].first - vecy[i].first, make_pair(vecy[i].second, vecy[i+1].second) ));
	}
	sort(edges.begin(), edges.end());
	
	int ans = 0;
	for(int i = 0; i < edges.size(); i++){
		if(same(edges[i].second.first, edges[i].second.second)) continue;
		unite(edges[i].second.first, edges[i].second.second);
		ans += edges[i].first;
	}
	cout << ans << endl;
	return 0;
}