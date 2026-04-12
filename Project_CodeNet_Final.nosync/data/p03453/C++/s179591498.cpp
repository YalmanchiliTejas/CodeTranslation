#include <bits/stdc++.h>
using namespace std;

#ifdef HELTHAZAR
#define dout if (true) cout
#else
#define dout if (false) cout
#endif

const int MAXN = 1e5 + 1;
const long long MOD = 1e9 + 7;
struct edge {
	int next;
	long long d;
};
vector<edge> edges[MAXN];
int used[MAXN];
long long dis1[MAXN], dis2[MAXN];
long long cnt1[MAXN], cnt2[MAXN];

long long summod(long long a, long long b) {
	return (a + b) % MOD;
}

long long mulmod(long long a, long long b) {
	return (a * b) % MOD;
}

long long sqr(long long x) {
	return mulmod(x, x);
}

void dijkstra(int s, long long dis[], long long cnt[]) {
	set<pair<long long, int> > st;
	st.insert({1, s});
	used[s] = 1;
	cnt[s] = 1;
	while (!st.empty()) {
		auto v = st.begin()->second;
		st.erase(st.begin());
		for (auto e: edges[v]) {
			if (!used[e.next] || dis[e.next] > dis[v] + e.d) {
				st.erase({dis[e.next], e.next});
				used[e.next] = 1;
				dis[e.next] = dis[v] + e.d;
				cnt[e.next] = cnt[v];
				st.insert({dis[e.next], e.next});
			}
			else if (dis[e.next] == dis[v] + e.d) {
				cnt[e.next] = summod(cnt[e.next], cnt[v]);
			}
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	for (int i = 0; i < m; i++) {
		int u, v;
		long long d;
		cin >> u >> v >> d;
		edges[u].push_back({v, d});
		edges[v].push_back({u, d});
	}

	dijkstra(s, dis1, cnt1);
	fill(used + 1, used + n + 1, 0);
	dijkstra(t, dis2, cnt2);
	long long d = dis1[t];
	long long sum = 0, sqrsum = 0;
	for (int v = 1; v <= n; v++) {
		if (dis1[v] + dis2[v] == d && dis1[v] == dis2[v]) {
			long long res = mulmod(cnt1[v], cnt2[v]);
			sum = summod(sum, res);
			sqrsum = summod(sqrsum, sqr(res));
		}
		for (auto e: edges[v])
			if (dis1[v] + e.d + dis2[e.next] == d && dis1[v] * 2 < d && dis2[e.next] * 2 < d) {
				long long res = mulmod(cnt1[v], cnt2[e.next]);
				sum = summod(sum, res);
				sqrsum = summod(sqrsum, sqr(res));
			}
	}
	cout << summod(sqr(sum), MOD - sqrsum) << endl;
}

int main(){
  	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();
}
