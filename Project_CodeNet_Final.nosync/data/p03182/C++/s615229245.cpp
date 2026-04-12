#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
template <typename T>
inline void read(T &x) {
	x = 0;
	char ch = 0;
	bool sign = false;
	while (ch < '0' || '9' < ch) sign |= ch == '-', ch = getchar();
	while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	x = sign ? -x : x;
}
template <typename T>
inline void print(T x) {
	static char outp[64];
	if (!x) { putchar('0'); return; }
	if (x < 0) putchar('-'), x = -x;
	int tot = 0;
	while (x) outp[tot++] = x % 10 + '0', x /= 10;
	while (tot) putchar(outp[--tot]);
}
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
#define fst first
#define sed second
#define pb push_back
#define mp make_pair
#define rt register int
#define all(it) it.begin(), it.end()
#define rep(it, f, e) for (rt it = f; it <= e; ++it)
#define per(it, f, e) for (rt it = f; it >= e; --it)
const int MAXN = 2e5 + 10;
const int Sz = MAXN << 2; // (1 << 19) + 10;
vector<pii> bck[MAXN];
struct Node {
	#define lson (root << 1)
	#define rson (root << 1 | 1)
	#define mid ((tree[root].lt + tree[root].rg) >> 1)
	struct Point {
		int lt, rg;
		ll mn, vl;
	}	tree[Sz];
	inline void build(int root, int l, int r) {
		tree[root].lt = l;
		tree[root].rg = r;
		if (l == r) return;
		build(lson, l, mid);
		build(rson, mid + 1, r);
	}
	inline void change(int root, int x, ll p) {
		if (tree[root].lt == tree[root].rg) {
			tree[root].vl = p;
			tree[root].mn = p;
			return;
		}
		pushdown(root);
		if (x <= mid) change(lson, x, p);
		else change(rson, x, p);
		update(root);
	}
	inline void pushdown(int root) {
		tree[lson].vl += tree[root].vl;
		tree[lson].mn += tree[root].vl;
		tree[rson].vl += tree[root].vl;
		tree[rson].mn += tree[root].vl;
		tree[root].vl = 0;
	}
	inline void update(int root) {
		tree[root].mn = min(tree[lson].mn, tree[rson].mn);
	}
	inline void plus(int root, int l, int r, ll p) {
		if (l <= tree[root].lt && r >= tree[root].rg) {
			tree[root].vl += p;
			tree[root].mn += p;
			return;
		}
		pushdown(root);
		if (l <= mid) plus(lson, l, r, p);
		if (r > mid) plus(rson, l, r, p);
		update(root);
	}
	inline ll query(int root, int l, int r) {
		if (l <= tree[root].lt && r >= tree[root].rg) {
			return tree[root].mn;
		}
		ll ret = 1e18;
		pushdown(root);
		if (l <= mid) ret = min(ret, query(lson, l, r));
		if (r > mid) ret = min(ret, query(rson, l, r));
		return ret;
	}
	#undef lson
	#undef rson
	#undef mid
}	Tree;
int main() {
	int l, n;
	read(l), read(n);
	ll s = 0;
	rep (i, 1, n) {
		int u, v, e;
		read(u), read(v), read(e);
		bck[v].pb(mp(u, e));
		s += e;
	}
	Tree.build(1, 0, l);
	rep (i, 1, l) {
		ll d = Tree.query(1, 0, i - 1);
		Tree.change(1, i, d);
		for (auto t : bck[i]) {
			Tree.plus(1, 0, t.fst - 1, t.sed);
		}
	}
	print(s - Tree.query(1, 0, l)), puts("");
	return 0;
}