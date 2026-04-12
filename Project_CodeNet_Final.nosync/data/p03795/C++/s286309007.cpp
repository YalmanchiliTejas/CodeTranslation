#include <bits/stdc++.h>

#define rep(i, first, to) for(ll i = first; i < to; ++i)

using namespace std;
typedef long long ll;

void solve() {
	int x;
	cin >> x;
	cout << (800 * x - (x / 15) * 200) << endl;
}

int main() {
	solve();
	return 0;
}