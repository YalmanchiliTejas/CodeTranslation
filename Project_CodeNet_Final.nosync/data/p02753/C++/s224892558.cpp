#if defined(__GNUC__)
#include <bits/stdc++.h>
#define __int32 __int32_t
// __GNUC__
#else
#include "bits/stdc++.h"
#endif
using namespace std;

#define int long long

#define itn __int32
#define REP(i, n) for(itn (i) = 0; (i) < (n); ++(i))
#define REP2(i, x, n) for(itn (i) = x; (i) < (n); ++(i))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SORT(x) sort(ALL(x))
#define RSORT(x) sort(ALL(x), greater<decltype(x)::value_type>())
#define RSORT2(x, T) sort(ALL(x), greater<T>())
#define REVERSE(x) reverce(ALL(x))
#define ACM(x, y) accumulate(ALL(x), y)

#define INT_POW(x, y) [](int a, int b) -> int {int c = a; REP(i, b - 1){c *= a;} return c;}(x, y)
#define INT_POWM(x, y, m) [](int a, int b, int m) -> int {int c = a; REP(i, b - 1){c *= a; c %= m;} return c;}(x, y, m)
#define FCT(x) [](int a) -> int {int r = 1; REP(i, a){r *= i;} return r;}(x)

// デバッグ用
#define PUT_LIST(x, y) std::copy(ALL(x), ostream_iterator<decltype(x)::value_type>(cout, y))

const int kMod = 1e9 + 7;

itn main() {
	ios::sync_with_stdio(false);

	string s;

	cin >> s;

	if (s[0] == s[1] && s[1] == s[2]) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}

	return 0;
}
