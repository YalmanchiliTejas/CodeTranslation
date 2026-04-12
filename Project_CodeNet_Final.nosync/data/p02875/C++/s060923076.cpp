//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//#include "math/modulo.h"

template<class T, T M>
struct modulo {
	T n;
	modulo(T n): n(n<0? n%M+M: n%M)   { }
	operator T() const                { return n;             }
	modulo operator-() const          { return modulo(-n);    }
	modulo operator+(const modulo &o) const { return modulo(n+o.n); }
	modulo operator-(const modulo &o) const { return modulo(n-o.n); }
	modulo operator*(const modulo &o) const { return modulo(n*o.n); }
	bool  operator< (const modulo &o) const { return n< o.n; }
	bool  operator<=(const modulo &o) const { return n<=o.n; }
	bool  operator> (const modulo &o) const { return n> o.n; }
	bool  operator>=(const modulo &o) const { return n>=o.n; }
	bool  operator==(const modulo &o) const { return n==o.n; }
	bool  operator!=(const modulo &o) const { return n!=o.n; }

	modulo pow(T n) const {
		modulo y = 1, x = *this;
		while (n) {
			if (n%2) y = y * x;
			n /= 2;
			x = x * x;
		}
		/*
		if (n==0) return 1;
		modulo y = pow(n/2);
		y = y*y;
		if (n%2) y = y * (*this);
		*/
		return y;
	}
	modulo inv() const {
		return pow(M-2);
	}
	modulo operator/(const modulo &o) const {
		return (*this) * o.inv();
	}

	T gcd_ext(T a, T b, T *x, T *y) {
		if (a == 0) {
			*x = 0;
			*y = 1;
			return b;
		}
		T x1, y1;
		T gcd = gcd_ext(b%a, a, &x1, &y1);
		*x = y1 - (b/a) * x1;
		*y = x1;
		return gcd;
	}
	modulo div(const modulo &o) const {
		T x, y;
		T g = gcd_ext(o.n, M, &x, &y);
		if (g != 1) return 0;
		else return modulo(n * (x % M));
	}

	friend ostream &operator<<(ostream &os, const modulo &x) {
		return os << x.n;
	}
};

typedef modulo<long,998244353> T;
//#include "math/comb.h"

void comb_inc_k(T &r, int n, int &k) {
        //C(n,k+1) = C(n,k) * (n-k) / (k+1)
	r = r * T(n-k) / T(k+1);
	k++;
}

void comb_dec_k(T &r, int n, int &k) {
        //C(n,k-1) = C(n,k) * k / (n-k+1)
	r = r * T(k) / T(n-k+1);
	k--;
}

void comb_inc_n(T &r, int &n, int k) {
        //C(n+1,k) = C(n,k) * (n+1) / (n+1-k)
	r = r * T(n+1) / T(n+1-k);
	n++;
}

void comb_dec_n(T &r, int &n, int k) {
        //C(n-1,k) = C(n,k) * (n-k) / n
	r = r * T(n-k) / T(n);
	n--;
}

T comb(int n, int k) {
    if (k*2 > n) k = n-k;
    if (n==0) return 0;
    T r = 1; //C(n,0)
    int i = 0;
    while (i<k) comb_inc_k(r, n, i);
    return r;
}


#define MAXN 100000

int n;


int input() {
	if (scanf("%d", &n) < 0) return 0;
	return 1;
}

void init() {
}

int solve() {
	T r = T(3).pow(n);
	int k = n/2;
	T e = comb(n, k);
	while (k+1<=n) {
		comb_inc_k(e, n, k);
		r = r - e*T(2).pow(n-k+1);
	}
	return r;
}

void output(int ans) {
	printf("%d\n", ans);
}

void cleanup() {
}

int main() {
	//int ca; scanf("%d", &ca);
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}



