#include "bits/stdc++.h"
using namespace std;
using lint = long long;
#define low lower_bound
#define upp upper_bound
#define rep(i, n) for (lint i = 0; i < lint(n); ++i)
#define Rep(i, n) for (lint i = lint(n); i >= 0; --i)
#define all(vec) (vec).begin(), (vec).end()
#define cend printf("\n");
#define prique(T) priority_queue<T, vector<T>, greater<T>>
#define prique2(T) priority_queue<T>

struct edge { int to; double cost; };
using P = pair<lint, lint>;
using D = pair<double, double>;
using DI = pair<double, int>;
//const lint mod = 998244353LL;
const lint mod = 1000000007LL;
const lint inf = 3LL * mod * mod;

template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

lint modpow(lint x, lint n, lint m) {
	lint ans = 1;
	while (n > 0) {
		if (n & 1) {
			ans *= x;
			if (m <= ans) ans %= m;
		}
		x *= x;
		if (m <= x) x %= m;
		n >>= 1;
	}
	return ans;
}

lint fact[1000000];
void f_init(lint n) {
	if (1000000 <= n) return;
	fact[0] = fact[1] = 1;
	for (lint i = 2; i <= n; ++i) {
		fact[i] = i * fact[i - 1];
		if (mod <= fact[i]) fact[i] %= mod;
	}
	return;
}

lint inver[1000000]; bool inve[100000];
lint inv(lint x) {
	if (x == 0) return 0;
	else if (inve[x]) return inver[x];
	else {
		inve[x] = true;
		return inver[x] = modpow(x, mod - 2, mod);
	}
}

lint comb(lint n, lint r) {
	if (n < r) return 0;
	if (n == r) return 1;
	lint ans = fact[n] * inv(fact[n - r]) % mod * inv(fact[r]) % mod;
	if (ans < 0) return ans + mod;
	return ans;
}

lint nck[1010][1010];
void comb(lint n) {
	rep(i, n + 1) {
		rep(j, i + 1) {
			if (j == 0 || i == j) nck[i][j] = 1;
			else nck[i][j] = nck[i - 1][j - 1] + nck[i - 1][j];
		}
	}
}

lint gcd(lint a, lint b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

lint lcm(lint a, lint b) { return a / gcd(a, b) * b; }

bool pri(lint p) {
	for (lint i = 2; i * i <= p; i == 2 ? ++i : i += 2) if (p % i == 0) return false;
	return p > 1;
}

map<lint, lint> factring(lint n) {
	map<lint, lint>ans;
	for (lint i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			n /= i;
			++ans[i];
		}
	}
	if (n != 1) ++ans[n];
	return ans;
}

double dis(D a, D b) { return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)); }

lint n, k, cnt;
int main() {
	cin >> n >> k;
	for (lint b = k + 1; b <= n; ++b) {
		cnt += n / b * (b - k);
		cnt += max(0LL, n % b - k + 1);
	}
	if (k == 0) cnt -= n;
	cout << cnt << endl;
}