#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

int n, a[N], b[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++)
		if(a[i] >= b[(n >> 1)])
			cout << b[(n >> 1) - 1] << '\n';
		else
			cout << b[n >> 1] << '\n';
	return 0;
}