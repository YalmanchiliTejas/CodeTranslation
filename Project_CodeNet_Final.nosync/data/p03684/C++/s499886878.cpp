#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAX_V 120000
#define MAX_E 220000

typedef pair<int, int> P;

int par[MAX_V];
int rnk[MAX_V];

// n要素で初期化
void init(int n){
	for(int i = 0; i < n; i++){
		par[i] = i;
		rnk[i] = 0;
	}
}

// 木の根を求める
int find(int x){
	if(par[x] == x){
		return x;
	}
	return par[x] = find(par[x]);
}

// xとyの属する集合を併合
void unite(int x, int y){
	int x_par = find(x);
	int y_par = find(y);
	if(x_par == y_par){
		return;
	}
	
	if(rnk[x_par] < rnk[y_par]){
		par[x_par] = y_par;
	}else{
		par[y_par] = x_par;
		if(rnk[x_par] == rnk[y_par]){
			rnk[x_par]++;
		}
	}
}

bool same(int x, int y){
	return (find(x) == find(y));
}

struct edge{
	int u, v, cost;
};

bool comp(const edge& e1, const edge& e2){
	return e1.cost < e2.cost;
}

edge es[MAX_E];
int V, E;

int kruskal(){
	sort(es, es + E, comp);
	init(V);
	int res = 0;
	for(int i = 0; i < E; i++){
		edge e = es[i];
		if(!same(e.u, e.v)){
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}

int main(){
	
	int N;
	
	cin >> N;
	
	vector<P> v1, v2;
	
	for(int i = 0; i < N; i++){
		int x, y;
		cin >> x >> y;
		P p;
		p.first = x;
		p.second = i;
		v1.push_back(p);
		p.first = y;
		v2.push_back(p);
	}
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	V = N;
	E = 2 * N - 2;
	
	for(int i = 0; i < N - 1; i++){
		es[i].u = v1[i].second;
		es[i].v = v1[i + 1].second;
		es[i].cost = v1[i + 1].first - v1[i].first;
	}
	
	for(int i = 0; i < N - 1; i++){
		es[i + N - 1].u = v2[i].second;
		es[i + N - 1].v = v2[i + 1].second;
		es[i + N - 1].cost = v2[i + 1].first - v2[i].first;
	}
	
	for(int i = 0; i < E; i++){
		//cout << es[i].u << " " << es[i].v << " " << es[i].cost << endl;
	}
	
	int ans = kruskal();
	
	cout << ans << endl;
	
	return 0;
}