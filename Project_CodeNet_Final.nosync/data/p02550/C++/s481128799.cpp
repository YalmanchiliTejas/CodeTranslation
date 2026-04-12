#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;
using lint = long long;
using P = pair<lint, lint>;

#define rep(i, n) for (lint i = 0; i < (n); ++i)
#define rep1(i, n) for (lint i = 1; i < (n); ++i)
#define repn(i, a, b) for(lint i = (a); i < (b); ++i)
#define rep_inv(i, n) for (lint i = (n); i >= 0; --i)
#define rep_inv1(i, n) for(lint i = (n); i >= 1; --i)
#define all(vec) (vec).begin(), (vec).end()
#define cend printf("\n")
#define pair(f, s) struct { lint f, s; }

constexpr lint Mod = /**/ 1000'000'007LL /*/ 998'244'353LL /**/;
constexpr lint Inf = 4'500'000'000'000'000'007LL; //4.5e18+7
constexpr double Pi = 3.141592653589793;

template<class T> using prique     = priority_queue<T>;
template<class T> using prique_inv = priority_queue<T, vector<T>, greater<T>>;
template<class T> inline bool chmin(T& a, const T& b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, const T& b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline istream& operator>>(istream& is, vector<T>& v) { for (auto& e : v) is >> e; return is; }
template<class T> inline ostream& operator<<(ostream& os, const vector<T>& v) {
	size_t i = 0, n = v.size();
	for (const auto& e : v) {
		os << e;
		if (i + 1 < n) os << " ";
		++i;
	}
	return os;
}
template<class T, class U> inline istream& operator>>(istream& is, pair<T, U>& rhs) { return is >> rhs.first >> rhs.second; }
template<class T, class U> inline ostream& operator<<(ostream& os, const pair<T, U>& rhs) { return os << "{" << rhs.first << ", " << rhs.second << "}"; }
template<class T, class U> inline void print(const T& a, const U& b, bool f) {
	if (f) cout << a << "\n";
	else cout << b << "\n";
}
template<class InputIterator> void arrin(InputIterator first, InputIterator last) { for (; first != last; ++first) cin >> (*first); }
template<class InputIterator> void arrout(InputIterator first, InputIterator last) {
	for (; first != last; ++first) {
		cout << (*first) << ((first + 1) != last ? " " : "\n");
	}
}

bool pri(lint x) { 
	for (lint i = 2; i * i <= x; ++i) {
		if (x % i == 0) return false;
	}
	return 1 < x; 
}

lint fact[3'000'000];
void fact_init(lint n, lint m = Mod) {
	if (3'000'000 <= n) return;
	fact[0] = fact[1] = 1;
	for (lint i = 2; i <= n; ++i) {
		fact[i] = i * fact[i - 1] % m;
	}
}

lint modinv(lint a, lint m = Mod) {
	lint b = m, u = 1, v = 0;
	while (b != 0) {
		lint t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

lint modpow(lint x, lint n, lint m = Mod) {
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

lint comb(lint n, lint r, lint m = Mod) {
	if (r == 0 || r == n) return 1;
	lint res = fact[n] * modinv(fact[n - r], m) % m * modinv(fact[r], m) % m;
	return res < 0 ? res + m : res;
}

class Factring {
private:

	const lint max_n;
	vector<lint> sieve;

public:

	explicit Factring(lint n) :
		max_n(n), sieve(n)
	{
		iota(sieve.begin(), sieve.end(), 0);
		for (lint i = 2; i * i < n; ++i) {
			if (sieve[i] < i) continue;
			for (lint j = i * i; j < n; j += i) {
				if (sieve[j] == j) sieve[j] = i;
			}
		}
	}

	unordered_map<lint, lint> calc(lint x) const {
		assert(x < max_n);

		unordered_map<lint, lint> res;
		while (x > 1) {
			++res[sieve[x]];
			x /= sieve[x];
		}
		return res;
	}
};

lint n, x, m, w, cnt1, cnt2;
vector<lint>vec;
bool used[100010];
int main() {
	cin >> n >> x >> m;

	lint a1 = x;
	while (true) {
		used[a1] = true;
		vec.push_back(a1);
		a1 = a1 * a1 % m;
		if (used[a1]) {
			w = a1;
			break;
		}
	}

	rep(i, vec.size()) {
		if (w == vec[i]) {
			cnt1 = i;
			break;
		}
	}

	cnt2 = vec.size() - cnt1;

	if (n <= cnt1 + 1) {
		cout << accumulate(vec.begin(), vec.begin() + n, 0LL) << endl;
	}
	else {
		lint res = accumulate(vec.begin(), vec.begin() + cnt1, 0LL);
		n -= cnt1;
		lint sum1 = accumulate(vec.begin() + cnt1, vec.end(), 0LL);
		res += n / cnt2 * sum1;
		n %= cnt2;
		res += accumulate(vec.begin() + cnt1, vec.begin() + cnt1 + n, 0LL);
		cout << res << endl;
	}
}