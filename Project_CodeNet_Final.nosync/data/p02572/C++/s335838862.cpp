#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifdef on_linux
	#include <sys/resource.h>
#endif

#ifdef dobby_is_a_free_elf
	#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
	#define trace(...) 0;
#endif

using namespace std;
using namespace __gnu_pbds;


#define all(x)                  (x).begin(), (x).end()
#define between(i,x,y)          ((i) >= (x) && (i) <= (y))
#define DECIMAL(n)              cout << fixed << setprecision(n)
#define fi                      first
#define lbd                     lower_bound
#define mem0(x)                 memset(x, 0, sizeof (x))
#define mem1(x)                 memset(x, -1, sizeof (x))
#define mp                      make_pair
#define pb                      push_back
#define pf                      push_front
#define ppb                     pop_back
#define ppf                     pop_front
#define sc                      second
#define sqr(a)                  ((a) * (a))
#define sz(x)                   (int)((x).size())
#define ubd                     upper_bound

// #define int                     long long

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
using ordered_set = tree<T, null_type,
      less<T>,
      rb_tree_tag,
      tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0
// order_of_key(k) returns count of elements strictly smaller than k


const long double PI = 3.14159265358979323846264338;
const double eps = 1e-10;
#ifdef int
	const long long INF = 1e18;
#else
	const long long INF = 1e9;
#endif
const int32_t fftmod = 998244353;
const int32_t MOD = 1000000007;
const int32_t N = 1e5 + 10;
const int32_t NN = 1e6 + 10;

struct mod_int {
	int val;

	mod_int(long long v = 0) {
		if (v < 0) { v = v % MOD + MOD; }
		if (v >= MOD) { v %= MOD; }
		val = v;
	}

	static int mod_inv(int a, int m = MOD) {
		// https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
		int g = m, r = a, x = 0, y = 1;

		while (r != 0) {
			int q = g / r;
			g %= r; swap(g, r);
			x -= q * y; swap(x, y);
		}

		return x < 0 ? x + m : x;
	}

	explicit operator int() const {
		return val;
	}

	mod_int &operator+=(const mod_int &other) {
		val += other.val;
		if (val >= MOD) { val -= MOD; }
		return *this;
	}

	mod_int &operator-=(const mod_int &other) {
		val -= other.val;
		if (val < 0) { val += MOD; }
		return *this;
	}

	static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
		#if !defined(_WIN32) || defined(_WIN64)
		return x % m;
		#endif
		// Optimized mod for Codeforces 32-bit machines.
		// x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
		unsigned x_high = x >> 32, x_low = (unsigned) x;
		unsigned quot, rem;
		asm("divl %4\n"
		    : "=a" (quot), "=d" (rem)
		    : "d" (x_high), "a" (x_low), "r" (m));
		return rem;
	}

	mod_int &operator*=(const mod_int &other) {
		val = fast_mod((uint64_t) val * other.val);
		return *this;
	}

	mod_int &operator/=(const mod_int &other) {
		return *this *= other.inv();
	}

	friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
	friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
	friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
	friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }

	mod_int &operator++() {
		val = val == MOD - 1 ? 0 : val + 1;
		return *this;
	}

	mod_int &operator--() {
		val = val == 0 ? MOD - 1 : val - 1;
		return *this;
	}

	mod_int operator++(int) { mod_int before = *this; ++*this; return before; }
	mod_int operator--(int) { mod_int before = *this; --*this; return before; }

	mod_int operator-() const {
		return val == 0 ? 0 : MOD - val;
	}

	bool operator==(const mod_int &other) const { return val == other.val; }
	bool operator!=(const mod_int &other) const { return val != other.val; }

	mod_int inv() const {
		return mod_inv(val);
	}

	mod_int pow(long long p) const {
		assert(p >= 0);
		mod_int a = *this, result = 1;

		while (p > 0) {
			if (p & 1) {
				result *= a;
			}

			a *= a;
			p >>= 1;
		}

		return result;
	}

	friend ostream &operator<<(ostream &stream, const mod_int &m) {
		return stream << m.val;
	}
};

inline void elf_magic(int testcase)
{
	int n;
	cin >> n;
	ll a[n];
	mod_int s = 0, sq = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s += (a[i] % MOD);
		sq += (a[i] * a[i] % MOD);
	}
	cout << (s * s - sq) / 2;
	return;
}

int32_t main()
{
	#ifdef on_linux
	rlimit cpu_time {.rlim_cur = 2, .rlim_max = RLIM_INFINITY};
	setrlimit(RLIMIT_CPU, &cpu_time);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int TESTS = 1;
	//cin >> TESTS;
	for (int i = 1; i <= TESTS; ++i) {
		// cout << "Case #" << i << ": ";
		elf_magic(i);
		if (i != TESTS)	{ cout << '\n'; }
	}
	return 0;
}