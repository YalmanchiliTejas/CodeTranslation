#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cassert>
using namespace std;


using Weight = int;
using Capacity = int;
struct Edge {
	int src, dst; Weight weight; Capacity cap;
	Edge(int s, int d, Weight w, Capacity c) : src(s), dst(d), weight(w), cap(c) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;

struct Dinic {
	int n, s, t;
	vector<int> level, prog, que;
	vector<vector<Capacity>> cap, flow;
	vector<vector<int>> g;
	Capacity inf;
	Dinic(const Graph &graph)
		: n(graph.size()),
		cap(n, vector<Capacity>(n)), flow(n, vector<Capacity>(n)),
		g(n, vector<int>()), inf(numeric_limits<Capacity>::max() / 8) {
		for(int i = 0; i < n; i++) {
			for(auto &e : graph[i]) {
				int u = e.src, v = e.dst;
				Capacity c = e.cap;
				cap[u][v] += c; cap[v][u] += c; flow[v][u] += c;
				g[u].push_back(v); g[v].push_back(u);
			}
		}
	}
	inline Capacity residue(int u, int v) { return cap[u][v] - flow[u][v]; }
	Capacity solve(int s_, int t_) {
		this->t = t_, this->s = s_;
		que.resize(n + 1);
		Capacity res = 0;
		while(levelize()) { prog.assign(n, 0); res += augment(s, inf); }
		return res;
	}
	bool levelize() {
		int l = 0, r = 0;
		level.assign(n, -1); level[s] = 0; que[r++] = s;
		while(l != r) {
			int v = que[l++]; if(v == t) break;
			for(const int &d : g[v]) if(level[d] == -1 && residue(v, d) != 0) {
				level[d] = level[v] + 1; que[r++] = d;
			}
		}
		return level[t] != -1;
	}
	Capacity augment(int v, Capacity lim) {
		Capacity res = 0;
		if(v == t) return lim;
		for(int &i = prog[v]; i < (int)g[v].size(); i++) {
			const int &d = g[v][i];
			if(residue(v, d) == 0 || level[v] >= level[d]) continue;
			const Capacity aug = augment(d, min(lim, residue(v, d)));
			flow[v][d] += aug; flow[d][v] -= aug;
			res += aug; lim -= aug;
			if(lim == 0) break;
		}
		return res;
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H, W, C, M, Nw, Nc, Nm;
	while(cin >> H >> W >> C >> M >> Nw >> Nc >> Nm, H >= 0) {
		vector<int> H1(H), W1(W), W2(W), C1(C), C2(C), M1(M);
		Graph G(H + 2 * W + 2 + 2 * C + 2 + M + 1 + 2);
		int cnt = 0;
		for(int i = 0; i < H; i++) H1[i] = cnt++;
		for(int i = 0; i < W; i++) W1[i] = cnt++;
		for(int i = 0; i < W; i++) W2[i] = cnt++;
		for(int i = 0; i < C; i++) C1[i] = cnt++;
		for(int i = 0; i < C; i++) C2[i] = cnt++;
		for(int i = 0; i < M; i++) M1[i] = cnt++;
		int Nw1 = cnt++, Nw2 = cnt++, Nc1 = cnt++, Nc2 = cnt++, Nm1 = cnt++;
		int S = cnt++, T = cnt++;
		assert(cnt == G.size());

		for(int i = 0; i < H; i++) {
			G[S].push_back(Edge(S, H1[i], 0, 1));
		}
		for(int i = 0; i < M; i++) {
			G[M1[i]].push_back(Edge(M1[i], T, 0, 1));
		}

		int n, m;
		for(int i = 0; i < W; i++) {
			cin >> n;
			while(n--) {
				cin >> m;
				G[H1[m - 1]].push_back(Edge(H1[m - 1], W1[i], 0, 1));
			}
			G[W1[i]].push_back(Edge(W1[i], W2[i], 0, 1));
		}
		for(int i = 0; i < C; i++) {
			cin >> n;
			while(n--) {
				cin >> m;
				G[W2[m - 1]].push_back(Edge(W2[m - 1], C1[i], 0, 1));
			}
			G[C1[i]].push_back(Edge(C1[i], C2[i], 0, 1));
		}
		for(int i = 0; i < M; i++) {
			cin >> n;
			while(n--) {
				cin >> m;
				G[C2[m - 1]].push_back(Edge(C2[m - 1], M1[i], 0, 1));
			}
		}

		for(int i = 0; i < H; i++) {
			G[H1[i]].push_back(Edge(H1[i], Nw1, 0, 1));
		}
		G[Nw1].push_back(Edge(Nw1, Nw2, 0, Nw));
		for(int i = 0; i < C; i++) {
			G[Nw2].push_back(Edge(Nw2, C1[i], 0, 1));
		}

		for(int i = 0; i < W; i++) {
			G[W2[i]].push_back(Edge(W2[i], Nc1, 0, 1));
		}
		G[Nc1].push_back(Edge(Nc1, Nc2, 0, Nc));
		for(int i = 0; i < M; i++) {
			G[Nc2].push_back(Edge(Nc2, M1[i], 0, 1));
		}

		for(int i = 0; i < C; i++) {
			G[C2[i]].push_back(Edge(C2[i], Nm1, 0, 1));
		}
		G[Nm1].push_back(Edge(Nm1, T, 0, Nm));

		Dinic dinic(G);
		cout << dinic.solve(S, T) << endl;
	}
}