// Copyright by libra9z
#ifndef ONLINE_JUDGE
#define __DEBUG
#endif

#pragma comment(linker, "/STACK:1024000000,1024000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#define _CRT_SECURE_NO_WARNINGS
#include <immintrin.h>
#include <emmintrin.h>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>
#include <tuple>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename T, typename Comp = less <T>, typename Heap_tag = __gnu_pbds :: pairing_heap_tag>
using Priority_queue = __gnu_pbds :: priority_queue <T, Comp, Heap_tag>;
template <typename Key, typename Value>
using hashmap = __gnu_pbds :: gp_hash_table <Key, Value>;
template <typename T, typename Comp = less <T> >
using ordered_set = __gnu_pbds :: tree <T, __gnu_pbds :: null_type,
			Comp, __gnu_pbds :: rb_tree_tag, __gnu_pbds :: tree_order_statistics_node_update>;
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono :: steady_clock :: now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
template <typename T>
using hash_set = unordered_set <T, custom_hash>;
template <typename T, typename K>
using hash_map = unordered_map <T, K, custom_hash>;

#define rep(i, n) for (int i = 0; i < (n); ++ i)
#define rep1(i, n) for (int i = 1; i <= (n); ++ i)
#define Rep(i, a, b) for (int i = (a); i <= (b); ++ i)
#define repit(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it ++)
#define FILEOPEN(f)                              \
        freopen(f".in", "r", stdin);             \
        freopen(f".out", "w", stdout)
#define All(a) a.begin(), a.end()
#define SZ(a) ((int)a.size())
#define sqr(s) ((s) * (s))
#define fillset(a, val) memset(a, val, sizeof(a))
#define fi first
#define se second
#define y0 y19260817
#define y1 y19268107
#define j0 j19260817
#define j1 j19268107
#define x0 x19260817
#define x1 x19268107
#ifndef __DEBUG
#define Debug(...)
#else
template <typename T> inline void _debug(const char *names, T &&t) {
	(cerr << names << " = " << t << endl).flush();
}
template <typename T1, typename ...T>
inline void _debug(const char *names, T1 &&t1, T &&... t) {
	const char *comma = strchr(names, ',');
	(cerr.write(names, comma - names) << " = " << t1 << ", ").flush();
	_debug(comma + 1, t ...);
}
#define Debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
#endif
template <typename T>
inline T chmax(T &x, T y) { return x = max(x, y); }
template <typename T>
inline T chmin(T &x, T y) { return x = min(x, y); }
template <typename T>
inline void reinit(T &t) { t.~T(); new (&t) T(); }
template <typename T>
inline void readval(T &t) { cin >> t; }
template <typename T>
inline T readin() { T t; cin >> t; return t; }

typedef long long ll;
typedef unsigned long long ull;
typedef long long llong;
typedef unsigned long long ullong;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef ullong hash_type;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9, PI = acos(-1.0);
const int mod1 = 1000'000'007, mod2 = 998'244'353;
mt19937 __random_gen(time(NULL));

