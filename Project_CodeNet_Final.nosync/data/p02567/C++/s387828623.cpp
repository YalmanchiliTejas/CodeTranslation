#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int f(int a, int b) {
	return max(a, b);
}
int e() {
	return -1;
};
int lt_v;
bool lt(int v) {
	return v < lt_v;
};

int main() {
	int n, q; cin >> n >> q;
	vector<int> v(n); for(int& i : v) cin >> i;
	segtree<int, f, e> seg(v);
	while(q--) {
		int t, x, y; cin >> t >> x >> y;
		if(t == 1) {
			--x;
			seg.set(x, y);
		}
		if(t == 2) {
			--x;
			cout << seg.prod(x, y) << '\n';
		}
		if(t == 3) {
			--x;
			lt_v = y;
			cout << seg.max_right<lt>(x) + 1 << '\n';
		}
	}
	return 0;
}
