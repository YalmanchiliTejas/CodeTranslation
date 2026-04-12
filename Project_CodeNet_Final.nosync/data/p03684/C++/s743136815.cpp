#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

int n,i,j,p[100005];
pair <int, int> a[100005];
vector <pair<int, int> > x, y;

int find(int s){
	if(s == p[s]) return s;
	return p[s] = find(p[s]);
}

struct dat{
	int u, v, cost;
	
	bool operator < (const dat& T) const{
		return cost < T.cost;
	}
};

vector <dat> edge;

int main(){
	scanf("%d", &n);
	
	
	for(i = 0; i < n; i++)
	scanf("%d%d", &a[i].first, &a[i].second);
	
	for(i = 0; i < n; i++){
		p[i] = i;
		x.push_back({a[i].first, i});
		y.push_back({a[i].second, i});
	}
	
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	
	for(i = 1; i < x.size(); i++)
	edge.push_back({x[i - 1].second, x[i].second, x[i].first - x[i - 1].first});
	for(i = 1; i < y.size(); i++)
	edge.push_back({y[i - 1].second, y[i].second, y[i].first - y[i - 1].first});
	
	sort(edge.begin(), edge.end());
	
	long long res = 0;
	
	for(i = 0; i < edge.size(); i++){
		int u = find(edge[i].u);
		int v = find(edge[i].v);
		int cost = edge[i].cost;
		
		if(u == v) continue;
		
		p[u] = v;
		res += cost;
	}
	
	printf("%lld\n", res);
}
