//2018-1-28
//miaomiao
//
#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
#define pb push_back
#define For(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define Forr(i, a, b) for(int i = (a); i >= (int)(b); --i)
 
#define N (100000 + 5)
const int P = 1e9 + 7;
 
inline int Mod(int a){return a >= P? a - P: a;}
 
struct node{
	int v, d;	
};
 
int n, m, s, t, fs[N], ft[N];
LL ds[N], dt[N];
vector<node> G[N];
 
bool inq[N];
 
void Spfa(int st, LL *dis){
	For(i, 1, n) dis[i] = 1ll << 60, inq[i] = false;
	queue<int> q;
	
	dis[st] = 0;
	q.push(st); inq[st] = true;
 
	while(!q.empty()){
		int now = q.front(); q.pop();
		inq[now] = false;
 
		For(i, 0, G[now].size() - 1){
			int v = G[now][i].v, md = G[now][i].d;
			
			if(dis[v] > dis[now] + md){
				dis[v] = dis[now] + md;
				if(!inq[v]){
					q.push(v); inq[v] = true;
				}
			}
		}
	}
}
 
vector<node> g[N];
int in[N];
 
void Work(int st, LL *dis, int *f){
	For(i, 1, n) g[i].clear(), in[i] = 0;
	For(u, 1, n) For(i, 0, G[u].size() - 1){
		int v = G[u][i].v, d = G[u][i].d;
		if(dis[u] + d == dis[v]){
			g[u].pb(G[u][i]); ++in[v];
		}
	}
 
	queue<int> q;
 
	f[st] = 1;
	For(i, 1, n) if(!in[i]) q.push(i);
 
	while(!q.empty()){
		int now = q.front(); q.pop();
 
		For(i, 0, g[now].size() - 1){
			int v = g[now][i].v;
			f[v] = Mod(f[v] + f[now]); --in[v];
			if(!in[v]) q.push(v);
		}
	}
}
 
int Solve(){
	int ret = 0;
	LL D = ds[t];
 
	For(i, 1, n) if(2 * ds[i] <= D){
		if(2 * ds[i] == D && 2 * dt[i] == D){
			ret = Mod(ret + 1ll * fs[i] * ft[i] % P * fs[i] % P * ft[i] % P);
			continue;
		}
 
		For(j, 0, G[i].size() - 1){
			int v = G[i][j].v, d = G[i][j].d;
			if(2 * dt[v] >= D) continue;
			if(ds[i] + d + dt[v] != D) continue;
			
			ret = Mod(ret + 1ll * fs[i] * ft[v] % P * fs[i] % P * ft[v] % P);
		}
	}
 
	return ret;
}
 
int main(){
	int u, v, w;
	
	scanf("%d%d%d%d", &n, &m, &s, &t);
	For(i, 1, m){
		scanf("%d%d%d", &u, &v, &w);
		G[u].pb((node){v, w}); G[v].pb((node){u, w});
	}
 
	Spfa(s, ds); Work(s, ds, fs);
	Spfa(t, dt); Work(t, dt, ft);
 
	int ans = 1ll * fs[t] * fs[t] % P - Solve();
	
	if(ans < 0) ans += P;
	printf("%d\n", ans);
 
	return 0;
}