#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <iomanip>

typedef long double ld;
typedef long long ll;

using namespace std;


/* TEMPLATE ENDS HERE */

ll n, k;

ll f(ll b) {
	ll ret = 0;
	if (k >= b) {
		return ret;
	}
	ret = (n / b) * (b - k);
	if (k == 0) {
		ret--;
	}
	ll mod = n % b;
	if (mod >= k) {
		ret += mod - k + 1;
	}
	return ret;
}

int main() {
	cout << fixed << setprecision(12);	
	cin >> n >> k;
	ll ret = 0;
	for (int b = 1; b <= n; b++) {
		ret += f(b);
	}
	cout << ret << endl;
	return 0;
}


ll MOD = ((ll)1e9 + 7);

struct mod {
	ll x;

	mod(ll tx = 0) {
		x = tx;
		x %= MOD;
	}
	
	mod& operator=(const ll & tx) {
		x = tx % MOD;
		return *this;
	}
	
	mod& operator=(const mod & m2) {
		x = m2.x;
		return *this;
	}

	mod operator+(const mod& m2) const {
		return mod((x + m2.x) % MOD);
	}

	mod& operator+=(const mod& m2) {
		x += m2.x;
		x %= MOD;
		return *this;
	}

	mod operator-(const mod & m2) const {
		return mod((x - m2.x + MOD) % MOD);
	}

	mod& operator-=(const mod & m2) {
		x -= m2.x;
		x = (x + MOD) % MOD;
		return *this;
	}

	mod operator*(const mod & m2) const {
		return mod((x * m2.x) % MOD);
	}

	mod& operator*=(const mod & m2) {
		x *= m2.x;
		x %= MOD;
		return *this;
	}

	mod mypow(ll k) const {
		mod ret = 1;
		mod cur = x;
		while (k) {
			if (k & 1) {
				ret *= cur;
			}
			cur *= cur;
			k >>= 1;
		}
		return ret;
	}

	mod inv() const {
		return mypow(MOD - 2);
	}

	mod operator/(const mod & m2) const {
		return (*this) * m2.inv();
	}

	mod& operator/=(const mod & m2) {
		x *= m2.inv().x;
		x %= MOD;
		return *this;
	}

	bool operator<(const mod & m2) const {
		return x < m2.x;
	}
};

ostream &operator<<(ostream & os, const mod & m) {
	return os << m.x;
}

