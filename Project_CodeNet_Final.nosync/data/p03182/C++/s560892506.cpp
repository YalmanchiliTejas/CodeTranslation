#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

struct SegTree {
	int n;
	std::vector<int64_t> maxed;
	std::vector<int64_t> added;
	SegTree (int n_) {
		for (n = 1; n < n_; n <<= 1);
		maxed.resize(n << 1, -1000000000000000000);
		added.resize(n << 1);
	}
	void flush(int node) {
		if (added[node]) {
			maxed[node] += added[node];
			if (node < n) {
				added[node << 1] += added[node];
				added[node << 1 | 1] += added[node];
			}
			added[node] = 0;
		}
	}
	void fetch(int node) {
		maxed[node] = std::max(maxed[node << 1], maxed[node << 1 | 1]);
	}
	void assign(int i, int64_t val, int node = 1, int node_l = 0, int node_r = 0) {
		if (!node_r) node_r = n;
		flush(node);
		if (node_l == i && node_r == i + 1) maxed[node] = val;
		else {
			int m = node_l + ((node_r - node_l) >> 1);
			if (i < m) assign(i, val, node << 1, node_l, m);
			else assign(i, val, node << 1 | 1, m, node_r);
			fetch(node);
		}
	}
	int64_t max(int l, int r, int node = 1, int node_l = 0, int node_r = 0) {
		if (!node_r) node_r = n;
		flush(node);
		if (l >= node_r || r <= node_l) return -1000000000000000000;
		if (l <= node_l && r >= node_r) return maxed[node];
		int m = node_l + ((node_r - node_l) >> 1);
		int64_t res = std::max(
			max(l, r, node << 1, node_l, m),
			max(l, r, node << 1 | 1, m, node_r));
		fetch(node);
		return res;
	}
	void add(int l, int r, int val, int node = 1, int node_l = 0, int node_r = 0) {
		if (!node_r) node_r = n;
		flush(node);
		if (l >= node_r || r <= node_l) return;
		if (l <= node_l && r >= node_r) {
			added[node] += val;
			flush(node);
		} else {
			int m = node_l + ((node_r - node_l) >> 1);
			add(l, r, val, node << 1, node_l, m);
			add(l, r, val, node << 1 | 1, m, node_r);
			fetch(node);
		}
	}
};

int main() {
	int n = ri(), m = ri();
	std::vector<std::pair<int, int> > right[n + 1];
	for (int i = 0; i < m; i++) {
		int l = ri();
		int r = ri();
		int val = ri();
		right[r].push_back({l, val});
	}
	SegTree tree(n + 1);
	tree.assign(0, 0);
	for (int i = 1; i <= n; i++) {
		tree.assign(i, tree.max(0, i));
		for (auto j : right[i]) tree.add(j.first, i + 1, j.second);
	}
	std::cout << tree.max(0, tree.n) << std::endl;
	
	return 0;
}
