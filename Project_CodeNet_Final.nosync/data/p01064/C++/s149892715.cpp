#include <bits/stdc++.h>

using namespace std;

#define FOR(i,n) for(int i = 0 ;i < (n); i++) 

int main() {
	int n, a, b; scanf("%d%d%d", &n, &a, &b);
	int m; scanf("%d", &m);
	vector<tuple<int, int, int>> v;
	FOR(i, m) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		v.emplace_back(x, y - 1, z - 1);
	}
	int k; scanf("%d", &k); k--;
	reverse(v.begin(), v.end());
	for (auto& xyz : v) {
		int x, y, z; tie(x, y, z) = xyz;
		if (x == 0) {
			if (y <= k && k <= z) k = y + z - k;
		}
	}
	reverse(v.begin(), v.end());
	int val = a + b * k;
	for (auto& xyz : v) {
		int x, y, z; tie(x, y, z) = xyz;
		if (x == 0) {
			if (y <= k && k <= z) k = y + z - k;
		} else if (x == 1) {
			if (y <= k && k <= z) val++;
		} else {
			if (y <= k && k <= z) val /= 2;
		}
	}
	cout << val << endl;
}