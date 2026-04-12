#include <vector>
#include <iostream>
using namespace std;
int n, a;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	vector<int> x(2 * n); int l = n, r = n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (i % 2 == 0) x[r++] = a;
		else x[--l] = a;
	}
	if (n % 2 == 0) for (int i = l; i < r; i++) cout << x[i] << ' ';
	else for (int i = r - 1; i >= l; i--) cout << x[i] << ' ';
	return 0;
}