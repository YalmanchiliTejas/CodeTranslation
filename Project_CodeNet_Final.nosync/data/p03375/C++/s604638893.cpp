//#include "debug.h"
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template<class T>
void printa(const T *a, int n) {
	cout << '[';
	for (int i=0; i<n; i++) {
		if (i) cout << ',';
		cout << a[i];
	}
	cout << ']' << endl;
}

template<class T>
void printa_nz(const T *a, int n) {
	cout << '[';
	for (int i=0, k=0; i<n; i++) {
		if (!(a[i]==0)) {
			if (k++) cout << ',';
			cout << i << ':' << a[i];
		}
	}
	cout << ']' << endl;
}

template<class T>
void printa_i(const T *a, int n) {
	cout << '[';
	for (int i=0; i<n; i++) {
		if (i) cout << ',';
		cout << i << ':' << a[i];
	}
	cout << ']' << endl;
}

template<class T1,class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &x) {
	return os<<'('<<x.first<<','<<x.second<<')';
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	int n = a.size();
	for (int i=0; i<n; i++) {
		if (i) os << ',';
		os << a[i];
	}
	os << ']';
	return os;
}

template<class K, class T>
ostream &operator<<(ostream &os, const map<K,T> &a) {
	os << '{';
	int i = 0;
	for (auto &x: a) {
		if (i) os << ',';
		i++;
		os << x.first << ':' << x.second;
	}
	return os << '}';
}


template<class T, class C>
ostream &operator<<(ostream &os, const set<T, C> &a) {
	os << '{';
	int i = 0;
	for (auto &x: a) {
		if (i) os << ',';
		i++;
		os << x;
	}
	return os << '}';
}


template<class T>
ostream &operator<<(ostream &os, const multiset<T> &a) {
	os << '{';
	int i = 0;
	for (auto &x: a) {
		if (i) os << ',';
		i++;
		os << x;
	}
	return os << '}';
}
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//modulo
//#include "math/modulo.h"
//#include "math/func.h"

template<class T>
T pow(T x, long n) {
	T y(1);
	while (n) {
		if (n%2) y = y * x;
		n /= 2;
		x = x * x;
	}
	return y;
}

template<class T>
T fac(long n) {
	T y(1);
	for (long i=2; i<n; i++)
		y = y * T(i);
	return y;
}

template<class T>
T gcd(const T &a, const T &b) {
	return a==0 ? b: gcd(b%a, b);
}

template<class T>
T gcd_ext(const T &a, const T &b, T *x, T *y) {
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	T x1, y1;
	T g = gcd_ext(b%a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;
	*y = x1;
	return g;
}


template<class T, T MOD=1000000007>
struct modulo {
	static T M;
	T n;
	modulo(T n=0): n(n<0? n%M+M: n%M)   { }
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
		return ::pow(*this, n);
	}
	modulo inv() const {
		return pow(M-2);
	}
	modulo operator/(const modulo &o) const {
		return (*this) * o.inv();
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

template<class T, T MOD>
T modulo<T,MOD>::M = MOD;

typedef modulo<long> T;
//#include "math/comb.h"

template<class T>
void comb_inc_k(T &r, int n, int &k) {
        //C(n,k+1) = C(n,k) * (n-k) / (k+1)
	r = r * T(n-k) / T(k+1);
	k++;
}

template<class T>
void comb_dec_k(T &r, int n, int &k) {
        //C(n,k-1) = C(n,k) * k / (n-k+1)
	r = r * T(k) / T(n-k+1);
	k--;
}

template<class T>
void comb_inc_n(T &r, int &n, int k) {
        //C(n+1,k) = C(n,k) * (n+1) / (n+1-k)
	r = r * T(n+1) / T(n+1-k);
	n++;
}

template<class T>
void comb_dec_n(T &r, int &n, int k) {
        //C(n-1,k) = C(n,k) * (n-k) / n
	r = r * T(n-k) / T(n);
	n--;
}

template<class T>
T comb(int n, int k) {
    if (k*2 > n) k = n-k;
    if (n==0) return 0;
    T r = 1; //C(n,0)
    int i = 0;
    while (i<k) comb_inc_k(r, n, i);
    return r;
}


#define MAXN 3001

int n;
long m;
T s[MAXN][MAXN];

int input() {
	if (scanf("%d %ld", &n, &m) < 0) return 0;
	return 1;
}

void init() {
}

long solve() {
	T::M = m;

	for (int j=0; j<=n; j++)
		s[0][j] = (j==0);
	for (int i=1; i<=n; i++) {
		s[i][0] = 1;
		for (int j=1; j<=i; j++) {
			s[i][j] = T(j+1) * s[i-1][j] + s[i-1][j-1];
			//cout << s[i][j] << ' ';
		}
		//cout << endl;
	}

	T c = 1, t= (n%2 ? -1: 1), r = 0;
	T p = 2;
	for (int i=n; i>=0; ) {
		//T p = T(2).pow(T(2).pow(n-i));
		for (int j=0; j<=i; j++)
			r = r + t * c * s[i][j] * T(2).pow((n-i)*j) * p;
		comb_dec_k(c, n, i);
		t = -t;
		p = p * p;
	}
	return r;
}

void output(long ans) {
	printf("%ld\n", ans);
}

void cleanup() {
}

int main() {
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}



