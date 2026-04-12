#include<iostream>
#include<algorithm>
using namespace std;
int n, m, a[300010];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	m = 0;
	for (int i = 0; i <= m; i++) {
		m = max(a[i] / 10 + i, m);
		if (m >= n)goto heaven1;
	}
	cout << "no\n";
	return 0;
heaven1:m = n - 1;
	for (int i = n - 1; i >= m; i--) {
		m = min(i - a[i] / 10, m);
		if (m <= 0)goto heaven2;
	}
	cout << "no\n";
	return 0;
heaven2:cout << "yes\n";
	return 0;
}
