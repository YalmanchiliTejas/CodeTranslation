// Making chalk mark on generator: $1
// Knowing where to make mark: $9,999
#include <bits/stdc++.h>
#define when(...) fprintf(stderr,__VA_ARGS__)
typedef long long ll;
ll read() {
	static char c;
	static ll x;
	int flag = 1;
	while (c = getchar(), !isdigit(c))
		if (c == '-') flag = 0;
	x = c - '0';
	while (c = getchar(), isdigit(c))
		x = x * 10 + c - '0';
	return flag ? x : -x;
}

int n, m;
struct line {
	ll l, r, a;
	bool operator<(const line &rhs) const {return r < rhs.r;}
} ns[200200];

struct segmenttree {
#define lc x<<1
#define rc x<<1|1
#define mid ((l+r)>>1)
	ll ns[800800], tag[800800];
	inline void pushdown(int x, int l, int r) {
		if (!tag[x]) return ;
		if (l != r) {
			tag[lc] += tag[x];
			tag[rc] += tag[x];
		}
		ns[x] += tag[x];
		tag[x] = 0;
	}
	ll query(int ql, int qr, int x = 1, int l = 0, int r = n) {
		pushdown(x, l, r);
		if (l >= ql && r <= qr) return ns[x];
		ll ans = -1e18;
		if (ql <= mid) ans = std::max(ans, query(ql, qr, lc, l, mid));
		if (qr > mid) ans = std::max(ans, query(ql, qr, rc, mid + 1, r));
		return ans;
	}
	void update(int ql, int qr, ll delta, int x = 1, int l = 0, int r = n) {
		pushdown(x, l, r);
		if (l >= ql && r <= qr) return tag[x] += delta, void();
		if (ql <= mid) update(ql, qr, delta, lc, l, mid);
		if (qr > mid) update(ql, qr, delta, rc, mid + 1, r);
		pushdown(lc, l, mid);
		pushdown(rc, mid + 1, r);
		ns[x] = std::max(ns[lc], ns[rc]);
	}
} seg;

signed main() {
	n = read(), m = read();
	for (int i = 1; i <= m; ++i) ns[i].l = read(), ns[i].r = read(), ns[i].a = read();
	std::sort(ns + 1, ns + 1 + m);

	for (int i = 1, cur = 1; i <= n; ++i) {
		seg.update(i, i, seg.query(0, i));
		for (; ns[cur].r == i; ++cur) seg.update(ns[cur].l, ns[cur].r, ns[cur].a);
	}
	printf("%lld\n", seg.query(0, n));
}