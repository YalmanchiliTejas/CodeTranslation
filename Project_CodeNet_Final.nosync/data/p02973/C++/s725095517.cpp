#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n), l(n);
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		a[i] = -tmp;
	}
	l[0] = a[0];
	int length = 1;
	for (int i = 1; i < n; ++i) {
		if (l[length - 1] <= a[i]) l[length++] = a[i];
		else *upper_bound(l.begin(), l.begin() + length, a[i]) = a[i];
	}
	cout << length << endl;

	return 0;
}