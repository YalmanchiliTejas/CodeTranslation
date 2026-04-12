#include "bits/stdc++.h"
using namespace std;
using lint = long long;
#define low lower_bound
#define upp upper_bound
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define Rep(i, n) for (int i = int(n); i >= 0; --i)
#define all(vec) (vec).begin(), (vec).end()
#define cend printf("\n");
#define prique(T) priority_queue<T, vector<T>, greater<T>>
#define prique2(T) priority_queue<T>

struct edge { lint to; lint cost; };
using P = pair<lint, lint>;
using D = pair<long double, long double>;
using mll = map<lint, lint>;
//const lint mod = 998244353LL;
const lint mod = 1000000007LL;
const lint inf = 3LL * mod * mod;
const double Pi = acos(-1.0);

template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmin(T& a, T b) {
	return chmax(b, a);
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

lint comb(lint n, lint r) {
	if (n < r) return 0;
	if (n == r) return 1;
	lint ans = fact[n] * modpow(fact[n - r], mod - 2, mod) % mod * modpow(fact[r], mod - 2, mod) % mod;
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

mll factring(lint n) {
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

lint xor128() {
	static lint x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	lint t = (x xor (x << 11));
	x = y; y = z; z = w;
	return (w = (w xor (w >> 19)) xor (t xor (t >> 8)));
}

double dis(D a, D b) {
	double x = a.first - b.first, y = a.second - b.second;
	return sqrt(x * x + y * y);
}

//外心を求める
D circum(D x, D y, D z) {
	long double a1, a2, b1, b2, c1, c2;
	long double da, db, dc; //距離
	long double a, b, c; //cos
	long double o, ox, oy;
	a1 = x.first, a2 = x.second, b1 = y.first, b2 = y.second, c1 = z.first, c2 = z.second;
	dc = dis(D(a1, a2), D(b1, b2));
	da = dis(D(b1, b2), D(c1, c2));
	db = dis(D(c1, c2), D(a1, a2));
	a = (db * db + dc * dc - da * da) / (2 * db * dc);
	b = (dc * dc + da * da - db * db) / (2 * dc * da);
	c = (da * da + db * db - dc * dc) / (2 * da * db);
	o = a * da + b * db + c * dc;
	ox = (a1 * a * da + b1 * b * db + c1 * c * dc) / o;
	oy = (a2 * a * da + b2 * b * db + c2 * c * dc) / o;
	return D(ox, oy);
}

class unionfind {
private:
	int par[2 * 100010], ranks[2 * 100010], sizeth[2 * 100010];
public:
	void init(int n) {
		for (int i = 0; i < n; ++i) {
			par[i] = i;
			ranks[i] = 0;
			sizeth[i] = 1;
		}
	}

	int root(int x) {
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	void unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return;
		if (ranks[x] < ranks[y]) {
			par[x] = y;
			sizeth[y] += sizeth[x];
		}
		else {
			par[y] = x;
			if (ranks[x] == ranks[y]) ++ranks[x];
			sizeth[x] += sizeth[y];
		}
	}
};


int main() {
	int n, m;
	cin >> n >> m;
	if (n == m) cout << "Yes" << endl;
	else cout << "No" << endl;
}