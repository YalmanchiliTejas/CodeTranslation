#include "bits/stdc++.h"
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
using pii=pair<int, int>;

using Weight =int;
struct Edge {
	int s, d;
	Weight w;
	Edge() {};
	Edge(int s, int d, Weight w) :s(s), d(d), w(w) {};
};
using Array=vector<Weight>;
using Edges = vector<Edge>;
using Graph = vector<Edges>;

void addArc(Graph& g, int s, int d, Weight w = 1) {
	g[s].emplace_back(s, d, w);
}
void addEdge(Graph& g, int s, int d, Weight w = 1) {
	addArc(g, s, d, w);
	addArc(g, s, d, w);
}
const int INF = 1e7;
//vector<int>dijkstra(const Graph& g, int s, Array& dist) {
//	int n = g.size();
//	enum {WHITE,GRAY,BLACK};
//	assert(s < n);
//	vector<int>color(n, WHITE); color[s] = GRAY;
//	vector<int>prev(n, -1);
//	dist.assign(n, INF); dist[s] = 0;
//	using State=tuple<Weight, int, int>;
//	priority_queue<State, vector<State>, greater<State>>pq; pq.emplace(0, s, -1);
//
//}

void solve(int N, int M) {
	vector<string>c(N);
	rep(i, 0, N) {
		cin >> c[i];
	}
	auto inrange = [&](int x, int y) {return 0 <= x and x < N and 0 <= y and y < M; };
	vector<int>dx = { 0,-1,0,1 }, dy = { 1,0,-1,0 };

	auto check = [&](int x, int y, int dir) {
		int xx = x + dx[dir];
		int yy = y + dy[dir];
		if (not inrange(xx, yy))return false;
		return c[xx][yy] == '.';
	};

	int x = 0, y = 0, dir = 0;
	auto idx = [&](int x, int y) {return x * M + y;
	};
	vector<int>visited;
	while (1) {
		int left = (dir + 1) % 4;
		if (check(x, y, left)) {
			dir = left;
			x += dx[dir];
			y += dy[dir];

		}
		else if (check(x, y, dir)) {
			x += dx[dir];
			y += dy[dir];
		}
		else {
			(dir += 3) %= 4;
		}
		visited.emplace_back(idx(x, y));
		if (x == 0 && y == 0)break;
	}
	if (visited.back() == 0)visited.pop_back();
	int cnt = 0;
	rep(i, 0, visited.size()) {
		int xx = visited[i] / M;
		int yy = visited[i] % M;
		if ((xx == 0 && yy == M - 1) || (xx == N - 1 && yy == 0) || (xx == N - 1 && yy == M - 1)) cnt++;
		for (int j = visited.size() - 1; j > i; j--) {
			if (visited[i] == visited[j]) {
				i = j;
				break;
			}
		}
	}
	if (cnt == 3) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

signed main(void) {
	int N, M;
	while (cin >> N >> M, N && M) {
		solve(N, M);
	}
}
