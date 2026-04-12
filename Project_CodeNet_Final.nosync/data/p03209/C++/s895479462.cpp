#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

long long f[55];
long long p[55];

long long foo(int n, long long x) {
	if (n == 0) {
		return 1;
	}
	if (x == 1) {
		return 0;
	}
	if (x <= 1 + f[n - 1]) {
		return foo(n - 1, x - 1);
	}
	if (x == 1 + f[n - 1] + 1) {
		return 1 + p[n - 1];
	}
	if (x <= 1 + f[n - 1] + 1 + f[n - 1]) {
		return 1 + p[n - 1] + foo(n - 1, x - 2 - f[n - 1]);
	}
	return p[n];
}

int main () {
	f[0] = 1;
	p[0] = 1;
	for (int i = 1; i <= 50; ++i) {
		f[i] = 2 * f[i - 1] + 3;
		p[i] = 2 * p[i - 1] + 1;
	}
	int n;
	long long x;
	while (scanf("%d%lld", &n, &x) != EOF) {
		cout << foo(n, x) << endl;
	}
	return 0;
}