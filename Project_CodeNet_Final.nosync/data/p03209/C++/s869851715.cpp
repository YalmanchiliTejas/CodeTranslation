///created: 29/May/2019 08:59:18

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll x, p[51], f[51];

ll calc(int n, ll x) {
	if (n == 0) return x >= 1;
	if (x <= 1 + p[n - 1]) return calc(n - 1, x - 1);
	return f[n - 1] + calc(n - 1, x - 2 - p[n - 1]) + 1;
}

int main() {
	cin >> n >> x;
	p[0] = 1;
	for (int i = 1; i <= 50; ++i)
		p[i] = 3LL + 2LL * p[i - 1];
	f[0] = 1;
	for (int i = 1; i <= 50; ++i)
		f[i] = 1LL + 2LL * f[i - 1];
	printf("%lld", calc(n, x));
	return 0;
}