template <unsigned MOD>
class modular_int {
	public:
		typedef unsigned value_type;
	protected:
		unsigned x;
	public:
		modular_int inv() const {
			unsigned a = MOD, b = x;
			int u = 0, v = 1;
			while (b) {
				int t = a / b;
				a -= t * b, swap(a, b);
				u -= t * v, swap(u, v);
			} if (u < 0) u += MOD;
			return modular_int(u);
		}
		inline modular_int pow(long long y) const {
			modular_int b = *this, r = 1;
			if (y < 0) b = b.inv(), y = -y;
			for (; y; y >>= 1, b *= b) if (y & 1) r *= b;
			return r;
		}
	public:
		modular_int() { x = 0; }
		modular_int(const modular_int &y) { x = y.x; }
		modular_int(modular_int &&y) { x = y.x; }
		inline void clear() { *this = modular_int(); }
		inline int to_int() const { return (int)x; }
		inline unsigned value() const { return x; }
		inline void invalid_copyright() {
			std :: cerr << "\"modular_int\" copyrights by libra9z, ";
			std :: cerr << "don't use it unless getting the agreement of libra9z! ";
			std :: cerr << "(You can ask libra9z on \"https://codeforces.com/profile/libra9z\")\n";
			__builtin_abort();
		}
	public:
		modular_int(int y) { if (y < 0 || (int)MOD <= y) y %= (int)MOD; if (y < 0) y += MOD; x = y; }
		modular_int(unsigned y) { if (MOD <= y) x = y % MOD; else x = y; }
		modular_int(long long y) { if (y < 0 || MOD <= y) y %= MOD; if (y < 0) y += MOD; x = y; }
		modular_int(unsigned long long y) { if (MOD <= y) x = y % MOD; else x = y; }
		modular_int &operator = (const modular_int &y) { x = y.x; }
		modular_int &operator = (const int &y) { x = y; }
		modular_int &operator = (const long long &y) { x = y; }
		modular_int &operator = (const unsigned int &y) { x = y; }
		modular_int &operator = (const unsigned long long &y) { x = y; }
		modular_int &operator += (const modular_int &y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
		modular_int &operator -= (const modular_int &y) { if ((x -= y.x) & (1u << 31)) x += MOD; return *this; }
		modular_int &operator *= (const modular_int &y) { x = (unsigned long long)x * y.x % MOD; return *this; }
		modular_int &operator /= (const modular_int &y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
		modular_int &operator += (const int &y) { return *this += modular_int(y); }
		modular_int &operator -= (const int &y) { return *this -= modular_int(y); }
		modular_int &operator *= (const int &y) { return *this *= modular_int(y); }
		modular_int &operator /= (const int &y) { return *this /= modular_int(y); }
		modular_int &operator += (const long long &y) { return *this += modular_int(y); }
		modular_int &operator -= (const long long &y) { return *this -= modular_int(y); }
		modular_int &operator *= (const long long &y) { return *this *= modular_int(y); }
		modular_int &operator /= (const long long &y) { return *this /= modular_int(y); }
		modular_int &operator += (const unsigned int &y) { return *this += modular_int(y); }
		modular_int &operator -= (const unsigned int &y) { return *this -= modular_int(y); }
		modular_int &operator *= (const unsigned int &y) { return *this *= modular_int(y); }
		modular_int &operator /= (const unsigned int &y) { return *this /= modular_int(y); }
		modular_int &operator += (const unsigned long long &y) { return *this += modular_int(y); }
		modular_int &operator -= (const unsigned long long &y) { return *this -= modular_int(y); }
		modular_int &operator *= (const unsigned long long &y) { return *this *= modular_int(y); }
		modular_int &operator /= (const unsigned long long &y) { return *this /= modular_int(y); }
		friend modular_int operator + (modular_int x, const modular_int &y) { return x += y; }
		friend modular_int operator - (modular_int x, const modular_int &y) { return x -= y; }
		friend modular_int operator * (modular_int x, const modular_int &y) { return x *= y; }
		friend modular_int operator / (modular_int x, const modular_int &y) { return x *= y.inv(); }
		friend modular_int operator + (modular_int x, const int &y) { return x += y; }
		friend modular_int operator - (modular_int x, const int &y) { return x -= y; }
		friend modular_int operator * (modular_int x, const int &y) { return x *= y; }
		friend modular_int operator / (modular_int x, const int &y) { return x /= y; }
		friend modular_int operator + (modular_int x, const long long &y) { return x += y; }
		friend modular_int operator - (modular_int x, const long long &y) { return x -= y; }
		friend modular_int operator * (modular_int x, const long long &y) { return x *= y; }
		friend modular_int operator / (modular_int x, const long long &y) { return x /= y; }
		friend modular_int operator + (modular_int x, const unsigned &y) { return x += y; }
		friend modular_int operator - (modular_int x, const unsigned &y) { return x -= y; }
		friend modular_int operator * (modular_int x, const unsigned &y) { return x *= y; }
		friend modular_int operator / (modular_int x, const unsigned &y) { return x /= y; }
		friend modular_int operator + (modular_int x, const unsigned long long &y) { return x += y; }
		friend modular_int operator - (modular_int x, const unsigned long long &y) { return x -= y; }
		friend modular_int operator * (modular_int x, const unsigned long long &y) { return x *= y; }
		friend modular_int operator / (modular_int x, const unsigned long long &y) { return x /= y; }
		modular_int operator - () const { return (x ? MOD - x : 0); }
		modular_int operator ++ () const { return *this += 1; }
		modular_int operator -- () const { return *this -= 1; }
		modular_int operator ++ (int) const { modular_int ret = *this; *this += 1; return ret; }
		modular_int operator -- (int) const { modular_int ret = *this; *this -= 1; return ret; }
		friend bool operator < (const modular_int &x, const modular_int &y) { return x.x < y.x; }
		friend bool operator == (const modular_int &x, const modular_int &y) { return x.x == y.x; }
		friend bool operator != (const modular_int &x, const modular_int &y) { return x.x != y.x; }
		friend ostream &operator << (ostream &os, modular_int x) { return os << x.x; }
		friend istream &operator >> (istream &is, modular_int &x) { is >> x.x; x.x %= MOD; return is; }
};
typedef modular_int <mod1> mod_int;

pair <mod_int, mod_int> solve(const vector <int> &v) {
	int mn = *min_element(All(v));
	mod_int pv = 1, ph = 1;
	vector <int> p;
	for (int now: v)
		if (now == mn) {
			pv *= 2;
			if (p.empty()) continue;
			auto npr = solve(p);
			p.clear();
			ph *= npr.se, pv *= (npr.fi + npr.se);
		}
		else
			p.push_back(now - mn);
	if (!p.empty()) {
		auto npr = solve(p);
		ph *= npr.se, pv *= (npr.fi + npr.se);
	}
	mod_int k = 2 * ph;
	ph *= mod_int(2).pow(mn);
	return {pv + ph - k, ph};
}

int main(int argc, const char *argv[]) {
	ios_base :: sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout << fixed << setprecision(12);
	vector <int> a(*istream_iterator<int>(cin));
	for_each(All(a), readval <int>);
	cout << solve(a).fi << endl;
	return 0;
}