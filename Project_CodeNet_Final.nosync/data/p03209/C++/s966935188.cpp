#include <bits/stdc++.h>
using namespace std;

long long a(int n) {
	long long a = 4;
	return (a << n) - 3;
}

long long p(int n) {
	long long p = 2;
	return (p << n) - 1;
}

long long f(int n, long long k) {
	if (k == 1)
		return n == 0;
	if (k <= a(n - 1) + 1)
		return f(n - 1, k - 1);
	if (k == a(n - 1) + 2)
		return p(n - 1) + 1;
	if (k <= a(n) - 1)
		return p(n - 1) + 1 + f(n - 1, k - a(n - 1) - 2);
	else
		return p(n);
}

int main() {
	int n;
	long long k;
	cin >> n >> k;
	cout << f(n, k) << endl;
}
