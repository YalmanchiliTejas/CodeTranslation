#include <bits/stdc++.h>
using namespace std;

const int maxn = 2 * 1e5 + 10;
int a[maxn];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> nums;
	for (int i = n; i >= 1; i -= 2) {
		nums.push_back(a[i]);
	}
	for (int i = n % 2 == 0 ? 1 : 2; i <= n; i += 2) {
		nums.push_back(a[i]);
	}
	for (int i = 0; i < nums.size(); i++) {
		if (i > 0) cout << " ";
		cout << nums[i];
	}
	cout << endl;
	return 0;
}