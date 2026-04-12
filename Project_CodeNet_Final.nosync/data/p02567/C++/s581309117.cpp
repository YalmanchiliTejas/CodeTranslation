#include <atcoder/segtree>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;

int op(int x, int y) { return max(x, y); }

int e() { return -1; }

int target;

bool f(int v) { return v < target; }

int main()
{
	int n, q, t, x, y;
	scanf("%d%d", &n, &q);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	segtree<int, op, e> st(a);
	while (q--) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d", &x, &y);
			st.set(x-1, y);
		}
		else if (t == 2) {
			scanf("%d%d", &x, &y);
			printf("%d\n", st.prod(x-1, y));
		}
		else {
			scanf("%d%d", &x, &target);
			--x;
			printf("%d\n", st.max_right<f>(x)+1);
		}
	}
}