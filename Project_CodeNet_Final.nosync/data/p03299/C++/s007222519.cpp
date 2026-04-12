#include <bits/stdc++.h>
#define fi first
#define se second
#define N 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> Pair;

template <class T> inline void read(T &x) {
	char ch; bool flag = false;
	while (!isdigit(ch = getchar())) flag |= ch == '-';
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	if (flag) x = -x;
}

inline int input() {
	int x; char ch; bool flag = false;
	while (!isdigit(ch = getchar())) flag |= ch == '-';
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return flag ? -x : x;
}

const int mod = 1e9 + 7;
inline int add(int x, int y) { x += y; return x >= mod ? x - mod : x; }
inline void inc(int &x, int y) { x += y; x -= x >= mod ? mod : 0; }

inline int Power(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = (ll) res * x % mod;
		x = (ll) x * x % mod, y >>= 1;
	} return res;
}

template <class T> void chkmax(T &x, T y) { x = x > y ? x : y; }
template <class T> void chkmin(T &x, T y) { x = x < y ? x : y; }
template <class T> T gcd(T x, T y) { return !y ? x : gcd(x % y, y); }

int n;
int h[N];

Pair solve(int l, int r, int lim) {
	bool flag = false; int upp = h[l]; Pair res;
	for (int i = l + 1; i <= r; ++i) {
		flag |= h[i] != h[i - 1];
		chkmin(upp, h[i]);
	}
	if (!flag) {
		res.fi = add(Power(2, r - l + 1), mod - 2);
		res.se = Power(2, upp - lim - 1);
		return res;
	}
	
	int cnt = 0, last = 0, s0 = 1, s1 = 1;
	for (int i = l; i <= r + 1; ++i) {
		if (h[i] == upp) ++cnt;
		if (!last && h[i] > upp) last = i;
		else if (last && (h[i] == upp || i > r)) {
			Pair tmp = solve(last, i - 1, upp);
			s0 = (ll) s0 * (tmp.fi + 4ll * tmp.se % mod) % mod;
			s1 = (ll) s1 * tmp.se * 2 % mod;
			last = 0;
		}
	}
	
	inc(s0, mod - s1);
	res.fi = (ll) s0 * Power(2, cnt) % mod;
	inc(res.fi, (ll) s1 * add(Power(2, cnt), mod - 2) % mod);
	res.se = (ll) s1 * Power(2, upp - lim - 1) % mod;
	return res;
}

int main() {
	n = input();
	for (int i = 1; i <= n; ++i) h[i] = input();
	if (n == 1) return printf("%d\n", Power(2, h[1])), 0;
	ll Ex = 1;
	for (int i = 1; i <= n; ++i) {
		if (h[i] <= h[i - 1] || h[i] <= h[i + 1]) continue;
		Ex = Ex * Power(2, h[i] - max(h[i - 1], h[i + 1])) % mod;
		h[i] = max(h[i - 1], h[i + 1]);
	}
	Pair ans = solve(1, n, 0);
	printf("%lld\n", Ex * add(ans.fi, add(ans.se, ans.se)) % mod);
	return 0;
}