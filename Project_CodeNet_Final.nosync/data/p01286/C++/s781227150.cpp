#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int to, cap, rev;
};

bool used[2000];
vector< vector<Edge> > G;

#define INF 1e9

void addEdge(int from, int to, int cap) {
	G[from].push_back({to, cap, (int)G[to].size()});
	G[to].push_back({from, cap, (int)G[from].size()-1});
}
int dfs(int s, int t, int f) {
	if (s == t) return f;
	used[s] = true;

	for (int i = 0; i < G[s].size(); ++i) {
		Edge& e = G[s][i];
		if (!used[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int flow(int s, int t) {
	int flow = 0;
	while (1) {
		memset(used, false, sizeof(used));
		int f = dfs(s, t, INF);
		if (f == 0) break;
		else flow += f;
	}
	return flow;
}

int main() {
	int H, W, C, M, Nw, Nc, Nm;
	while (cin >> H >> W >> C >> M >> Nw >> Nc >> Nm, H >= 0) {
		int s = H+2*(W+C+M), t = s+1;
		int w = t+1, c = w+2, m = c+2;
		G.clear(); G.resize(m+1);

		addEdge(w, w+1, Nw);
		addEdge(c, c+1, Nc);
		addEdge(m, t, Nm);
		for (int i = 0; i < H; ++i) {
			addEdge(s, i, 1);
			addEdge(i, w, 1);
		}
		for (int i = 0; i < W; ++i) {
			int n; cin >> n;
			for (int j = 0; j < n; ++j) {
				int id; cin >> id; --id;
				addEdge(id, H+i, 1);
			}
			addEdge(H+i, H+W+i, 1);
			addEdge(H+W+i, c, 1);
		}
		for (int i = 0; i < C; ++i) {
			int n; cin >> n;
			for (int j = 0; j < n; ++j) {
				int id; cin >> id; --id;
				addEdge(H+W+id, H+2*W+i, 1);
			}
			addEdge(w+1, H+W+i, 1);
			addEdge(H+2*W+i, H+2*W+C+i, 1);
			addEdge(H+2*W+C+i, m, 1);
		}
		for (int i = 0; i < M; ++i) {
			int n; cin >> n;
			for (int j = 0; j < n; ++j) {
				int id; cin >> id; --id;
				addEdge(H+2*W+C+id, H+2*W+2*C+i, 1);
			}
			addEdge(c+1, H+2*W+C+i, 1);
			addEdge(H+2*W+2*C+i, t, 1);
		}
		cout << flow(s, t) << endl;
	}
}