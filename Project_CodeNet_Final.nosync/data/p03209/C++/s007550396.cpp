#include <bits/stdc++.h>

using namespace std;

long a[55], b[55];
long f(int n, long x) {
	if (!x) return 0;
	if (!n) return 1;
	if (x < a[n - 1] + 2)
		return f(n - 1, x - 1);
	return b[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
}
int main() {
	int n;
	long x;
	cin >> n >> x;
	a[0] = b[0] = 1;
	for (int i = 0; i < n; i++) {
		a[i + 1] = a[i] * 2 + 3;
		b[i + 1] = b[i] * 2 + 1;
	}
	cout << f(n, x) << endl;
	return 0;
}
