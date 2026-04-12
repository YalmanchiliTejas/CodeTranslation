#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>

using namespace std;
using lint = int64_t;
using P = pair<int, int>;

#define rep(i, n) for (lint i = 0; i < (n); ++i)
#define rep1(i, n) for (lint i = 1; i < (n); ++i)
#define repn(i, a, b) for(lint i = (a); i < (b); ++i)
#define Rep(i, n) for (lint i = (n); i >= 0; --i)
#define All(vec) vec.begin(), vec.end()
#define cend printf("\n")

//constexpr lint mod = 998'244'353LL;
constexpr lint mod = 1000'000'007LL;
constexpr lint inf = 3LL * mod * mod;
constexpr double Pi = 3.141592653589793;

template<class T> using prique     = priority_queue<T>;
template<class T> using prique_inv = priority_queue<T, vector<T>, greater<T>>;
template<class T, class U>inline istream& operator>>(istream& is, pair<T, U>& rhs) { return is >> rhs.first >> rhs.second; }
template<class T, class U>inline ostream& operator<<(ostream& os, const pair<T, U>& rhs) { return os << rhs.first << " " << rhs.second; }
template<class InputIterator> void arrin(InputIterator first, InputIterator last) { for (; first != last; ++first) cin >> (*first); }
template<class InputIterator> void arrout(InputIterator first, InputIterator last) {
	for (; first != last; ++first) {
		cout << (*first) << ((first + 1) != last ? " " : "\n");
	}
}

constexpr bool pri(lint x) { for (lint i = 2; i * i <= x; ++i) if (x % i == 0) return false; return 1 < x; }

lint fact[3000000];
void fact_init(lint n, lint m = mod) {
	if (3000000 <= n) return;
	fact[0] = fact[1] = 1;
	for (lint i = 2; i <= n; ++i) {
		fact[i] = i * fact[i - 1] % m;
	}
}

lint modpow(lint x, lint n, lint m = mod) {
	lint res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % m;
		x = x * x % m;
		n >>= 1;
	}
	return res;
}

lint intpow(lint x, lint n) {
	lint res = 1;
	while (n > 0) {
		if (n & 1) res *= x;
		x *= x;
		n >>= 1;
	}
	return res;
}

lint comb(lint n, lint r, lint m = mod) {
	if (r == 0 || r == n) return 1;
	lint res = fact[n] * modpow(fact[n - r], m - 2, m) % m * modpow(fact[r], m - 2, m) % m;
	return res < 0 ? res + m : res;
}

map<lint, lint> factring(lint n) {
	map<lint, lint> res;
	for (lint i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			n /= i;
			++res[i];
		}
	}
	if (n != 1) ++res[n];
	return res;
}

lint n, m, k, ans;
int main() {
	cin >> n >> m >> k;
	fact_init(n * m + 10);
	rep(i, n) {
		rep(j, m) {
			if (i == 0 && j == 0) continue;
			lint cnt1 = 2 * (n - i) * (m - j) * (i + j);
			if (i == 0 || j == 0) cnt1 >>= 1;
			ans += cnt1 % mod;
			ans %= mod;
		}
	}
	cout << ans * comb(n * m - 2, k - 2) % mod << endl;
}