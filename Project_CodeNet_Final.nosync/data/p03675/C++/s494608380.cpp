#include <iostream>
#include <vector>
using namespace std;

int n;
int a[200000];
int b[200000];

signed main() {
	int i;
	cin >> n;
	for (i = 0; i < n; i++) cin >> a[i];
	
	if (n % 2 == 0) {
		for (i = 0; i < n / 2; i++) b[i] = n - 2 * i;
		for (i = 0; i < n / 2; i++) b[n / 2 + i] = 1 + 2 * i;
	}
	else {
		for (i = 0; i < n / 2 + 1; i++) b[i] = n - 2 * i;
		for (i = 0; i < n / 2; i++) b[n / 2 + 1 + i] = 2 + 2 * i;
	}
	
	vector<int> ans;
	for (i = 0; i < n; i++) {
		ans.push_back(a[b[i] - 1]);
	}
	
	cout << ans[0];
	for (i = 1; i < n; i++) {
		cout << " " << ans[i];
	}
	cout << endl;
	return 0;
}