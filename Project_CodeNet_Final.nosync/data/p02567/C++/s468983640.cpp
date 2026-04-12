#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
template <typename T, typename E>
struct SegmentTree {
	typedef function<T(T, T)> F;
	typedef function<T(T, E)> G;
	int n, N;
	F f;
	G g;
	T d1;
	E d0;
	vector<T> dat;
	SegmentTree(){};
	SegmentTree(int n_, F f, G g, T d1, vector<T> v = vector<T>()) : f(f), g(g), d1(d1) {
		N = n_;
		init(n_);
		if (n_ == (int)v.size()) build(n_, v);
	}
	void init(int n_) {
		n = 1;
		while (n < n_) n *= 2;
		dat.clear();
		dat.resize(2 * n - 1, d1);
	}
	void build(int n_, vector<T> v) {
		for (int i = 0; i < n_; i++) dat[i + n - 1] = v[i];
		for (int i = n - 2; i >= 0; i--) dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
	}
	void update(int k, E a) {
		k += n - 1;
		dat[k] = g(dat[k], a);
		while (k > 0) {
			k = (k - 1) / 2;
			dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}
	inline T query(int a, int b) {
		T vl = d1, vr = d1;
		for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) vl = f(vl, dat[(l++) - 1]);
			if (r & 1) vr = f(dat[(--r) - 1], vr);
		}
		return f(vl, vr);
	}

	template <bool (*h)(T)>
	int max_right(int l) {
		return max_right(l, [](T x) { return h(x); });
	}
	template <class H>
	int max_right(int l, H h) {
		assert(0 <= l && l <= N);
		assert(h(d1));
		if (l == N) return N;
		l += n - 1;
		T tm = d1;
		do {
			while (l & 1) l = (l - 1) / 2;
			if (!h(f(tm, dat[l]))) {
				while (l < n - 1) {
					l = (2 * l + 1);
					if (h(f(tm, dat[l]))) {
						tm = f(tm, dat[l]);
						l++;
					}
				}
				return l - n + 1;
			}
			tm = f(tm, dat[l]);
			l++;
		} while (((l + 1) & -(l + 1)) != (l + 1));
		return N;
	}

	template <bool (*h)(T)>
	int min_left(int r) {
		return min_left(r, [](T x) { return h(x); });
	}
	template <class H>
	int min_left(int r, H h) {
		assert(0 <= r && r <= N);
		assert(h(d1));
		if (r == 0) return 0;
		r += n;
		T tm = d1;
		do {
			r--;
			while (r > 1 && (r % 2)) r >>= 1;
			if (!h(f(dat[r], tm))) {
				while (r < n) {
					r = (2 * r + 1);
					if (h(f(dat[r], tm))) {
						tm = f(dat[r], tm);
						r--;
					}
				}
				return r + 1 - n + 1;
			}
			tm = f(dat[r], tm);
		} while ((r & -r) != r);
		return 0;
	}
};
int target;
bool f(int x) { return x < target; }
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	vector<int> vec(n);
	rep(i, n) cin >> vec[i];
	SegmentTree<int, int> seg(
	    n, [](int a, int b) { return max(a, b); }, [](int a, int b) { return b; }, -1, vec);
	for (int i = 0; i < q; i++) {
		int c, x, y;
		cin >> c >> x >> y;
		if (c == 2)
			cout << seg.query(x - 1, y) << endl;
		else if (c == 1)
			seg.update(x - 1, y);
		else {
			target = y;
			x--;
			cout << seg.max_right<f>(x) + 1 << endl;
		}
	}
	return 0;
}