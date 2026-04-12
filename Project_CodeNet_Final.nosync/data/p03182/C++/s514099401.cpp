#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
typedef pair<int, ll> P;
class BiOp1 {
public:
	ll operator()(ll a, ll b) const {
		return max(a, b);
	}
};
class BiOp2 {
public:
	ll operator()(ll a, ll b) const {
		return a + b;
	}
};
class BiOp3 {
public:
	ll operator()(ll a, ll b) {
		return a + b;
	}
};
template<class T1, class T2, class BiOp1, class BiOp2, class BiOp3>
struct LazySegmentTree {
	//BiOp1:T1×T1->T1
	//BiOp2:T2×T2->T2
	//BiOp3:T1×T2->T1
	vector<T1> data;
	vector<T2> lazy;
	T1 e1;
	T2 e2;
	BiOp1 op1;
	BiOp2 op2;
	BiOp3 op3;
	int size;
	LazySegmentTree(int n, T1 e1, T2 e2, BiOp1 op1, BiOp2 op2, BiOp3 op3) :e1(e1), e2(e2), op1(op1), op2(op2), op3(op3) {
		size = 1;
		while (size < n) size *= 2;
		data.resize(size * 2 - 1);
		lazy.resize(size * 2 - 1);
		for (int i = 0; i < size * 2 - 1; i++) {
			data[i] = e1;
			lazy[i] = e2;
		}
	}
	void push(int k) {
		if (lazy[k] == e2) return;
		if (k < size) {
			lazy[k * 2 + 1] = op2(lazy[k * 2 + 1], lazy[k]);
			lazy[k * 2 + 2] = op2(lazy[k * 2 + 2], lazy[k]);
		}
		data[k] = op3(data[k], lazy[k]);
		lazy[k] = e2;
	}
	T1 query(int a, int b) {
		return query(a, b, 0, 0, size);
	}
	T1 query(int a, int b, int k, int l, int r) {
		if (b <= l || r <= a) return e1;
		if (a <= l && r <= b) return op3(data[k], lazy[k]);
		push(k);
		return op1(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
	}
	T1 get(int x) {
		return query(x, x + 1, 0, 0, size);
	}
	void update(int a, int b, T2 v, int k, int l, int r) {
		if (b <= l || r <= a) return;
		if (a <= l && r <= b) {
			lazy[k] = op2(lazy[k], v);
			return;
		}
		push(k);
		update(a, b, v, k * 2 + 1, l, (l + r) / 2);
		update(a, b, v, k * 2 + 2, (l + r) / 2, r);
		data[k] = op1(op3(data[k * 2 + 1], lazy[k * 2 + 1]), op3(data[k * 2 + 2], lazy[k * 2 + 2]));
	}
	void update(int a, int b, T2 v) {
		update(a, b, v, 0, 0, size);
	}
};
vector<P> range[200000];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int l, r;
		ll a;
		cin >> l >> r >> a;
		l--; r--;
		range[r].emplace_back(l, a);
	}
	LazySegmentTree<ll, ll, BiOp1, BiOp2, BiOp3> S(N, 0, 0, BiOp1(), BiOp2(), BiOp3());
	for (int i = 0; i < N; i++) {
		if (i > 0) {
			ll x = S.query(0, i);
			S.update(i, i + 1, x);
		}
		for (P p : range[i]) {
			S.update(p.first, i + 1, p.second);
		}
	}
	cout << max(0LL, S.query(0, N)) << endl;
}