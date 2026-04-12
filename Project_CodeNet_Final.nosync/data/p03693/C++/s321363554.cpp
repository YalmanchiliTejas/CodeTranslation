#include <bits/stdc++.h>

#define rep(i, first, to) for(ll i = first; i < to; ++i)

using namespace std;
typedef long long ll;

void solve() {
	int n, r, g, b;
	cin >> r >> g >> b;
	n = 100 * r + 10 * g + b;
	cout << ( n % 4 == 0 ? "YES" : "NO") << endl;
}

int main() {
	solve();
	return 0;
}