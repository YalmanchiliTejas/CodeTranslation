#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 1, MOD = 1e9 + 7;

int parent[N], sz[N], rnk[N];

void init() {
	memset(rnk, 0, sizeof rnk);
	for (int i = 0; i < N; ++i) {
		parent[i] = i;
		sz[i] = 1;
	}
}

int root(int node) {
	while (node != parent[node]) {
		parent[node] = parent[parent[node]];
		node = parent[node];
	}
	return node;
}

bool join(int u, int v) {
	u = root(u);
	v = root(v);
	
	if (u == v)
		return false;
	
	if (rnk[u] < rnk[v])
		swap(u, v);
	
	rnk[u] += rnk[u] == rnk[v];
	sz[u] += sz[v];
	
	parent[v] = u;
	return true;
}

int find(int u, int v) {
	return root(u) == root(v);
}

struct Things {
	int cost, from, to;
	bool operator<(Things t) const {
		return cost < t.cost;
	}
};

struct Point {
	int x, y, i;
	bool operator<(Point p) const {
		if (x == p.x) {
			return y < p.y;
		}
		return x < p.x;
	}
};

Point a[N], b[N];
int main() {
//#ifndef ONLINE_JUDGE
//	freopen("input.in", "r", stdin);
//#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &a[i].x, &a[i].y);
		a[i].i = i;
		b[i] = {a[i].y, a[i].x, i};
	}
	sort(a, a + n);
	sort(b, b + n);
	vector<Things> things;
	for (int i = 1; i < n; ++i) {
		things.push_back({abs(a[i].x - a[i - 1].x), a[i].i, a[i - 1].i});
		things.push_back({abs(b[i].x - b[i - 1].x), b[i].i, b[i - 1].i});
	}
	sort(things.begin(), things.end());
	long long result = 0;
	init();
	for (auto x: things) {
		if (find(x.from, x.to) == 0) {
			join(x.from, x.to);
			result += x.cost;
		}
	}
	printf("%lld\n", result);
	return 0;
}
