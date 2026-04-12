#include <algorithm>
#include <assert.h>
#include <cmath>
#include <iostream>
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

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (lint i = 1; i < (n); ++i)
#define repn(i, a, b) for(lint i = (a); i < (b); ++i)
#define rep_inv(i, n) for (lint i = (n); i >= 0; --i)
#define all(vec) vec.begin(), vec.end()
#define cend printf("\n")

//constexpr lint mod = 998'244'353LL;
constexpr lint Mod = 1000'000'007LL;
constexpr lint Inf = 3'000'000'000'000'000'007LL; //3e18+7
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

bool pri(lint x) { 
	for (lint i = 2; i * i <= x; ++i) {
		if (x % i == 0) return false;
	}
	return 1 < x; 
}

lint fact[3000000];
void fact_init(lint n, lint m = Mod) {
	if (3000000 <= n) return;
	fact[0] = fact[1] = 1;
	for (lint i = 2; i <= n; ++i) {
		fact[i] = i * fact[i - 1] % m;
	}
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

int main() {
	int x;
	cin >> x;
	if (30 <= x) cout << "Yes\n";
	else cout << "No\n";
}