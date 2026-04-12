// author: Saman Mahdanian
#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10;
const int MOD = 1e9 + 7;

void _psum (int &, int);
int _sum (int, int);
int _mul (int, int);
int _pow (int, int);
int gcd (int, int);

int n, m, k, inv[N], f[N], res[N];
vector <int> X;

int x[] = {0, 0, -1, +1};
int y[] = {-1, +1, 0, 0};
int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector <int> ind(n);
	iota (ind.begin(), ind.end(), 0);
	sort (ind.begin(), ind.end(), [&] (int i, int j) {
		return a[i] < a[j];
	});

	int m = n / 2;
	for (int i = 0; i < n; i++)
		if (i < m)
			b[ind[i]] = a[ind[m]];
		else
			b[ind[i]] = a[ind[m - 1]];

	for (int i = 0; i < n; i++)
		cout << b[i] << '\n';
}

int gcd (int a, int b) {
	return !b? a : gcd (b, a % b);
}

// int choose (int r, int k) {
// 	return _mul (f[k], _mul(inv[r], inv[k - r]));
// }

void _psum (int &a, int b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
}

int _sum (int a, int b) {
	return a + b - (a + b >= MOD? MOD : 0);
}

int _mul (int a, int b) {
	return 1LL * a * b % MOD;
}

int _pow (int a, int b) {
	if (!b) 
		return 1;
	int res = _pow (a, b >> 1);
	res = _mul (res, res);
	if (b & 1)
		res = _mul (res, a);
	return res;
}

// SamMHD :: Jun27-2019 :: Another Day with Shayan...