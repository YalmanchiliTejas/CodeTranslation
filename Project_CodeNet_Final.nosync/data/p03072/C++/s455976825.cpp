#include <iostream>
#include<vector>
using namespace std;
int main() {
	int n, highest = 0, ans = 0;
	cin >> n;
	vector<int> h(n);
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		if (highest <= h[i]) {
			ans++;
			highest = h[i];
		}
	}
	cout << ans << endl;
	return 0;
}