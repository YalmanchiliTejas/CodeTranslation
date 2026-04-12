// (c) 2020, redotter

// Roses are red
// The Tardis is blue
// The Doctor once said
// Rose Tyler...

#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#pragma comment(linker, "/stack:500000000")
#endif

#define pb push_back
#define the(a) (a).begin(), (a).end()
#define ft first
#define sd second
#define endl "\n"
#define forn(i, n) for (int i = 0; i < (n); i++)
#define forr(i, s, n) for (int i = (s); i < (n); i++)

using i64 = long long;
using i32 = int;
using f64 = long double;

template <class T> using vec = vector<T>;
using str = string; using p64 = pair<i64, i64>;
using v64 = vec<i64>; using vv64 = vec<v64>;
using s64 = set<i64>; using m64 = map<i64, i64>;
template <size_t Size1> using a64 = array<i64, Size1>;
template <size_t Size1, size_t Size2> using aa64 = array<a64<Size2>, Size1>;
template <class T> using hash_set = unordered_set<T>;
template <class T, class U> using hash_map = unordered_map<T, U>;

mt19937 gen(998244353);
const i64 inf = numeric_limits<i64>::max() / 2;

template <class T> inline i64 len(const T& a) { return (i64)(a.size()); }
inline void fast() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
template <class T, class S>
inline bool check_min(T& a, S b) { if (a > b) return a = b, 1; return 0; }
template <class T, class S>
inline bool check_max(T& a, S b) { if (a < b) return a = b, 1; return 0; }

void read() {}
template<class T, class ...U>
void read(T& a, U& ...b) { cin >> a; read(b...); }
void print() {}
template<class T, class ...U>
void print(const T& a, const U& ...b) { cout << a << " "; print(b...); }
void println() { cout << "\n"; }
template<class T, class ...U>
void println(const T& a, const U& ...b) { cout << a << " "; println(b...); }

struct Problem {
	void files(str in, str out) {
#ifdef ONLINE_JUDGE
		freopen(in.c_str(), "r", stdin), freopen(out.c_str(), "w", stdout);
#endif
	}
	void solve(), input();
	void many() { i32 t; cin >> t; while (t--) input(), solve(); }
	void make(bool mt = 0) { if (mt) many(); else input(), solve(); }
} problem;

signed main() {
	fast();
	problem.make();
#ifdef _DEBUG
	println(); println("[finished]"); system("pause > nul");
#endif
	return 0;
}

i64 n;
v64 a;

void Problem::solve() {
	vv64 dp(n, v64(n, -inf));
	forn(i, n) {
		dp[i][i] = a[i];
	}
	forr(ln, 2, n + 1) {
		forn(i, n) {
			i64 j = i + ln - 1;
			if (j >= n) break;
			check_max(dp[i][j], a[i] - dp[i + 1][j]);
			check_max(dp[i][j], a[j] - dp[i][j - 1]);
		}
	}
	println(dp[0][n - 1]);
}

void Problem::input() {
	read(n);
	a.resize(n);
	forn(i, n) read(a[i]);
}
