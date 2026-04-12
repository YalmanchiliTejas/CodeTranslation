#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


const int kMod = 1e9+7;
const int kMaxN = 1e5+10;

struct Edge {
	int x, y, c;

	Edge(int x, int y, int c) : x(x), y(y), c(c) {}

	Edge() {}

	bool operator < (const Edge& other) {
		return c < other.c;
	}
};

int p[kMaxN], x[kMaxN], y[kMaxN], vx[kMaxN], vy[kMaxN];

int parent(int a) {
	if (p[a] != 0) {
		return p[a] = parent(p[a]);
	}
	return a;
}

void unite(int a, int b, int c, long long& ans) {
	a = parent(a);
	b = parent(b);

	if (a != b) {
		p[a] = b;
		ans += c;
	}
}

void Solve() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		p[i] = 0;
	}

	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		vx[i] = i;
		vy[i] = i;
	}

	auto cmpx = [&](int a, int b) {
		return x[a] < x[b];
	};

	auto cmpy = [&](int a, int b) {
		return y[a] < y[b];
	};

	sort(vx + 1, vx + n + 1, cmpx);
	sort(vy + 1, vy + n + 1, cmpy);

	vector<Edge> edges;

	for (int i = 1; i < n; ++i) {
		edges.emplace_back(vx[i], vx[i+1], x[vx[i+1]] - x[vx[i]]);
	}

	for (int i = 1; i < n; ++i) {
		edges.emplace_back(vy[i], vy[i+1], y[vy[i+1]] - y[vy[i]]);
	}

	sort(edges.begin(), edges.end());

	long long ans = 0;

	for (auto e : edges) {
		unite(e.x, e.y, e.c, ans);
	}

	cout << ans << "\n";
}

int main() {
	int tests = 1;

	for (;tests; --tests) {
		Solve();
	}
}