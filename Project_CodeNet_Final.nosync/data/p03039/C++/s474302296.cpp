#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10, mod = 1e9 + 7;
int n, m, k, ans, fac[N], inv[N];

int sum(int a, int b) {
	return a + b >= mod? a + b - mod: a + b < 0? a + b + mod: a + b;
}

int mul(int a, int b) {
	a %= mod;
	b %= mod;
	return (a * b) % mod;
}

void _sum(int &a, int b) {
	a = sum(a, b);
}

void _mul(int &a, int b) {
	a = mul(a, b);
}

template <typename Head, typename ...Tail>
int mul(Head H, Tail ...T) {
	return mul(H, mul(T...));
}

template <typename Head2, typename ...Tail2>
int sum(Head2 H, Tail2 ...T) {
	return sum(H, sum(T...));
}

int pw(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1)
			_mul(res, a);
		_mul(a, a);
		b /= 2;
	}
	return res;
}

int C(int i, int j) {
	return i > j? 0: mul(fac[j], inv[i], inv[j - i]);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = mul(i, fac[i - 1]);
		inv[i] = pw(fac[i], mod - 2);
	}
	
	cin >> n >> m >> k;
	int tmp = C(k - 2, n * m - 2), s = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			s += i + j;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			_sum(ans, mul(s, tmp));
			
			if (j == m - 1) 
				s -= m * (n - 1 - i);
			else
				s += (n - i - 1) * (j + 1) - (n - i) * (m - j - 1);
		}
	cout << ans << endl;
}