#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>


int op(int a, int b) { return max(a, b); }

int e() { return -1; }

int v;

bool f(int x) { return x < v; }

int main() {
	int n, q, x, ans;
	int t, l, r;
	cin >> n >> q;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		a.eb(x);
	}

	segtree<int, op, e> seg(a);

	for (int i = 0; i < q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> x >> v;
			x--;
			seg.set(x, v);
		}
		else if (t == 2) {
			cin >> l >> r;
			l--;
			ans = seg.prod(l, r);
			cout << ans << endl;
		}
		else if (t == 3) {
			cin >> x >> v;
			x--;
			ans = seg.max_right<f>(x) + 1;
			cout << ans << endl;
		}
	}
}
