#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
struct edge { int to, cost; };
struct state { int pos; long long cost; };
bool operator<(const state& s1, const state& s2) { return s1.cost > s2.cost; };
int N, M, S, T, a[200009], b[200009], c[200009]; vector<edge> g[100009];
vector<long long> shortest_path(int start) {
	vector<long long> res(N, 1LL << 60); res[start] = 0;
	priority_queue<state> que; que.push(state{ start, 0 });
	while (!que.empty()) {
		int pos = que.top().pos; que.pop();
		for (edge e : g[pos]) {
			if (res[e.to] > res[pos] + e.cost) {
				res[e.to] = res[pos] + e.cost;
				que.push(state{ e.to, res[e.to] });
			}
		}
	}
	return res;
}
vector<int> calc(int start, vector<long long> dist) {
	vector<int> res(N), p(N); res[start] = 1;
	for (int i = 0; i < N; i++) p[i] = i;
	sort(p.begin(), p.end(), [&](int i, int j) { return dist[i] < dist[j]; });
	for (int i = 1; i < N; i++) {
		for (edge e : g[p[i]]) {
			if (dist[e.to] + e.cost == dist[p[i]]) {
				res[p[i]] += res[e.to];
				if (res[p[i]] >= mod) res[p[i]] -= mod;
			}
		}
	}
	return res;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> S >> T; S--, T--;
	for (int i = 0; i < M; i++) {
		cin >> a[i] >> b[i] >> c[i]; a[i]--, b[i]--;
		g[a[i]].push_back(edge{ b[i], c[i] });
		g[b[i]].push_back(edge{ a[i], c[i] });
	}
	vector<long long> ds = shortest_path(S);
	vector<long long> dt = shortest_path(T);
	vector<int> cs = calc(S, ds);
	vector<int> ct = calc(T, dt);
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (ds[i] * 2 == ds[T] && dt[i] * 2 == ds[T]) {
			ret = (ret + 1LL * cs[i] * cs[i] % mod * ct[i] % mod * ct[i]) % mod;
		}
	}
	for (int i = 0; i < M; i++) {
		if (ds[a[i]] + dt[b[i]] + c[i] == ds[T] && ds[a[i]] * 2 < ds[T] && dt[b[i]] * 2 < ds[T]) {
			ret = (ret + 1LL * cs[a[i]] * cs[a[i]] % mod * ct[b[i]] % mod * ct[b[i]]) % mod;
		}
		if (ds[b[i]] + dt[a[i]] + c[i] == ds[T] && ds[b[i]] * 2 < ds[T] && dt[a[i]] * 2 < ds[T]) {
			ret = (ret + 1LL * cs[b[i]] * cs[b[i]] % mod * ct[a[i]] % mod * ct[a[i]]) % mod;
		}
	}
	cout << (1LL * cs[T] * cs[T] - ret + mod) % mod << '\n';
	return 0;
}