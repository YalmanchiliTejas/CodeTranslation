#include <bits/stdc++.h>

const int N = 105, mod = 1000000007;
typedef long long LL;

int pow(int x, int y, int ans = 1) {
	for (; y; y >>= 1, x = (LL) x * x % mod)
		if (y & 1) ans = (LL) ans * x % mod;
	return ans;
}

int n, p, h[N];

std::pair<int, int> solve(int l, int r, int base) {
	int x = h[l], w = 0;
	for (int i = l; i <= r; ++i)
		x = std::min(x, h[i]);
	for (int i = l; i <= r; ++i)
		if (h[i] == x) ++w;
	int prod0 = 1, prod1 = 1, lst = l - 1;
	for (int i = l; i <= r + 1; ++i)
		if (i > r || h[i] == x) {
			if (i - 1 > lst)  {
				auto t = solve(lst + 1, i - 1, x);
				prod0 = (LL) prod0 * (t.first + t.second) % mod;
				prod1 = (LL) prod1 * t.second % mod;
			}
			lst = i;
		}
	int t = pow(2, x - base);
	prod0 = (pow(2, w, prod0) + (LL) (t + mod - 2) * prod1) % mod;
	prod1 = (LL) t * prod1 % mod;
	return {prod0, prod1};
}
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> h[i];
	std::cout << solve(1, n, 0).first << '\n';
	return 0;
}