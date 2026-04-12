#include<bits/stdc++.h>

using std::pair;
using std::vector;


struct vertex {
	long long x, y;
	int idx;
};
struct edge {
	int a, b;
	long long cost;
};
long long abss(long long a) {
	if (a < 0)return -a;
	return a;
}
long long cost(vertex a, vertex b) {
	return std::min(abss(a.x - b.x), abss(a.y - b.y));
}
struct disjoint_set {
	vector<int> tree;
	disjoint_set(int n) {
		tree.resize(n, -1);
	}
	int find(int idx) {
		if (tree[idx] == -1)return idx;
		return tree[idx] = find(tree[idx]);
	}
	void Union(int a, int b) {
		int A = find(a);
		int B = find(b);
		if (A == B)return;
		tree[B] = A;
	}
};
int main() {
	int n;
	scanf("%d", &n);
	vector<vertex> P;
	for (int i = 0; i < n; i++) {
		long long x, y;
		scanf("%lld%lld", &x, &y);
		P.push_back({ x,y,i });
	}

	vector<edge> E;
	const int offset = 10;
	std::sort(P.begin(), P.end(), [&](const vertex& a, const vertex& b) {
		return a.x < b.x;
	});
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n && j - i <= offset; j++) {
			E.push_back({ P[i].idx,P[j].idx,cost(P[i],P[j]) });
			E.push_back({ P[j].idx,P[i].idx,cost(P[i],P[j]) });
		}
	}
	std::sort(P.begin(), P.end(), [&](const vertex& a, const vertex& b) {
		return a.y < b.y;
	});
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n && j - i <= offset; j++) {
			E.push_back({ P[i].idx,P[j].idx,cost(P[i],P[j]) });
			E.push_back({ P[j].idx,P[i].idx,cost(P[i],P[j]) });
		}
	}
	disjoint_set set(n);
	std::sort(E.begin(), E.end(), [&](const edge& a, const edge& b) {
		return a.cost < b.cost;
	});
	long long ans = 0;
	for (edge& e : E) {
		if (set.find(e.a) != set.find(e.b)) {
			ans += e.cost;
			set.Union(e.a, e.b);
		}
	}
	printf("%lld", ans);
}