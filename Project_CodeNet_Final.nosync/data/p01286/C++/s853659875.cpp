#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef int weight;

struct edge {
	int to;
	weight cap;
	int rev;
	edge(int to_, weight cap_, int rev_):to(to_), cap(cap_), rev(rev_){}
};

constexpr weight INF = (1 << 29);

vector<vector<edge> > G;
vector<int> level;
vector<int> iter;

void init(int V) {
	G.assign(V, vector<edge>());
	level.resize(V);
	iter.resize(V);
}

void add_edge(int from, int to, weight cap) {
	G[from].emplace_back(to, cap, G[to].size());
	G[to].emplace_back(from, 0, G[from].size() - 1);
}

void bfs(int s) {
	fill(level.begin(), level.end(), -1);
	queue<int> que;
	level[s] = 0;
	que.push(s);

	while(!que.empty()) {
		const int v = que.front();
		que.pop();

		for(const auto &e : G[v]) {
			if(e.cap > 0 && level[e.to] < 0) {
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

weight dfs(int v, int t, weight f) {
	if(v == t) return f;

	for(int &i = iter[v]; i < static_cast<int>(G[v].size()); ++i) {
		edge &e = G[v][i];
		if(e.cap > 0 && level[v] < level[e.to]) {
			const weight d = dfs(e.to, t, min(f, e.cap));
			if(d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}

	return 0;
}

weight max_flow(int s, int t) {
	weight flow = 0;

	for(;;) {
		bfs(s);
		if(level[t] < 0) return flow;

		fill(iter.begin(), iter.end(), 0);
		for(weight f; (f = dfs(s, t, INF)) > 0; flow += f);
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	for(int H, W, C, M, Nw, Nc, Nm; cin >> H >> W >> C >> M >> Nw >> Nc >> Nm && H >= 0;) {
		const int without_warrior = H + W + C + M;
		const int without_cleric = without_warrior + 1;
		const int without_mage = without_cleric + 1;
		const int offset_out = without_mage + 1;
		const int source = without_mage + offset_out + 1;
		const int sink = source + 1;
		const int V = sink + 1;
		init(V);

		add_edge(without_warrior, without_warrior + offset_out, Nw);
		add_edge(without_cleric, without_cleric + offset_out, Nc);
		add_edge(without_mage, sink, Nm);

		for(int hero = 0; hero < H; ++hero) {
			add_edge(source, hero, 1);
			add_edge(hero, hero + offset_out, 1);
			add_edge(hero + offset_out, without_warrior, 1);
		}

		for(int w = 0; w < W; ++w) {
			const int warrior = w + H;

			int n;
			cin >> n;

			for(int i = 0; i < n; ++i) {
				int h;
				cin >> h;

				const int hero = h - 1;
				add_edge(hero + offset_out, warrior, 1);
			}

			add_edge(warrior, warrior + offset_out, 1);
			add_edge(warrior + offset_out, without_cleric, 1);
		}

		for(int c = 0; c < C; ++c) {
			const int cleric = c + H + W;

			int n;
			cin >> n;

			for(int i = 0; i < n; ++i) {
				int w;
				cin >> w;

				const int warrior = w - 1 + H;
				add_edge(warrior + offset_out, cleric, 1);
			}

			add_edge(without_warrior + offset_out, cleric, 1);
			add_edge(cleric, cleric + offset_out, 1);
			add_edge(cleric + offset_out, without_mage, 1);
		}

		for(int m = 0; m < M; ++m) {
			const int mage = m + H + W + C;

			int n;
			cin >> n;

			for(int i = 0; i < n; ++i) {
				int c;
				cin >> c;

				const int cleric = c - 1 + H + W;
				add_edge(cleric + offset_out, mage, 1);
			}

			add_edge(without_cleric + offset_out, mage, 1);
			add_edge(mage, sink, 1);
		}

		cout << max_flow(source, sink) << endl;
	}

	return EXIT_SUCCESS;
}