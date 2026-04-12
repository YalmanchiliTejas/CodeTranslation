#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

/* debug macros */
#ifdef WAFDAYO
#define DBG_PRINT(s, t, u) { std::cerr << s << " \e[2m=\e[m \e[1m" << t << "\e[m" << u; }
#else
#define DBG_PRINT(s, t, u) {}
#endif
#define dbg(x) DBG_PRINT(#x, x, std::endl)
#define dbgn(x) DBG_PRINT(#x, x, ", ")
#define idbg(x, i) DBG_PRINT(#x "[" << i << "]", x[i], std::endl)
#define idbgn(x, i) DBG_PRINT(#x "[" << i << "]", x[i], ", ")

/* IO utilities */
struct read_input { read_input() {}; template<class T> operator T() { T t; std::cin >> t; return t; } };

/* types and constants */
typedef long long i64;
const i64 inf = (i64)1.05e18;
// const int inf = (int)1.05e9;
const i64 mod = 998244353;

i64 modpow(i64 x, i64 a) {
	i64 y = 1;
	for(int i = 0; i < 63; i++) {
		if((a >> i) & 1LL) {
			y = y * x % mod;
		}
		x = x * x % mod;
	}
	return y;
}

int main() {

	int n = read_input();

	int inv_lim = max(n, 10);
	vector<i64> inv(inv_lim + 1);

	inv[1] = 1;
	for(int i = 2; i <= inv_lim; i++) {
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	}

	vector<i64> fact(n + 1);
	vector<i64> fact_inv(n + 1);

	fact[0] = fact_inv[0] = 1;
	for(int i = 1; i <= n; i++) {
		fact[i] = fact[i - 1] * i % mod;
		fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
	}

	i64 ans = modpow(3, n);
	i64 r = modpow(2, n / 2);

	for(int k = n / 2 + 1; k <= n; k++) {
		r = r * inv[2] % mod;
		i64 nck = fact[n] * (fact_inv[n - k] * fact_inv[k] % mod) % mod;
		i64 s = nck * r * 2 % mod;
		ans = ans - s;
		if(ans < 0) {
			ans += mod;
		}
	}

	printf("%lld\n", ans);

	return 0;
}
