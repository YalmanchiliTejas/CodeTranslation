#include <bits/stdc++.h>

using namespace std;

template <typename T>
class seg {
	T t;
	using N = typename T::N;
	using F = typename T::F;
	vector<N> nt;
	vector<F> ft;
	void eval(int p, int l, int r) {
		if (ft[p] == t.IF)
			return;
		nt[p] = t.FN(ft[p], r - l, nt[p]);
		if (l + 1 < r) {
			t.FF(ft[p], ft[p + 1]);
			t.FF(ft[p], ft[p + (r - l & -2)]);
		}
		ft[p] = t.IF;
	}
	N init(N n, int p, int l, int r) {
		if (l + 1 == r)
			return nt[p] = n;
		int m = (l + r) / 2;
		return nt[p] = t.NN(init(n, p + 1, l, m), init(n, p + (r - l & -2), m, r));
	}
	N upd(int a, int b, F f, int p, int l, int r) {
		eval(p, l, r);
		if (b <= l || r <= a)
			return nt[p];
		if (a <= l && r <= b)
			return t.FN(ft[p] = f, r - l, nt[p]);
		int m = (l + r) / 2;
		return nt[p] = t.NN(upd(a, b, f, p + 1, l, m), upd(a, b, f, p + (r - l & -2), m, r));
	}
	N get(int a, int b, int p, int l, int r) {
		if (b <= l || r <= a)
			return t.IN;
		eval(p, l, r);
		if (a <= l && r <= b)
			return nt[p];
		int m = (l + r) / 2;
		return t.NN(get(a, b, p + 1, l, m), get(a, b, p + (r - l & -2), m, r));
	}
public:
	const int s;
	seg(int s) :s(s), nt(s * 2 - 1, t.IN), ft(s * 2 - 1, t.IF) {}
	seg(int s, N n) :seg(s) {
		init(n, 0, 0, s);
	}
	void upd(int a, int b, F f) {
		upd(a, b, f, 0, 0, s);
	}
	N get(int a, int b) {
		return get(a, b, 0, 0, s);
	}
};
struct L {
	typedef long N, F;
	const N IN = 0;
	const F IF = 0;
	N NN(N m, N n) { return max(m, n); }
	N FN(F f, int, N n) { return f + n; }
	void FF(F f, F &g) { g += f; }
};
vector<pair<int, int>> s[222222];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int l, r, a;
		scanf("%d%d%d", &l, &r, &a);
		s[r].emplace_back(l, a);
	}
	seg<L> t(n + 1);
	for (int i = 1; i <= n; i++) {
		t.upd(i, i + 1, t.get(0, i));
		for (auto p : s[i])
			t.upd(p.first, i + 1, p.second);
	}
	cout << t.get(0, n + 1) << endl;
	return 0;
}
