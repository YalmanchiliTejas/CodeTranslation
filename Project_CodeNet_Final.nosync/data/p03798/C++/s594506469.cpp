#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000000000000
#define MOD 1000000007
typedef pair<int, int> P;

bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int mod_pow(int n, int p, int m) {
	if (p == 0) return 1;
	if (p % 2 == 0) {
		int t = mod_pow(n, p / 2, m);
		return (t * t) % m;
	}
	return n * mod_pow(n, p - 1, m) % m;
}
int extGCD(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long d = extGCD(b, a % b, y, x);
	y -= a / b * x;
	return d;
}
int modinv(int a, int m) {
	int b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
int digit(int x) {
	int cnt = 0;
	while (x > 0) {
		cnt += x % 10;
		x /= 10;
	}
	return cnt;
}
int read() {
	int tmp;
	cin >> tmp;
	return tmp;
}
int xor128() {
	static int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	int t = (x xor (x << 11));
	x = y; y = z; z = w;
	return (w = (w xor (w >> 19)) xor (t xor (t >> 8)));
}

signed main() {
	int n;
	int a[100005];
	cin >> n;
	rep(i, n) {
		char c;
		cin >> c;
		if (c == 'o') a[i] = 1;
		else a[i] = 0;
	}

	P p[4] = { {0,0},{0,1},{1,0},{1,1} };
	rep(i, 4) {
		int ans[100005];
		ans[0] = p[i].first, ans[1] = p[i].second;
		if ((a[0] && !ans[0]) || (!a[0] && ans[0])) ans[n - 1] = ans[1];
		else ans[n - 1] = 1 - ans[1];
		bool finish = false;
		for (int i = 1; i <= n - 2; i++) {
			int next;
			if ((a[i] && !ans[i]) || (!a[i] && ans[i])) next = ans[i - 1];
			else next = 1 - ans[i - 1];
			if (i == n - 2 && next == ans[n - 1]) {
				if (a[n - 1] && !ans[n - 1]) finish = (ans[0] == ans[n - 2]);
				else if (a[n - 1] && ans[n - 1]) finish = (ans[0] != ans[n - 2]);
				else if (!a[n - 1] && !ans[n - 1]) finish = (ans[0] != ans[n - 2]);
				else finish = (ans[0] == ans[n - 2]);
			}
			ans[i + 1] = next;
		}
		if (finish) {
			rep(i, n) {
				if (ans[i] == 0) cout << "S";
				else cout << "W";
			}
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;

	return 0;
}