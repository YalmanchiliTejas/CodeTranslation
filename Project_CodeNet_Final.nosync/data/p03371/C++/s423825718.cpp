#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
typedef long long int lint;
typedef unsigned long long int ulint;

//#define DEBUG

#ifdef DEBUG
#	define dump(i) cout << "[*] " #i " : " << i << endl;
#	define debug(i) i
#else
#	define dump(i)
#	define debug(i)
#endif
#define rep(i, MAX) for (int i = 0; i < (MAX); ++i)

inline void solve() {
	int a, b, c;
	int x, y;
	cin >> a >> b >> c >> x >> y;
	c *= 2;
	int num_min = min(x, y);
	x -= num_min;
	y -= num_min;
	int ans;
	if (a + b > c) {
		ans = c * num_min;
	} else {
		ans = (a + b) * num_min;
	}
	ans += (a < c ? a : c) * x;
	ans += (b < c ? b : c) * y;
	cout << ans << endl;
}

int main() {
	//*
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	// */
#ifdef DEBUG
	const auto start = chrono::high_resolution_clock::now();
#endif
	solve();
#ifdef DEBUG
	const auto stop = chrono::high_resolution_clock::now();
	cerr << "[*] time: " << chrono::duration_cast<chrono::milliseconds>(stop-start).count()
		<< " [ms]" << endl;
#endif
	return 0;
}
