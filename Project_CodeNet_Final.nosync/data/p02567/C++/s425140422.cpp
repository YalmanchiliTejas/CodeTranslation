#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

int n, q, t, x, v, l, r;
int op(int a, int b) {
	return max(a, b);
}
int e() {
	return -1;
}
bool f(int i) {
	return i < v;
}

int main() {
	cin >> n >> q;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	atcoder::segtree<int, op, e> seg(a);
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> x >> v;
			seg.set(x - 1, v);
		} else if (t == 2) {
			cin >> l >> r;
			cout << seg.prod(l - 1, r) << endl;
		} else {
			cin >> x >> v;
			cout << seg.max_right<f>(x - 1) + 1 << endl;
		}
	}
}