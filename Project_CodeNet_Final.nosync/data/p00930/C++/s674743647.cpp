#define NDEBUG

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef int type;
constexpr type INIT = (1 << 28);

class segment_tree {
private:
	int n;
	vector<type> value;
	vector<type> lazy;

	static inline type function(type a, type b) {
		return min(a, b);
	}

	void evaluate(int k, int number_of_children) {
		if(lazy[k] == 0) return;
		if(number_of_children > 1) {
			lazy[k * 2 + 1] += lazy[k];
			lazy[k * 2 + 2] += lazy[k];
		}

		value[k] += lazy[k];
		lazy[k] = 0;
	}

	void add(int a, int b, type v, int k, int l, int r) {
		if(r <= a || b <= l) return;
		if(a <= l && r <= b) {
			lazy[k] += v;
		}
		else {
			const int m = (l + r) / 2;
			evaluate(k, r - l);
			add(a, b, v, k * 2 + 1, l, m);
			add(a, b, v, k * 2 + 2, m, r);
			value[k] = function(query(l, m, k * 2 + 1, l, m), query(m, r, k * 2 + 2, m, r));
		}
	}

	type query(int a, int b, int k, int l, int r) {
		if(r <= a || b <= l) return INIT;
		evaluate(k, r - l);
		if(a <= l && r <= b) return value[k];

		const int m = (l + r) / 2;
		const type vl = query(a, b, k * 2 + 1, l, m);
		const type vr = query(a, b, k * 2 + 2, m, r);
		return function(vl, vr);
	}

	int search(int a, int b, type v, int k, int l, int r) {
		if(r <= a || b <= l) return -1;
		evaluate(k, r - l);

		if(v < value[k]) return max(a, l);
		if(r - l == 1) return r;

		const int m = (l + r) / 2;
		const int r_idx = search(a, b, v, k * 2 + 2, m, r);
		if(r_idx != -1 && r_idx != m) return r_idx;
		const int l_idx = search(a, b, v, k * 2 + 1, l, m);
		return l_idx != -1 ? l_idx : m;
	}

public:
	segment_tree(int n_):n(1) {
		while(n < n_) n <<= 1;
		value.resize(2 * n - 1, INIT);
		lazy.resize(2 * n - 1, 0);
	}

	segment_tree(const vector<int> &a):n(1) {
		const int n_ = a.size();
		while(n < n_) n <<= 1;
		value.resize(2 * n - 1, INIT);
		lazy.resize(2 * n - 1, 0);

		for(int i = 0; i < n_; ++i) {
			value[i + n - 1] = a[i];
		}

		for(int i = n - 2; i >= 0; --i) {
			value[i] = function(value[2 * i + 1], value[2 * i + 2]);
		}
	}

	void add(int a, int b, type v) {
		add(a, b, v, 0, 0, n);
	}

	type query(int a, int b) {
		return query(a, b, 0, 0, n);
	}

	int search(int a, int b, type v) {
		return search(a, b, v, 0, 0, n);
	}
};

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	set<int> S;

	int sum = 0;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		if(s[i] == '(') {
			++sum;
		}
		else {
			--sum;
			S.insert(i);
		}

		a[i] = sum;
	}

	segment_tree seg(a);

	while(q--) {
		int p;
		cin >> p;
		--p;

		if(s[p] == '(') {
			s[p] = ')';
			S.insert(p);
			seg.add(p, n, -2);

 			const int res = *S.begin();
			assert(s[res] == ')');

			s[res] = '(';
			S.erase(res);
			seg.add(res, n, 2);

			cout << res + 1 << '\n';
		}
		else {
			s[p] = '(';
			S.erase(p);
			seg.add(p, n, 2);

			const int res = seg.search(0, p + 1, 1);
			assert(s[res] == '(');

			s[res] = ')';
			S.insert(res);
			seg.add(res, n, -2);

			cout << res + 1 << '\n';
		}
	}

	return EXIT_SUCCESS;
}