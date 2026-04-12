#include <bits/stdc++.h>
#define REP(i, a, b) for(int i(a); i <= (b); ++i)

#define gc getchar()
struct Reader {
	template <class T> inline operator T() {
		T w; char c, p = 0;
		for(; !isdigit(c = gc); c == '-' && (p = 1));
		for(w = c & 15; isdigit(c = gc); w = w * 10 + (c & 15));
		return p ? -w : w;
	}
} rd;

template <class T> inline bool smin(T&x, const T&y) { return y < x ? x = y, 1 : 0; }
template <class T> inline bool smax(T&x, const T&y) { return x < y ? x = y, 1 : 0; }

typedef long long ll;
#define int ll
const int N(2e5 + 5);
namespace SGT {
ll add[N << 2], max[N << 2];
#define ls o << 1
#define rs o << 1 | 1
inline void update(int o, int l, int r, int x, int y, int z) {
	if (x <= l && r <= y) return max[o] += z, add[o] += z, void();
	int mid = l + r >> 1;
	if (x <= mid) update(ls, l, mid, x, y, z);
	if (y > mid) update(rs, mid + 1, r, x, y, z);
	max[o] = add[o] + std::max(max[ls], max[rs]);
}
inline ll ask(int o, int l, int r, int x, int y) {
	if (x <= l && r <= y) return max[o];
	int mid = l + r >> 1;
	if (y <= mid) return add[o] + ask(ls, l, mid, x, y);
	if (x > mid) return add[o] + ask(rs, mid + 1, r, x, y);
	return std::max(ask(ls, l, mid, x, y), ask(rs, mid + 1, r, x, y)) + add[o];
}
#undef ls
#undef rs

}
#define ALL 1, 0, n
#define add(a, b, c) SGT::update(ALL, a, b, c)
#define ask(a, b) SGT::ask(ALL, a, b)
std::vector<std::pair<int, int>> g[N];
signed main() {
	int n = rd, m = rd;
	while (m--) {
		int l = rd, r = rd, w = rd;
		g[r].push_back({l, w});
	}
	REP(i, 1, n) {
		add(i, i, ask(0, i - 1));
		for (auto &u : g[i]) add(u.first, i, u.second);
	}
	std::cout << std::max(0ll, ask(0, n));
	return 0;
}
