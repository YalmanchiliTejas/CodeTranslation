#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
class fenwick_tree {
	const int n;
	vector<T> data;
public:
	fenwick_tree(int n_) : n(n_), data(n) {}
	T find(int p) const {
		T res = 0;
		while (p >= 0) {
			res += data[p];
			p = (p & (p + 1)) - 1;
		}
		return res;
	}
	T find(int l, int r) const {
		return find(r) - find(l - 1);
	}
	void add(int p, T val) {
		while (p < n) {
			data[p] += val;
			p |= p + 1;
		}
	}
};

struct RMQ {
	using type = int;
	static type id() { return INT_MAX; }
	static type op(const type& l, const type & r) { return min(l, r); }
};

template <typename M>
class segment_tree {
	using T = typename M::type;
	const int n;
	vector<T> data;
	int expand(int x) {
		int res;
		for (res = 1; res < x; res <<= 1);
		return res;
	}
public:
	segment_tree(int n_) : n(expand(n_)), data(n * 2, M::id()) {}
	segment_tree(int n_, T val) : n(expand(n_)), data(n * 2, val) {}
	void init(const vector<T>& data_) {
		for (int i = 0; i < (int)data_.size(); i++)
			data[i + n] = data_[i];
		for (int i = n - 1; i >= 0; i--)
			data[i] = M::op(data[i * 2], data[i * 2 + 1]);
	}
	void update(int p, T val) {
		data[p += n] = val;
		while (p >>= 1) data[p] = M::op(data[p * 2], data[p * 2 + 1]);
	}
	void add(int p, T val) {
		data[p += n] += val;
		while (p >>= 1) data[p] = M::op(data[p * 2], data[p * 2 + 1]);
	}
	T find(int l, int r) {
		l += n; r += n + 1;
		T res1 = M::id(), res2 = M::id();
		while (l < r) {
			if (l & 1) res1 = M::op(res1, data[l++]);
			if (r & 1) res2 = M::op(data[--r], res2);
			l >>= 1; r >>= 1;
		}
		return M::op(res1, res2);
	}
};

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	auto xs = x;
	sort(xs.begin(), xs.end());
	for (int i = 0; i < N; i++) {
		x[i] = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin();
	}
	ll rev = 0;
	fenwick_tree<int> ft(N);
	for (int i = 0; i < N; i++) {
		rev += i - ft.find(x[i]);
		ft.add(x[i], 1);
	}
	if (rev <= K) {
		for (int i = 0; i < N; i++) {
			printf("%d\n", xs[x[i]]);
		}
		return 0;
	}
	rev -= K;
	vector<int> pos(N);
	for (int i = 0; i < N; i++) {
		pos[x[i]] = i;
	}
	vector<int> top;
	segment_tree<RMQ> st(N);
	for (int i = 0; i < N; i++) {
		st.update(pos[i], i);
	}
	while (rev > 0) {
		int t;
		{
			int lb = -1, ub = N - 1;
			while (ub - lb > 1) {
				int c = (lb + ub) >> 1;
				if (ft.find(c) <= rev) {
					lb = c;
				}
				else {
					ub = c;
				}
			}
			t = ub;
		}
		int id = st.find(0, t);
		assert(0 <= id && id < N);
		ft.add(pos[id], -1);
		rev -= ft.find(pos[id]);
		st.update(pos[id], INT_MAX);
		top.push_back(id);
	}
	vector<int> res(N);
	for (int i = 0, j = 0; i < N; i++) {
		if (i < (int)top.size()) {
			res[i] = top[i];
		}
		else {
			while (ft.find(j, j) == 0) ++j;
			res[i] = x[j++];
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", xs[res[i]]);
	}
	return 0;
}

