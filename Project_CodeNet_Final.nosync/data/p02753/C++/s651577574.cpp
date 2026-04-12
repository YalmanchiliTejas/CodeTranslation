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

int main() {
	string s;
	cin >> s;
	bool a = false, b = false;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'A') {
			a = true;
		}
		if (s[i] == 'B') {
			b = true;
		}
	}
	if (a && b) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}