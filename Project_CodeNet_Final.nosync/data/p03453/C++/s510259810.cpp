#include <bits/stdc++.h>

#define x first
#define y second
#define pb push_back
#define Set(i, v) memset(i, v, sizeof i)
#define For(i, j, k) for(int i = j; i <= k; i++)
#define Forr(i, j, k) for(int i = j; i >= k; i--)

typedef long long LL;

using namespace std;

const int Mod = 1e9 + 7;
const int N = 1e5 + 10, M = N << 2;

int Begin[N], Next[M], to[M], len[M], e = 1;

void add(int u, int v, int w){
	len[++e] = w, Next[e] = Begin[u], Begin[u] = e, to[e] = v;
}

struct Node{
	int o;
	LL d;

	Node(int _o = 0, LL _d = 0): o(_o), d(_d) {}

	bool operator < (const Node& B) const{
		return d > B.d;
	}
};

int n, m, S, T;
bool vis[N];
LL dis[N];
vector<int> G[N];

void Dijkstra(){
	priority_queue<Node> q;
	memset(dis, 0x3f, sizeof dis);
	dis[S] = 0;
	q.emplace(S, 0);
	while(!q.empty()){
		Node s = q.top(); q.pop();
		if(vis[s.o]) continue;
		vis[s.o] = true;

		for(int i = Begin[s.o]; i; i = Next[i]){
			int u = to[i];
			if(dis[u] > s.d + len[i]){
				G[u].clear();
				G[u].pb(s.o);
				dis[u] = s.d + len[i];
				q.emplace(u, dis[u]);
			}
			else if(dis[u] == s.d + len[i]) G[u].pb(s.o);
		}
	}
}

int f[N], g[N];
bool imp[N];

void DFS_init(int o){
	imp[o] = true;
	for(int v : G[o]){
		if(dis[v] > dis[o]) continue;
		if(!imp[v]) DFS_init(v);
		G[v].pb(o);
	}
}

void add(int &x, int y){
	x += y;
	if(x >= Mod) x -= Mod;
}

int DFS_workpre(int o){
	if(vis[o]) return f[o];
	vis[o] = true;
	f[o] = 0;
	for(int v : G[o]){
		if(!imp[v] || dis[v] < dis[o]) continue;
		add(f[o], DFS_workpre(v));
	}
	return f[o];
}

int DFS_worksuf(int o){
	if(vis[o]) return g[o];
	vis[o] = true;
	g[o] = 0;
	for(int v : G[o]){
		if(!imp[v] || dis[v] > dis[o]) continue;
		add(g[o], DFS_worksuf(v));
	}
	return g[o];
}

int main(){

	scanf("%d%d%d%d", &n, &m, &S, &T);
	For(i, 1, m){
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		d *= 2;
		add(u, v, d), add(v, u, d);
	}
	Dijkstra();
	DFS_init(T);

	LL D = dis[T] / 2;
	
	Set(vis, false);
	vis[T] = true, f[T] = 1;
	DFS_workpre(S);

	Set(vis, false);
	vis[S] = true, g[S] = 1;
	DFS_worksuf(T);

	LL ans = 1ll * f[S] * g[T] % Mod;
	For(i, 1, n) if(imp[i] && dis[i] == D) ans = (ans + Mod - 1ll * f[i] * g[i] % Mod * f[i] % Mod * g[i] % Mod) % Mod;
	For(i, 1, n) if(imp[i] && dis[i] < D)
		for(int j : G[i]) if(imp[j] && dis[j] > D){
			ans = (ans + Mod - 1ll * g[i] * f[j] % Mod * g[i] % Mod * f[j] % Mod) % Mod;
		}
	printf("%lld\n", ans);

	return 0;
}