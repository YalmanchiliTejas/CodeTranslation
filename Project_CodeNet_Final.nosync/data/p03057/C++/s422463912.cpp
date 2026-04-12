#include <bits/stdc++.h>

typedef long long LL;
const int N = 200005, mod = 1000000007;

void reduce(int &x) { x += x >> 31 & mod; }


int n, m, f[N], g[N]; std::string s;

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n >> m >> s;
	if (s[0] == 'B') for (char &ch : s) ch ^= 'R' ^ 'B';
	if (std::count(s.begin(), s.end(), 'B')) {
		if (n & 1) return std::cout << "0\n", 0;
		int now = 0, bound = std::find(s.begin(), s.end(), 'B') - s.begin() | 1;
		for (char ch : s) {
			if (ch == 'B') {
				if (now & 1) bound = std::min(bound, now);
				now = 0;
			} else ++now;
		}
		bound = bound + 1 >> 1;
		f[0] = 1, g[0] = 1;
		for (int i = 1; i <= n / 2; ++i) {
			reduce(f[i] = g[i - 1] - (i >= bound + 1 ? g[i - bound - 1] : 0));
			reduce(g[i] = g[i - 1] + f[i] - mod);
		}
		int ans = 0;
		for (int i = 1; i <= bound && i <= n / 2; ++i)
			ans = (ans + 2LL * i * f[n / 2 - i]) % mod;
		std::cout << ans << '\n';
	} else {
		f[0] = 2, f[1] = 1;
		for (int i = 2; i <= n; ++i)
			reduce(f[i] = f[i - 1] + f[i - 2] - mod);
		std::cout << f[n] << '\n';
	}
	return 0;
}