#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>h(n); for (auto&& x : h)cin >> x;
	int ans = 0;
	int maxNum = h[0];
	for (auto&& x : h) {
		if (maxNum <= x) {
			maxNum = x;
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}