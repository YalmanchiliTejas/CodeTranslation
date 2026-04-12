#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

llint n, m, K, M;
llint d[20], dinv[105];
vector<llint> G[1<<16];
llint x[105][105];
llint dist[1<<16];

void bfs()
{
	for(int i = 0; i < M; i++) dist[i] = inf;
	dist[M-1] = 0;
	
	queue<llint> Q;
	Q.push(M-1);
	
	while(Q.size()){
		llint v = Q.front();
		Q.pop();
		for(int i = 0; i < G[v].size(); i++){
			llint u = G[v][i];
			if(dist[u] < inf/2) continue;
			dist[u] = dist[v] + 1;
			Q.push(u);
		}
	}
}

int main(void)
{
	cin >> n >> m >> K;
	for(int i = 0; i < m; i++) cin >> d[i];
	
	for(int i = 1; i <= n; i++) dinv[i] = -1;
	for(int i = 0; i < m; i++) dinv[d[i]] = i;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= K; j++){
			cin >> x[i][j];
		}
	}
	
	M = 1<<m;
	for(int i = 0; i < M; i++){
		for(int j = 1; j <= K; j++){
			llint mask = 0;
			for(int k = 0; k < m; k++){
				if((i & (1<<k)) == 0) continue;
				if(dinv[x[d[k]][j]] == -1) continue;
				mask |= (1 << dinv[x[d[k]][j]]);
			}
			G[i].push_back(mask);
		}
	}
	
	bfs();
	
	cout << dist[0] << endl;
	
	return 0;
}
