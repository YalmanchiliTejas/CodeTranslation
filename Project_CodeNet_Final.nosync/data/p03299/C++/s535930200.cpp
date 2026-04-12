#include <bits/stdc++.h>
#define EB emplace_back

typedef long long ll;
typedef std::pair <int, int> pr;
typedef std::vector <int> vector;
const int mod = 1000000007, pmod = mod - 1;

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
inline void sub(int &x, const int y) {x -= y, x += x >> 31 & mod;}
ll PowerMod(ll a, int n, ll c = 1) {for (n += n >> 31 & pmod; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

pr solve(const vector &h) {
	int i, j = -1, n = h.size(), x, y = 0, P1 = 1, P2 = 1, C1, C2, W = n;
	vector S; x = *std::min_element(h.begin(), h.end());
	for (i = 0; i <= n; ++i)
		if (i == n || h[i] == x) {
			if (j + 1 == i) ++j;
			else if (j + 2 == i) ++j, P1 = PowerMod(2, h[j] - x, P1), P2 = PowerMod(2, h[j] - x, P2), ++j;
			else {
				W -= i - j - 1, S.clear(), S.reserve(i - j - 1);
				for (++y; ++j < i; S.EB(h[j] - x));
				std::tie(C1, C2) = solve(S), P1 = (ll)P1 * (C1 + C2) % mod, P2 = (ll)P2 * C2 % mod;
			}
		}
	C2 = PowerMod(2, x, P2), C1 = PowerMod(2, W, P1), sub(C1, P2), sub(C1, P2);
	return add(C1, C2), pr(C1, C2);
}

int main() {
	int i, n, x; vector h;
	scanf("%d", &n), h.reserve(n);
	for (i = 0; i < n; ++i) scanf("%d", &x), h.EB(x);
	printf("%d\n", solve(h).first);
	return 0;
}