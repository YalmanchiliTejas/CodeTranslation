#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<LL, LL> P;
const LL INF = 1LL << 60;
const LL MOD = 1000000007LL;
LL distS[100000];
LL distT[100000];
vector<int> orderS;
vector<int> orderT;
int r_orderS[100000];
int r_orderT[100000];
LL dpS[100000];
LL dpT[100000];
vector<P> G[100000];
bool vis[100000];
int N, M;
void dijkstra(int v, LL *dist) {
	priority_queue<P, vector<P>, greater<P>> Q;
	fill(vis, vis + N, 0);
	fill(dist, dist + N, INF);
	dist[v] = 0;
	Q.push(P(0, v));
	while (!Q.empty()) {
		P p = Q.top(); Q.pop();
		if (dist[p.second] != p.first) continue;
		for (P e : G[p.second]) {
			int to = e.first;
			int d = e.second;
			if (dist[to] > dist[p.second] + d) {
				dist[to] = dist[p.second] + d;
				Q.push(P(dist[to], to));
			}
		}
	}
}
void topo_sort(int v, LL *dist, vector<int> &order) {
	vis[v] = 1;
	for (P x : G[v]) {
		int to = x.first;
		LL d = x.second;
		if (dist[v] + d == dist[to] && !vis[to]) topo_sort(to, dist, order);
	}
	order.push_back(v);
}
void route_count(LL *dp, LL *dist, vector<int> &order, int *r_order) {
	dp[0] = 1;
	for (int i = 0; i < N; i++) {
		int v = order[i];
		for (P x : G[v]) {
			int to = x.first;
			LL d = x.second;
			if (dist[v] + d == dist[to]) (dp[r_order[to]] += dp[i]) %= MOD;
		}
	}
}
int main() {
	cin >> N >> M;
	int S, T;
	cin >> S >> T; S--; T--;
	for (int i = 0; i < M; i++) {
		int U, V, D;
		cin >> U >> V >> D;
		U--; V--;
		G[U].push_back(P(V, D));
		G[V].push_back(P(U, D));
	}
	dijkstra(S, distS);
	dijkstra(T, distT);
	fill(vis, vis + N, 0);
	for (int i = 0; i < N; i++) {
		if (!vis[i]) topo_sort(i, distS, orderS);
	}
	reverse(orderS.begin(), orderS.end());
	for (int i = 0; i < N; i++) r_orderS[orderS[i]] = i;
	fill(vis, vis + N, 0);
	for (int i = 0; i < N; i++) {
		if (!vis[i]) topo_sort(i, distT, orderT);
	}
	reverse(orderT.begin(), orderT.end());
	for (int i = 0; i < N; i++) r_orderT[orderT[i]] = i;
	route_count(dpS, distS, orderS, r_orderS);
	route_count(dpT, distT, orderT, r_orderT);
	LL ans = 0;
	for (int i = 0; i < N; i++) {
		for (P x : G[i]) {
			int to = x.first;
			LL d = x.second;
			if (distS[i] + d + distT[to] == distS[T] && abs(distS[i] - distT[to]) < d) {
				LL tmpS = (dpS[r_orderS[i]] * dpS[r_orderS[i]]) % MOD;
				LL tmpT = (dpT[r_orderT[to]] * dpT[r_orderT[to]]) % MOD;
				LL tmp = (tmpS*tmpT) % MOD;
				(ans += tmp) %= MOD;
			}
		}
		if (distS[i] == distT[i] && distS[i] + distT[i] == distS[T]) {
			LL tmpS = (dpS[r_orderS[i]] * dpS[r_orderS[i]]) % MOD;
			LL tmpT = (dpT[r_orderT[i]] * dpT[r_orderT[i]]) % MOD;
			LL tmp = (tmpS*tmpT) % MOD;
			(ans += tmp) %= MOD;
		}
	}
	LL total = (dpS[r_orderS[T]] * dpS[r_orderS[T]]) % MOD;
	cout << (total - ans + MOD) % MOD << endl;
}