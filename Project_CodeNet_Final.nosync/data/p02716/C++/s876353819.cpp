#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;

#define LL long long

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

LL mod(LL x, LL md) {
	return ((x % md) + md) % md;
}

class Mint {
public:
	static LL md;
	LL x;
	Mint(LL _x) {
		x = mod(_x, md);
	}
	Mint(const Mint &y) {
		x = mod(y.x, md);
	}
};

void MintMyExgcd(LL a, LL b, LL &x, LL &y) {
	// solve equation ax + by = 1 (mod m)
	LL md = Mint::md;
	if (b == 0) {
		y = 0;
		x = 1;
		return ;
	}
	MintMyExgcd(b, a % b, x, y);
	LL t = y;
	y = mod(x - (a / b) * y, md);
	x = t;
}

LL MintNY(LL x) {
	if (x == 0) {
		return 1;
	}
	LL md = Mint::md;
	LL a, b;
	MintMyExgcd(x, md, a, b);
	while (a < 0) {
		a += md;
	}
	return a;
}

/* LL gcd(LL a, LL b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
} */

Mint operator+(Mint a, Mint b) {
	return Mint(mod(a.x + b.x, Mint::md));
}
Mint operator-(Mint a, Mint b) {
	return Mint(mod(a.x - b.x, Mint::md));
}
Mint operator*(Mint a, Mint b) {
	return Mint(mod(a.x * b.x, Mint::md));
}
Mint operator/(Mint a, Mint b) {
	Mint c = Mint(MintNY(b.x));
	return Mint(mod(a.x * c.x, Mint::md));
}

Mint operator-(Mint a) {
	return Mint(-a.x);
}
bool operator==(Mint a, Mint b) {
	return a.x == b.x;
}
bool operator!=(Mint a, Mint b) {
	return a.x != b.x;
}
bool operator>(Mint a, Mint b) {
	return a.x > b.x;
}
bool operator<(Mint a, Mint b) {
	return a.x < b.x;
}
bool operator>=(Mint a, Mint b) {
	return a.x >= b.x;
}
bool operator<=(Mint a, Mint b) {
	return a.x <= b.x;
}

void operator+=(Mint &a, Mint b) {
	a = a + b;
}
void operator-=(Mint &a, Mint b) {
	a = a - b;
}
void operator*=(Mint &a, Mint b) {
	a = a * b;
}
void operator/=(Mint &a, Mint b) {
	a = a / b;
}

ostream& operator<<(ostream &out, Mint a) {
	out << a.x;
	return out;
}

istream& operator>>(istream &in, Mint &a) {
	in >> a.x;
	return in;
}

Mint factorial(LL n) {
	if (n == 0) {
		return Mint(1);
	}
	Mint res = 1;
	for (LL i = 1; i <= n; ++i) {
		res *= i;
	}
	return res;
}
Mint multiRange(LL s, LL t) {
	Mint res = 1;
	for (LL i = s; i <= t; ++i) {
		res *= i;
	}
	return res;
}

Mint getC(LL n, LL k) {
	if (n - k < k) {
		return getC(n, n - k);
	}
	return multiRange(n - k + 1, n) / factorial(k);
}

Mint getA(LL n, LL k) {
	return multiRange(n - k + 1, n);
}

Mint countNonNegativeDivision(LL n, LL k) {
	return getC(n + k - 1, k - 1);
}
Mint countPositiveDivision(LL n, LL k) {
	if (n < k) {
		return 0;
	}
	if (k <= 0) {
		return 0;
	}
	return getC(n - 1, k - 1);
}
Mint quickMod(Mint a, LL b) {
	Mint res = 1;
	while (b > 0) {
		if (b % 2) {
			res *= a;
		}
		a *= a;
		b /= 2;
	}
	return res;
}

LL Mint::md = 1000000007;

int n;
int *a;
int main() {
	scanf("%d", &n);
	a = new int[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	LL ***f = new LL**[n + 1];
	LL inf = 1;
	for (int i = 0; i < 16; ++i) {
		inf *= (LL)(10);
	}
	for (int i = 0; i <= n; ++i) {
		f[i] = new LL*[3];
		for (int j = 0; j < 3; ++j) {
			f[i][j] = new LL[2]; // 0 for last un-used, 1 for last used
			for (int k = 0; k < 2; ++k) {
				f[i][j][k] = -inf;
			}
		}
	}
	int maxEmpty = 2;
	if (n % 2) {
		maxEmpty = 3;
	}
	f[0][0][1] = a[0];
	f[1][1][1] = a[1];
	f[1][0][0] = a[0];
	int start = 2;
	if (maxEmpty == 3 && n > 2) {
		f[2][0][1] = (LL)(a[0]) + (LL)(a[2]);
		f[2][1][0] = max(a[1], a[0]);
		f[2][2][1] = a[2];
		start = 3;
	}
	for (int i = start; i < n; ++i) {
		for (int j = 0; j < maxEmpty; ++j) {
			if (j == 0) {
				f[i][j][0] = f[i - 1][j][1];
				f[i][j][1] = f[i - 1][j][0] + a[i];
			}
			else {
				f[i][j][0] = max(f[i - 1][j][1], f[i - 1][j - 1][0]);
				f[i][j][1] = f[i - 1][j][0] + a[i];
			}
		}
	}
	LL res = -inf;
	if (n % 2 == 0) {
		res = max(res, f[n - 1][0][0]);
		res = max(res, f[n - 1][0][1]);
		res = max(res, f[n - 1][1][0]);
		res = max(res, f[n - 1][1][1]);
	}
	else {
		res = max(res, f[n - 1][1][0]);
		res = max(res, f[n - 1][1][1]);
		res = max(res, f[n - 1][2][0]);
		res = max(res, f[n - 1][2][1]);
	}
	cout << res << endl;

	return 0;
}