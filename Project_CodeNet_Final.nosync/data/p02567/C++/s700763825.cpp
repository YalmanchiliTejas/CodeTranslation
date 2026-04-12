#include <iostream>
#include <vector>
using namespace std;

template<class M> struct SegmentTree
{
	int n;
	int size;
	vector<M> data;
	const function<M(M, M)> op;
	const M ID;

	SegmentTree(int n, function<M(M, M)> op, M id, const vector<M> &init_vals=vector<M>()) : n(n), op(op), ID(id) {
		size = 1;
		while (size < n) size <<= 1;
		data.assign(size * 2, ID);
		for (int i = 0; i < init_vals.size(); i++) data[size+i] = init_vals[i];
		for (int i = size-1; i > 0; i--) data[i] = op(data[2*i], data[2*i+1]);
	}

	void init(const vector<M> &init_vals) {
		data.assign(size * 2, ID);
		for (int i = 0; i < init_vals.size(); i++) data[size+i] = init_vals[i];
		for (int i = size-1; i > 0; i--) data[i] = op(data[2*i], data[2*i+1]);
	}

	void update(int idx, M x) {
		idx += size;
		data[idx] = x;
		while (idx >>= 1) {
			data[idx] = op(data[2*idx], data[2*idx+1]);
		}
	}

	M query(int l, int r) {
		M L = ID, R = ID;
		for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
			if (l & 1) L = op(L, data[l]), l++;
			if (r & 1) r--, R = op(data[r], R);
		}
		return op(L, R);
	}

	M query_all() {
		return data[1];
	}

	int find_max_right(int l, const function<bool(M)> &f) {
		if (l == n) return n;
		l += size;
		M s = ID;
		while (true) {
			while (l % 2 == 0) l >>= 1;
			if (!f(op(s, data[l]))) break;
			s = op(s, data[l]);
			l++;
			if ((l & -l) == l) return n;
		}
		while (l < size) {
			l = 2 * l;
			if (f(op(s, data[l]))) {
				s = op(s, data[l]);
				l++;
			}
		}
		return l - size;
	}

	int find_min_left(int r, const function<bool(M)> &f) {
		if (r == 0) return 0;
		r += size;
		M s = ID;
		while (true) {
			r--;
			while (r > 1 && (r % 2)) r >>= 1;
			if (!f(op(data[r], s))) break;
			s = op(data[r], s);
			if ((r & -r) != r) return 0;
		}
		while (r < size) {
			r = 2 * r + 1;
			if (f(op(data[r], s))) {
				s = op(data[r], s);
				r--;
			}
		}
		return r + 1 - size;
	}

	M val(int idx) {
		return data[size + idx];
	}

	vector<M> val_vec() {
		vector<M> res(n);
		for (int i = 0; i < n; i++) res[i] = data[size+i];
		return res;
	}
};

int main() {
	int n, Q;
	cin >> n >> Q;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	using M = int;
	auto op = [&](M a, M b) -> M {
		return max(a, b);
	};
	M id = -1;
	SegmentTree<M> st(n, op, id, A);
	int thr;
	auto f = [&](M m) -> bool {
		return m < thr;
	};
	for (int q = 0; q < Q; q++) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int x, v;
			scanf("%d%d", &x, &v);
			x--;
			st.update(x, v);
		} else if (type == 2) {
			int l, r;
			scanf("%d%d", &l, &r);
			l--;
			int ans = st.query(l, r);
			cout << ans << '\n';
		} else {
			int x, v;
			scanf("%d%d", &x, &v);
			x--;
			thr = v;
			int ans = st.find_max_right(x, f) + 1;
			cout << ans << '\n';
		}
	}
	return 0;
}