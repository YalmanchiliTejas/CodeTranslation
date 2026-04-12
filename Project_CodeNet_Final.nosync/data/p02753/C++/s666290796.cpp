#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define fi first
#define se second
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define out(t, a) copy(all(a), ostream_iterator<t>(cout, " ")); cout << "\n";
// #define DEBUG
#define int long long

using namespace std;

void set_program() {
	#ifdef DEBUG
		freopen ("test.in", "r", stdin);
		freopen ("test.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pt;

const int INF = 1e9 + 1;
const int MAXN = 3000;
const int LOGN = 20;
const int MOD = 1e7;
const int ALF = 26;

void solve() {
	string s;
	cin >> s;
	if (s == "AAA" || s == "BBB") {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
}

main() {
	set_program();
	int t;
	#ifdef DEBUG
		// cin >> t;
		t = 1;
	#else
		// cin >> t;
		t = 1;
	#endif
	for (; t--; ) {
		solve();
		cout << "\n";
	}
 	return 0;
}