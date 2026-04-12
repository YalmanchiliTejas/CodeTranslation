#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
int op(int a, int b) {
	return max(a, b);
}
int e() {
	return -1;
}
int main() {
	int N, Q;
	cin >> N >> Q;
	segtree<int, op, e> seg(N);
	for (int i = 0; i < N; ++ i) {
		int x;
		cin >> x;
		seg.set(i, x);
	}
	for (int i = 0; i < Q; ++ i) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			seg.set(x-1, y);
		} else if (t == 2) {
			cout << seg.prod(x-1, y) << endl;
		} else {
			cout << seg.max_right(x-1, [y](int v){ return v < y; })+1 << endl;
		}
	}
}
