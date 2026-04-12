#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")
#include <bits/stdc++.h>
#define pb(X) push_back(X)
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;

int n, a, b, c, d, q, ans;

int main() {
	INIT
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ans = 1;
	b = a[0];
	for (int i = 1; i < n; ++i) {
		if (a[i] >= b) {
			b = a[i];
			++ans;
		}
	}
	cout << ans;
	return 0;
}