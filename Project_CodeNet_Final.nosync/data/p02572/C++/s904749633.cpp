#include <bits/stdc++.h>

using namespace std;

long long a[200005], sum, n, N = 1e9 + 7;

int main() {
	cin >> n;
	sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum = (sum + a[i]) % N;
	}
	sum = (sum * sum) % N;
	for (int i = 0; i < n; i++) {
		sum = (sum - a[i] * a[i]) % N;
	}
	sum = (sum + N) % N;
	sum = (sum * 500000004) % N;
	cout << sum;
	return 0;
}