#include "bits/stdc++.h"
using namespace std;
#define INF (1 << 29)

struct edge { int to, cost; };
typedef pair<int, int> P;   // firstは最短距離、secondは頂点の番号

const int MAX_V = 1000, MAX_E = 1000;

int V, E;
vector<edge> G[MAX_V];
int d[MAX_V];
bool flag[MAX_V];
int cnt=0;

int dfs(int s, int depth) {
	//cout << s <<" "<< depth << endl;
	bool F=true;
	for (int i = 0; i < V; i++) {
		if (!flag[i]) { F = false; break; }
	}
	if(F) cnt++;

	for (int i = 0; i < G[s].size(); i++) {
		edge u = G[s][i];
		int v = u.to;
		if(flag[v]) continue;
		flag[v]=true;
		dfs(v,depth+1);
		flag[v]=false;
	}

	return cnt;
}


int main() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int s, t;
		cin >> s >> t;
		s--; t--;
		G[s].push_back(edge{ t, 1 });
		G[t].push_back(edge{ s, 1 });
	}
	flag[0]=true;
	cout << dfs(0,0) << endl;
}