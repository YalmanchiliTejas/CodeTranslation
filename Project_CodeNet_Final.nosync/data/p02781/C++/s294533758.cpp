#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <numeric>
#include <stack>
#include <iomanip>
#include <random>
#include <complex>
#include <functional>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; ++i)
#define rep(i,b) Rep(i,0,b)
#define allof(a) (a).begin(), (a).end()

#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")

using ll = long long;

using pint = std::pair<int, int>;
using pll = std::pair<ll, ll>;


constexpr int inf = 1e9 + 7;
constexpr ll infll = 1ll << 60ll;
constexpr ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

namespace {
	template<typename T> void chmax(T& a, T b) { a = std::max(a, b); }
	template<typename T> void chmin(T& a, T b) { a = std::min(a, b); }
	template<typename T> void chadd(T& a, T b) { a = a + b; }

	void Cout(long long x, const char* end = "\n") { std::cout << x << end; }
	template <typename T> void Cout(const T& x, const char* end = "\n") { std::cout << x << end; }
	template <typename T> void Cout(const std::vector<T>& x, const char* sep = " ", const char* end = "\n") { for (std::size_t i = 0, sz = x.size(); i < sz; i++) { std::cout << x[i] << (i == sz - 1 ? end : sep); } }


	// 標準入出力
	struct inp {
		std::size_t sz;
		inp(std::size_t _sz = 1) : sz(_sz) {}
		template <typename T> operator T () const { T a; std::cin >> a; return a; }
		template <typename T> operator std::vector<T>() const { vector<T> a(sz); for (std::size_t i = 0; i < sz; i++) std::cin >> a[i]; return a; }
		template <typename T, typename U> operator std::pair<T, U>() const { T f; U s; std::cin >> f >> s; return std::pair<T, U>(f, s); }
	};

	inp inp1; // input one

	ll powll(ll a, ll n) {
		ll result = 1;
		ll base = a;
		ll mask = 1;
		while (mask <= n) {
			if (n & mask) (result *= base) %= mod;
			mask <<= 1;
			(base *= base) %= mod;
		}
		return result;
	}

	// 素因数分解 O(√N)
	template <typename T>
	std::vector<T> Factorize2Vector(T x) {
		if (x <= 1) return std::vector<T>();
		std::vector<T> r; T x0 = x;
		while (x % 2 == 0)
			x /= 2, r.push_back(2);
		for (long long f = 3; f * f <= x0; f += 2)
			while (x % f == 0)
				x /= f, r.push_back(f);
		if (x > 1) r.push_back(x);
		return r;
	}
	template<typename T>
	std::map<T, T> Factorize2Map(T x) {
		if (x <= 1) return std::map<T, T>();
		std::map<T, T> mp;
		for (T i = 2; i * i <= x; ++i) {
			while (x % i == 0) {
				x /= i;
				mp[i]++;
			}
		}
		if (x != 1) {
			mp[x]++;
		}
		return mp;
	}

	// 素因数分解 pair.firstで素数、pair.secondで対応する指数
	std::vector<std::pair<long long, long long> > prime_factorize(long long n) {
		std::vector<std::pair<long long, long long> > res;
		for (long long p = 2; p * p <= n; ++p) {
			if (n % p != 0) continue;
			int num = 0;
			while (n % p == 0) { ++num; n /= p; }
			res.push_back(std::make_pair(p, num));
		}
		if (n != 1) res.push_back(std::make_pair(n, 1));
		return res;
	}

	const int MAX = 2100000;

	//二項係数を求める前処理 テーブルを作る　O(n)
	// facは階乗
	long long fac[MAX], finv[MAX], inv[MAX];
	void COMinit() {
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for (int i = 2; i < MAX; i++) {
			fac[i] = fac[i - 1] * i % mod;
			inv[i] = mod - inv[mod % i] * (mod / i) % mod;
			finv[i] = finv[i - 1] * inv[i] % mod;
		}
	}

	// 二項係数計算
	ll COM(int n, int k) {
		if (n < k) return 0;
		if (n < 0 || k < 0) return 0;
		return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
	}

	// 重複組み合わせ
	ll H(int n, int k) {
		return COM(n + k - 1, k);
	}
}

int main() {

	string n = inp1;
	int k = inp1;
	COMinit();

	// 少なくてもk桁が必要になる
	if (n.length() < k) {
		Cout(0);
		return 0;
	}

	ll ans = 0;

	// 先頭は0でない数

	// digit桁の数字の場合にいくつあるか
	Rep(digit, 1, n.length()) {
		if (digit < k) continue;

		ans += COM(digit - 1, k - 1) * powll(9, k);
	}

	// n.length()桁の時
	int head = 0;
	for (int digit = n.length(); digit > 0; --digit) {
		int d = n.length() - digit;
		// n[d]-1
		if (n[d] == '0') continue;
		//自分を1以上にするとき
		ans += ((n[d] - '0') - 1) * COM(digit - 1, k - 1 - head) * powll(9, k - 1 - head);
		// 自分を0にするとき
		if(d >= 1)
			ans += COM(digit - 1, k - head) * powll(9, k - head);
		if (n[d] != '0') ++head;
	}

	// n自身がどうか
	rep(i, n.length()) {
		if (n[i] != '0') --k;
	}
	if (k == 0) ++ans;

	Cout(ans);

	return 0;
}
