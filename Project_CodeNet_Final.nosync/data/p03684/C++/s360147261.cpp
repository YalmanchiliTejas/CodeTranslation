#include <bits/stdc++.h>

using namespace std;

#define INF int(1e9)

struct Point {
	int idx, x, y;

	Point() { idx = x = y = -1; }

	Point(int idx, int x, int y) :
			idx(idx), x(x), y(y) {
	}
};

struct Edge {
	int u, v, c;
	Edge(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
};

struct DSU {   //Zero-based
	int size;
	int* p;
	int* rank;

	DSU(int n) {
		size = n;
		p = new int[n];
		rank = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
			rank[i] = 0;
		}
	}

	int findSet(int i) {
		return i == p[i] ? i : p[i] = findSet(p[i]);
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	void merge(int i, int j) {
		i = findSet(i);
		j = findSet(j);
		if (i == j)
			return;
		if (rank[i] < rank[j]) {
			p[i] = j;
		} else {
			p[j] = i;
			if (rank[i] == rank[j])
				rank[i]++;
		}
		size--;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x, y;
	cin >> n;
	Point points[n];
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		points[i] = Point(i, x, y);
	}
	vector<Edge> edges;
	edges.reserve(2 * (n - 1));

	sort(points, points + n, [](Point& a, Point& b) {
		return a.x < b.x;
	});
	for (int i = 0; i < n - 1; i++) {
		edges.push_back(
				{ points[i].idx, points[i + 1].idx, min(
						abs(points[i].x - points[i + 1].x),
						abs(points[i].y - points[i + 1].y)) });
	}

	sort(points, points + n, [](Point& a, Point& b) {
		return a.y < b.y;
	});
	for (int i = 0; i < n - 1; i++) {
		edges.push_back(
				{ points[i].idx, points[i + 1].idx, min(
						abs(points[i].x - points[i + 1].x),
						abs(points[i].y - points[i + 1].y)) });
	}

	sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
		return a.c < b.c;
	});

	DSU unionFind(n);
	long long ans = 0;
	for (Edge e : edges) {
		if (!unionFind.isSameSet(e.u, e.v)) {
			unionFind.merge(e.u, e.v);
			ans += e.c;
		}
	}
	cout << ans << '\n';
	return 0;
}
