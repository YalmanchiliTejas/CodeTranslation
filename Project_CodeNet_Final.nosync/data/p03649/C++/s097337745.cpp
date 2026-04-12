#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

#define TEST 0

ll mrand() {
	ll x = rand();
	return x * RAND_MAX + rand();
}

vll a;
int n;

bool read() {
#if TEST
	n = 2 + rand() % 50;
	a.resize(n);
	forn(i, n) {
		a[i] = mrand() % ll(1e16);
	}
	return 1;
#else
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		scanf("%lld", &a[i]);
	}
	return 1;
#endif
}

ll brut(vll a) {
	ll ans = 0;
	while (1) {
		sort(all(a));

		if  (a.back() < sz(a)) {
			break;
		}
		++ans;

		forn(i, sz(a) - 1) {
			a[i] += 1;
		}
		a.back() -= sz(a);
	}
	return ans;
}

const ll INF = 1e17;

void simulate(vll& a, int steps, int n) {
	forn(it, steps) {
		int mx = max_element(all(a)) - a.begin();
		forn(i, sz(a)) {
			if  (i == mx) {
				a[i] -= n;
			} else {
				a[i] += 1;
			}
		}
	}
}

ll repair(vll& left, vll& right, int n) {
	sort(all(left));
	sort(all(right));

	assert(right.back() - right.front() < n);

	// eprintf("repair:\n");
	// eprintf("left:\n");
	// forn(i, sz(left)) {
	// 	eprintf("%lld ", left[i]);
	// }
	// eprintf("\n");
	// eprintf("right:\n");
	// forn(i, sz(right)) {
	// 	eprintf("%lld ", right[i]);
	// }
	// eprintf("\n\n");

	const int cnt = sz(right);
	const ll mn = *min_element(all(right));
	ll x = INF;
	// prev + x * cnt < min + x * (-n + cnt - 1)
	// x * (cnt + n - cnt + 1) < min - prev
	if  (left.back() > -INF) {
		x = min(x, (mn - left.back()) / (n + 1));
	}
	
	// min + x * (-n + cnt - 1) > n
	// x * (-n + cnt - 1) > n - min
	// x < (n - min) / (-n + cnt - 1)
	x = min(x, (mn - n) / (n - cnt + 1));

	x = max(x - 3, 0ll);

	forn(i, sz(left)) {
		if  (left[i] > -INF) {
			left[i] += x * cnt;
		}
	}
	forn(i, sz(right)) {
		right[i] += x * (-n + cnt - 1);
	}
	assert(left.back() <= right.back());

	ll ans = x * cnt;

	// eprintf("AFTER BIG:\n");
	// eprintf("left:\n");
	// forn(i, sz(left)) {
	// 	eprintf("%lld ", left[i]);
	// }
	// eprintf("\n");
	// eprintf("right:\n");
	// forn(i, sz(right)) {
	// 	eprintf("%lld ", right[i]);
	// }
	// eprintf("\n\n");

	while (1) {
		// eprintf("STEP:\n");
		// eprintf("left:\n");
		// forn(i, sz(left)) {
		// 	eprintf("%lld ", left[i]);
		// }
		// eprintf("\n");
		// eprintf("right:\n");
		// forn(i, sz(right)) {
		// 	eprintf("%lld ", right[i]);
		// }
		// eprintf("\n\n");

		if  (max(right.back(), left.back()) - min(right.front(), left.back()) < n) {
			break;
		}
		if  (right.back() < n) {
			break;
		}

		assert(left.back() <= right.back());

		simulate(right, 1, n);
		sort(all(right));

		forn(i, sz(left)) {
			if  (left[i] > -INF) {
				left[i] += 1;
			}
		}

		ans += 1;
	}

	return ans;
}

ll solve() {
	sort(all(a));

	ll ans = 0;
	for (int suff = 1; suff <= n; ++suff) {
		vll left;
		vll right;
		forn(i, n) {
			if  (i < n - suff) {
				left.pb(a[i]);
			} else {
				right.pb(a[i]);
			}
		}
		if  (left.empty()) {
			assert(suff == n);
			left.pb(-INF);
		}

		ans += repair(left, right, n);

		forn(i, n) {
			if  (i < n - suff) {
				a[i] = left[i];
			} else {
				a[i] = right[i - (n - suff)];
			}
		}
	}

	sort(all(a));
	assert(a.back() < n);
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

#if TEST
	// while (1) {
	// 	read();

	// 	sort(all(a));

	// 	int cnt = 1 + rand() % (n - 1);
	// 	vll right;
	// 	forn(i, n) {
	// 		if  (i >= n - cnt) {
	// 			right.pb(a[i]);
	// 		}
	// 	}
	// 	simulate(right, cnt, n);

	// 	forn(i, sz(right)) {
	// 		assert(right[i] == a[(n - cnt) + i] - n + cnt - 1);
	// 	}

	// 	printf("OK n=%d, cnt=%d\n", n, cnt);
	// }

	while (1) {
		read();

		auto was = a;

		// printf("%d\n", n);
		// forn(i, n) {
		// 	printf("%lld ", was[i]);
		// }
		// printf("\n");

		ll br = brut(a);

		ll my = solve();

		// ll br = my;

		if  (my == br) {
			printf("OK %lld == %lld\n", br, my);
			continue;
		}

		printf("br=%lld, my=%lld\n", br, my);
		forn(i, n) {
			printf("%lld ", was[i]);
		}
		printf("\n");
		exit(0);
	}
#endif

	while (read()) {
		printf("%lld\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
