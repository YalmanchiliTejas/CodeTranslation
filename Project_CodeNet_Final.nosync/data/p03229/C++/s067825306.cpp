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

#define int                     long long
#define ll                      long long

#define fi                      first
#define sc                      second
#define mp                      make_pair
#define pb                      push_back
#define ppb                     pop_back
#define pf                      push_front
#define ppf                     pop_front
#define sqr(a)                  ((a) * (a))
#define lbd                     lower_bound
#define ubd                     upper_bound
#define sz(x)                   (int)((x).size())
#define all(x)                  (x).begin(), (x).end()
#define mem0(x)                 memset(x, 0, sizeof (x))
#define mem1(x)                 memset(x, -1, sizeof (x))
#define pii                     pair<int32_t, int32_t>
#define pll                     pair<long long, long long>

#define DECIMAL(n)              cout << fixed << setprecision(n);
#define rep(i,a,b)              for(int32_t i = (a); i < (b); ++i)
#define between(i,x,y)          ((i) >= (x) && (i) <= (y))
// #define clamp(i,x,y)            (((i) < (x)) ? (x) : ((y) < (i)) ? (y) : (i));

template<typename T, typename U> static inline void remax(T &x, U y) {if (x < y) {x = y;}}
template<typename T, typename U> static inline void remin(T &x, U y) {if (y < x) {x = y;}}

static mt19937_64 gen(chrono::duration_cast<chrono::nanoseconds>
                      (chrono::high_resolution_clock::now().time_since_epoch()).count());

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// erase, insert same as normal set

const long double PI = 3.14159265358979323846264338;
const double eps = 1e-10;
const int32_t fftmod = 998244353;
const int32_t MOD = 1000000007;
const long long INF = 1e18;
const int32_t N = 1e5 + 10;
const int32_t NN = 1e6 + 10;



inline void elf_magic(int testcase)
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	int ans = 0;
	{
		int s = 0;
		for (int i = 0; i <= n / 2 - 2; ++i) {
			s -= 2 * a[i];
		}
		if (n & 1) {
			s -= (a[n / 2 - 1] + a[n / 2]);
		} else {
			s -= a[n / 2 - 1];
			s += a[n / 2];
		}
		for (int i = n / 2 + 1; i < n; ++i) {
			s += 2 * a[i];
		}
		remax(ans, s);
	}
	{
		int s = 0;
		for (int i = 0; i < n / 2; ++i) {
			s -= 2 * a[i];
		}
		if (n & 1) {
			s += (a[n / 2] + a[n / 2 + 1]);
		} else {
			s -= a[n / 2];
			s += a[n / 2 + 1];
		}
		for (int i = n / 2 + 2; i < n; ++i) {
			s += 2 * a[i];
		}
		remax(ans, s);
	}
	cout << ans;

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