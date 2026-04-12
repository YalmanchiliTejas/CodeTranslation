#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

// range add/range max
struct SegTree {
	int n;
	std::vector<int64_t> data;
	std::vector<int64_t> added;
	SegTree (int n_) {
		for (n = 1; n < n_; n <<= 1);
		data.resize(n << 1);
		added.resize(n << 1);
	}
	void flush(int i) {
		if (added[i]) {
			data[i] += added[i];
			if (i < n) {
				added[i << 1] += added[i];
				added[i << 1 | 1] += added[i];
			}
			added[i] = 0;
		}
	}
	void assign(int i, int64_t val, int node = 1, int node_l = 0, int node_r = 0) {
		if (!node_r) node_r = n;
		flush(node);
		if (node_l == i && node_r == i + 1) {
			data[node] = val;
			return;
		}
		int mid = node_l + ((node_r - node_l) >> 1);
		if (i < mid) assign(i, val, node << 1, node_l, mid);
		else assign(i, val, node << 1 | 1, mid, node_r);
		data[node] = std::max(data[node << 1], data[node << 1 | 1]);
	}
	void add(int l, int r, int val, int node = 1, int node_l = 0, int node_r = 0) {
		if (!node_r) node_r = n;
		flush(node);
		if (l >= node_r || r <= node_l) return;
		if (l <= node_l && r >= node_r) {
			added[node] = val;
			flush(node);
		} else {
			int mid = node_l + ((node_r - node_l) >> 1);
			add(l, r, val, node << 1, node_l, mid);
			add(l, r, val, node << 1 | 1, mid, node_r);
			data[node] = std::max(data[node << 1], data[node << 1 | 1]);
		}
	}
	int64_t max(int l, int r, int node = 1, int node_l = 0, int node_r = 0) {
		if (!node_r) node_r = n;
		flush(node);
		if (l >= node_r || r <= node_l) return 0;
		if (l <= node_l && r >= node_r) return data[node];
		else {
			int mid = node_l + ((node_r - node_l) >> 1);
			int64_t res = std::max(max(l, r, node << 1, node_l, mid), max(l, r, node << 1 | 1, mid, node_r));
			data[node] = std::max(data[node << 1], data[node << 1 | 1]);
			return res;
		}
	}
};

int main() {
	int n = ri(), m = ri();
	struct Query {
		int l;
		int r;
		int score;
	};
	Query qs[m];
	for (int i = 0; i < m; i++) qs[i].l = ri() - 1, qs[i].r = ri(), qs[i].score = ri();
	std::sort(qs, qs + m, [] (auto i, auto j) { return i.r < j.r; });
	
	SegTree tree(n);
	int head = 0;
	for (int i = 0; i <= n; i++) {
		while (head < m && qs[head].r == i) tree.add(qs[head].l, qs[head].r, qs[head].score), head++;
		if (i < n) tree.assign(i, tree.max(0, i));
	}
	printf("%lld\n", (long long) std::max<int64_t>(0, tree.max(0, tree.n)));
	return 0;
}
