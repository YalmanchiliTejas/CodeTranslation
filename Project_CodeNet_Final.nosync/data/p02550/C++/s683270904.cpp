#include<iostream>
#include <map>
#include<algorithm>
#include <string>
#include<vector>
#include <set>

using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x, m;
	cin >> n >> x >> m;
	vector<int>r;
	map<int, int>ar;
	int cur = 0;
	for (int i = 0; i < min(n, 200000ll); i++) {
		r.push_back(x);
		if (ar.find(x) != ar.end()) {
			int j = ar[x];
			int d = i - ar[x];
			int vv = 0;
			for (int q = j; q < i; q++) {
				vv += r[q];
			}
			cur += vv * ((n - i) / d);
			for (int q = j; q < j + (n - i) % d; q++) {
				cur += r[q];
			}
			cout << cur;
			return 0;
		}
		cur += x;
		ar[x] = i;
		x = (x * x) % m;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += r[i];
	}
	cout << ans;
	return 0;
}