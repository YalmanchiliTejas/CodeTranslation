#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)cin >> a[i];
	for (auto& x : a)x = -x;
	multiset<int> dp;
	for (int i = 0; i < n; ++i) {
		auto it = dp.upper_bound(a[i]);
		if (it == dp.end())dp.insert(a[i]);
		else {
			dp.erase(it);
			dp.insert(a[i]);
		}
	}
	cout << dp.size() << endl;
}