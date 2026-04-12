#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int n, m;
	while(cin >> n >> m, n || m) {
		vector<int> t;
		for(int i = 0; i < n; ++i) {
			int tmp;
			cin >> tmp;
			t.push_back(tmp);
		}
		for(int i = 0; i < m; ++i) {
			int tmp;
			cin >> tmp;
			t.push_back(tmp);
		}
		sort(t.begin(), t.end());
		int ans = t[0];
		for(unsigned int i = 0; i < t.size() - 1; ++i) {
			ans = max(ans, t[i+1] - t[i]);
		}
		cout << ans << endl;
	}
}