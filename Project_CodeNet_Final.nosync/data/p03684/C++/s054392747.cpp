//  Created by Sengxian on 2017/6/24.
//  Copyright (c) 2017年 Sengxian. All rights reserved.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
inline int readInt() {
	int n = 0, ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) n = n * 10 + ch - '0', ch = getchar();
	return n;
}

const int MAX_N = 100000 + 3;
int n;

struct Point {
	int x, y, id;
	
	void read() {
		x = readInt(), y = readInt();
	}
} pts[MAX_N];

inline bool cmp1(const Point &a, const Point &b) {
	return a.x < b.x;
}

inline bool cmp2(const Point &a, const Point &b) {
	return a.y < b.y;
}

struct DisjointSet {
	int fa[MAX_N];
	
	void init(int n) {
		for (int i = 0; i < n; ++i)
			fa[i] = i;
	}
	
	inline int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	
	void unite(int x, int y) {
		x = find(x), y = find(y);
		fa[x] = y;
	}
	
	bool same(int x, int y) {
		return find(x) == find(y);
	}
} ds;

struct Edge {
	int from, to, cost;
	bool operator < (const Edge &e) const {
		return cost < e.cost;
	}
} edges[MAX_N * 2];

inline int calc(const Point &a, const Point &b) {
	return min(abs(a.x - b.x), abs(a.y - b.y));
}

int main() {
	n = readInt();
	for (int i = 0; i < n; ++i) pts[i].read(), pts[i].id = i;
	int cnt = 0;
	sort(pts, pts + n, cmp1);
	for (int i = 0; i < n - 1; ++i) edges[cnt].from = pts[i].id, edges[cnt].to = pts[i + 1].id, edges[cnt++].cost = calc(pts[i], pts[i + 1]);
	sort(pts, pts + n, cmp2);
	for (int i = 0; i < n - 1; ++i) edges[cnt].from = pts[i].id, edges[cnt].to = pts[i + 1].id, edges[cnt++].cost = calc(pts[i], pts[i + 1]);
	ds.init(n);
	sort(edges, edges + cnt);
	ll ans = 0;
	for (int i = 0; i < cnt; ++i) {
		Edge &e = edges[i];
		if (!ds.same(e.from, e.to)) {
			ds.unite(e.from, e.to);
			ans += e.cost;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
