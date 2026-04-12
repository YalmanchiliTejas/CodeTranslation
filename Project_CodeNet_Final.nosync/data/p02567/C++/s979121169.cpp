#include <atcoder/segtree>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

int op(int a, int b) {
	return max(a, b);
}
int e() {
	return -1;
}

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	segtree<int, op, e> st(a);
	for (int i = 0; i < q; ++i) {
		int t, x, y; cin >> t >> x >> y;
		if (t == 1) st.set(x-1, y);
		else if (t == 2) cout << st.prod(x-1, y) << "\n";
		else cout << st.max_right(x-1, [&y](int z) {return z < y;}) + 1 << "\n";
	}
	return 0;
}