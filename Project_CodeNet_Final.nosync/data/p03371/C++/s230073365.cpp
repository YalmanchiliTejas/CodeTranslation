template<class T> inline void chmin(T & a, T b) { if (a > b) a = b; }

#define rep(i, n) for(int i=0; i<n; i++)
#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
	const long long MAX = 100001;

	long long res = (1 << 30);
	for (int i = 0; i < MAX; i++) {
		chmin(res, ((i * 2 * C) + (max(0LL, X - i) * A) + (max(0LL, Y - i) * B)));
	}

	cout << res << endl;

}

int main(void) {
	solve();
	return 0;
}