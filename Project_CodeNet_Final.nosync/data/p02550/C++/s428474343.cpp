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

#define int                     long long

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

inline void elf_magic(int testcase)
{
	int n, x, m;
	cin >> n >> x >> m;

	bool vis[m + 10] = {};

	int ctr = 0;
	vector<int> v;

	int brat = -1;
	while (ctr < n) {
		if (vis[x]) { brat = x; break; }
		vis[x] = 1;
		v.pb(x);
		ctr++;
		x = (x * x) % m;
	}

	int ans = 0;
	int bb = 0;
	int i;
	for (i = 0; i < ctr; ++i) {
		if (v[i] == brat) { bb = i; break; }
		ans += v[i];
	}

	trace(ans);

	int temp = 0;
	for (i; i < ctr; ++i) {
		temp += v[i];
	}

	trace(temp, (n - bb) / (ctr - bb));

	ans += temp * ((n - bb) / (ctr - bb));

	for (int i = 0; i < ((n - bb) % (ctr - bb)); ++i) {
		ans += v[i + bb];
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