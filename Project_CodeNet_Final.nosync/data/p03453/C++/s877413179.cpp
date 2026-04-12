#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long int LL;
typedef pair <LL, int> pii;
const LL MOD = 1000000007LL;
const int MAXN = 100005, MAXM = 200005;

int n, m, s, t, g[MAXN], nxt[MAXM << 1], to[MAXM << 1];
int val[MAXM << 1], edgeSize;
LL dp1[MAXN], dp2[MAXN], ans, d1[MAXN], d2[MAXN];

void addEdge(int u, int v, int w){
	nxt[++ edgeSize] = g[u];
	to[g[u] = edgeSize] = v;
	val[edgeSize] = w;
}
void dijkstra(int st, LL d[], LL dp[]){
	priority_queue <pii, vector <pii>, greater <pii> > q;
	int i, p; pii now;
	for(i = 1; i <= n; ++ i)
		d[i] = 0x3f3f3f3f3f3f3f3fLL, dp[i] = 0;
	d[st] = 0, dp[st] = 1;
	q.push(pii(0, st));
	while(!q.empty()){
		now = q.top(); q.pop();
		if(now.fi != d[now.se])
			continue;
		for(p = g[now.se]; p; p = nxt[p])
			if(d[to[p]] > now.fi + val[p]){
				q.push(pii(d[to[p]] = now.fi + val[p], to[p]));
				dp[to[p]] = dp[now.se];
			}else if(d[to[p]] == now.fi + val[p])
				dp[to[p]] = (dp[to[p]] + dp[now.se]) % MOD;
	}
}
int main(){
	int i, u, v, w, j;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d%d", &u, &v, &w);
		addEdge(u, v, w), addEdge(v, u, w);
	} dijkstra(s, d1, dp1);
	dijkstra(t, d2, dp2);
	ans = dp1[t] * dp1[t] % MOD;
	for(i = 1; i <= n; ++ i){
		if(d1[i] * 2 == d1[t] && d1[i] + d2[i] == d1[t])
			ans = (((ans - (dp1[i] * dp2[i] % MOD) * (dp1[i] * dp2[i] % MOD)) % MOD) + MOD) % MOD;
		if(d1[i] * 2 >= d1[t]) continue;
		for(j = g[i]; j; j = nxt[j]){
			if(d1[i] + val[j] != d1[to[j]] || d1[to[j]] + d2[to[j]] != d1[t])
				continue;
			if(d1[to[j]] * 2 > d1[t])
				ans = (((ans - (dp1[i] * dp2[to[j]] % MOD) * (dp1[i] * dp2[to[j]] % MOD)) % MOD) + MOD) % MOD;
		}
	} printf("%d\n", int(ans));
	return 0;
}