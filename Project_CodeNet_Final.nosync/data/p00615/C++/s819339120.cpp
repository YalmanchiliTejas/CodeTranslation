#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	while(true) {
		int n, m;
		cin >> n >> m;
		if(!n && !m) break;

		vector<int> v(n+m);
		for(int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		for(int i = n; i < m+n; ++i) {
			cin >> v[i];
		}
		v.push_back(0);
		sort(v.begin(), v.end());
		int ans = 0;
		for(int i = 0; i < m+n; ++i) {
			ans = max(ans, v[i+1]-v[i]);
		}
		cout << ans << endl;
	}
	return 0;
}