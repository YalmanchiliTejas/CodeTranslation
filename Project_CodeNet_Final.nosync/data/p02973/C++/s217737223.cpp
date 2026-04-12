#include <bits/stdc++.h>
using namespace std;

signed main () {
	int n, x;
	cin >> n;
	multiset < int > heads;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		auto it = heads.lower_bound(x);
		if (it == heads.begin() || heads.empty()) 
			heads.insert(x);
		else {
			heads.erase(prev(it));
			heads.insert(x);
		}
	}
	cout << heads.size() << '\n';
}
