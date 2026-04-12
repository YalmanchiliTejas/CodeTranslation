#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n; cin >> n;
	vector <int > v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int max = -1, ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] >= max) {
			ans++;
			max = v[i];
		}
	}
	cout << ans;
	return 0;
}


