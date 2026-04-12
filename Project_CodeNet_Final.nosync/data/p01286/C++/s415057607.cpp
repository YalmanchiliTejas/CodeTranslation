#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

struct Dinic {
	using Flow = int;
	struct Edge {
		int to, rev;
		Flow cap;
		Edge() {}
		Edge(int to, int rev, Flow cap) :to(to), rev(rev), cap(cap) {}
	};
	int n;
	vector<vector<Edge>> g;
	vector<bool> used;
	vector<int> level;
	vector<int> iter;
	Dinic(int n) :n(n), g(n), used(n), level(n), iter(n) {};
	void addArc(int from, int to, Flow cap) {
		g[from].emplace_back(to, (int)g[to].size(), cap);
		g[to].emplace_back(from, (int)g[from].size() - 1, 0);
	}
	void addEdge(int a, int b, Flow cap) {
		g[a].emplace_back(b, (int)g[b].size(), cap);
		g[b].emplace_back(a, (int)g[a].size() - 1, cap);
	}
	Flow maximumFlow(int s, int t) {
		Flow total = 0;
		while (true) {
			levelize(s);
			if (level[t] < 0)return total;
			fill(iter.begin(), iter.end(), 0);
			Flow f;
			while (true) {
				f = augment(s, t, INF);
				if (f == 0)break;
				total += f;
			}
		}
	}
	Flow augment(int v, int t, Flow f) {
		if (v == t)return f;
		for (int &i = iter[v]; i < g[v].size(); i++) {
			Edge &e = g[v][i];
			if (e.cap > 0 && level[v] < level[e.to]) {
				Flow d = augment(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					g[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	void levelize(int s) {
		fill(level.begin(), level.end(), -1);
		queue<int> q;
		level[s] = 0;
		q.push(s);
		while (q.size()) {
			int v = q.front(); q.pop();
			for (int i = 0; i < g[v].size(); i++) {
				Edge &e = g[v][i];
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					q.push(e.to);
				}
			}
		}
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (int H, W, C, M, NW, NC, NM; cin >> H >> W >> C >> M >> NW >> NC >> NM&&H != -1;) {
		//dump(H, W, C, M, NW, NC, NM);
		int N = H + W + C + M;
		Dinic dinic(N * 2 + 2 + 2 + 2 + 2);
		int ws = N * 2, wt = ws + 1, cs = wt + 1, ct = cs + 1, ms = ct + 1, mt = ms + 1;
		int s = dinic.n - 2, t = s + 1;
		rep(i, 0, H) {
			int h = i;
			dinic.addArc(s, h, 1);
			dinic.addArc(N + h, ws, 1);
		}
		rep(i, 0, W) {
			int w = i + H;
			int n; cin >> n;
			rep(j, 0, n) {
				int h; cin >> h; h--;
				dinic.addArc(N + h, w, 1);
			}
			dinic.addArc(N + w, cs, 1);
		}
		rep(i, 0, C) {
			int c = i + H + W;
			dinic.addArc(wt, c, 1);
			int n; cin >> n;
			rep(j, 0, n) {
				int w; cin >> w; w--; w += H;
				dinic.addArc(N + w, c, 1);
			}
			dinic.addArc(N + c, ms, 1);
		}
		rep(i, 0, M) {
			int m = i + H + W + C;
			dinic.addArc(ct, m, 1);
			int n; cin >> n;
			rep(j, 0, n) {
				int c; cin >> c; c--; c += H + W;
				dinic.addArc(N + c, m, 1);
			}
			dinic.addArc(N + m, t, 1);
		}

		dinic.addArc(ws, wt, NW);
		dinic.addArc(cs, ct, NC);
		dinic.addArc(ms, mt, NM);
		dinic.addArc(mt, t, INF);

		rep(i, 0, N) {
			dinic.addArc(i, N + i, 1);
		}

		cout << dinic.maximumFlow(s, t) << endl;
	}
	return 0;
}