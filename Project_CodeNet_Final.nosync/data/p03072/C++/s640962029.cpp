#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < i; ++j)
			cnt += v[i] >= v[j];
		if (cnt == i)
			ans++;
	}
	cout << ans << '\n';
	return 0;
}