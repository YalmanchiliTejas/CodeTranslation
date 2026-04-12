#include <bits/stdc++.h>

#define MAXN (100010)


int n;
int lfson[MAXN], sz[MAXN], deg[MAXN], f[MAXN], dep[MAXN];
int delta[MAXN];
std::vector<int> vec[MAXN];
struct cmp{
	bool operator() (int a, int b){
		return dep[a] < dep[b];
	}
};
std::priority_queue<int, std::vector<int>, cmp> pq;
bool vis[MAXN];

void dfs(int u, int fa){
	sz[u] = 1;
	for(auto v : vec[u]){
		if(v == fa) continue;
		f[v] = u;
		dep[v] = dep[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
		if(sz[v] == 1){
			lfson[u] ++;
			pq.push(v);
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++ i){
		int u, v;
		scanf("%d%d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
		++ deg[u];
		++ deg[v];
	}
	for(int i = 1; i <= n; ++ i){
		if(deg[i] != 1){
			dfs(i, 0);
			break;
		}
	}
	while(!pq.empty()){
		int u = pq.top();
		pq.pop();
		int v = f[u];
		if(lfson[v] != 1){
			return printf("First\n"), 0;
		}
		//v = f[v];
		if(!f[v]) continue;
		delta[f[v]] += delta[u] + delta[v] + 2;
		sz[f[v]] -= delta[u] + delta[v] + 2;
		v = f[v];
		if(sz[v] == 1){
			pq.push(v);
			if(f[v]){
			    lfson[f[v]] ++;
			}
		}
	}
	printf("Second\n");
	return 0;
}