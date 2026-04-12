#include<bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define mkp make_pair
typedef long long ll;
typedef pair<ll, int> pli;
const int MAXN = 100010;
const ll MOD = 1000000007; 
const ll INF = 1LL<<50;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch=='-') f=-1;
	for(; isdigit(ch); ch = getchar()) x = (x*10)+(ch^48);
	return x * f;
}

int st[MAXN], to[MAXN<<2];
int nxt[MAXN<<2], d[MAXN<<2], e;
inline void Add(int u, int v, int D) {
	to[++e] = v, nxt[e] = st[u];
	st[u] = e, d[e] = D;
	to[++e] = u, nxt[e] = st[v];
	st[v] = e, d[e] = D;
}

struct Edge {
	int u, v, d;
}E[MAXN<<1];

int n, m;
ll dis[2][MAXN], dp[2][MAXN], ans;
bool done[MAXN];

inline void update(ll &cur, ll val) {
	cur += val;
	if(cur >= MOD) cur -= MOD;
}

priority_queue<pli, vector<pli>, greater<pli> > q;

inline void Dijkstra(int S, int t) {
	int i;
	for(i = 1; i <= n; i++) dis[t][i] = INF;
	dis[t][S] = 0, dp[t][S] = 1;
	memset(done, 0, sizeof(done));
	q.push(mkp(0LL, S));
	while(!q.empty()) {
		int u = q.top().snd;
		q.pop();
		if(done[u]) continue;
		done[u] = true;
		for(i = st[u]; i; i = nxt[i]) {
			int v = to[i];
			if(dis[t][v] > dis[t][u]+d[i]) {
				dis[t][v] = dis[t][u]+d[i];
				dp[t][v] = dp[t][u];
				q.push(mkp(dis[t][v], v));
			}
			else if(dis[t][v] == dis[t][u]+d[i]) 
				update(dp[t][v], dp[t][u]);
		}
	}
	/*for(i = 1; i <= n; i++) printf("%lld ", dp[t][i]);
	printf("\n");*/
}

int main() {

	int i, S, T;
	n = read(), m = read();
	S = read(), T = read();
	for(i = 1; i <= m; i++) {
		int u = read(), v = read();
		Add(u, v, E[i].d = read());
		E[i].u = u, E[i].v = v;
	}

	Dijkstra(S, 0);
	Dijkstra(T, 1);

	ll C;
	//printf("%lld %lld\n", dp[0][T], dis[0][T]);
	ans = dp[0][T]*dp[0][T]%MOD;
	//printf("%lld\n", ans);
	//printf(":%lld\n", dis[0][2]);
	for(i = 1; i <= n; i++) 
		if(dis[0][i]*2 == dis[0][T]) {
			//printf(":%d %lld %lld\n", i, dp[0][i], dp[1][i]);
			C = dp[0][i]*dp[1][i]%MOD;
			ans = (ans-C*C%MOD+MOD)%MOD;
		}
	for(i = 1; i <= m; i++) {
		int u = E[i].u, v = E[i].v;
		if(dis[0][u] > dis[0][v]) swap(u, v);
		//if(dis[0][u]+E[i].d != dis[0][v]) continue;
		if(dis[0][u]+E[i].d+dis[1][v] != dis[0][T]) continue;
		if(dis[0][u]*2 < dis[0][T] && dis[0][v]*2 > dis[0][T]) {
			//printf("%d %d %lld %lld\n", u, v, dp[0][u], dp[1][v]);
			C = dp[0][u]*dp[1][v]%MOD;
			ans = (ans-C*C%MOD+MOD)%MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
