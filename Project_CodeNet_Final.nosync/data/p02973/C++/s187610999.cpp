#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int64_t rll() {
	long long n;
	scanf("%lld", &n);
	return n;
}

struct SegTree {
	std::vector<int> data;
	int n;
	SegTree(int n_) {
		for (n = 1; n < n_; n *= 2);
		data.resize(2 * n);
	}
	void set(int i, int val) {
		for (data[i += n] = val; i >>= 1; ) data[i] = std::max(data[i << 1], data[i << 1 | 1]);
	}
	int max(int l, int r) {
		int res = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (r & 1) {
				r--;
				res = std::max(res, data[r]);
			}
			if (l & 1) {
				res = std::max(res, data[l]);
				l++;
			}
		}
		return res;
	}
};

int main() {
	int n = ri();
	int a[n];
	for (int i = 0; i < n; i++) a[i] = ri();
	std::set<int> all;
	for (int i = 0; i < n; i++) all.insert(a[i]);
	std::map<int, int> comp;
	std::vector<int> decomp;
	int cnt = 0;
	for (auto i : all) comp[i] = cnt++, decomp.push_back(i);
	SegTree tree(all.size());
	for (int i = 0; i < n; i++) {
		tree.set(comp[a[i]], std::max(tree.data[tree.n + comp[a[i]]], tree.max(comp[a[i]], tree.n) + 1));
	}
	std::cout << tree.max(0, tree.n) << std::endl;
	
	return 0;
}
