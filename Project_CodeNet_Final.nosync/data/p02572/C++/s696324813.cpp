#include <bits/stdc++.h>
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define FSP(x) fixed << setprecision(x)
using namespace std;
using ll = long long;
constexpr ll INF = LLONG_MAX;
constexpr long double PI = acosl(-1);
void Yes() {cout << "Yes\n";}
void No() {cout << "No\n";}
void YES() {cout << "YES\n";}
void NO() {cout << "NO\n";}

#include <iostream>
#include <vector>

/*	NOTICE : followings requires template argument to be prime
		- use of modinv
		- division by modint
		- use of factorial_inv
*/

/*	verified : 2020/07/30
		AtCoder, Knapsack for All Subsets
		https://atcoder.jp/contests/abc169/tasks/abc169_f
		AtCoder, Bouquet
		https://atcoder.jp/contests/abc156/tasks/abc156_d
*/

template<long long P>
long long modinv(long long n) {
	long long a = P, u = 1, v = 0;
	while (a) {
		long long t = n / a;
		n -= t * a;
		std::swap(n, a);
		u -= t * v;
		std::swap(u, v);
	}
	u %= P;
	if (u < 0) u += P;
	return u;
}

template<long long M>
struct modint {
	long long val;

	modint<M>(long long right) : val(right) {sub(val);}
	modint<M>() {val = 0;}

	void sub(long long &n) {
		if (n < 0) {
			long long m = (-n) % M;
			n = M - m;
		}
		else n %= M;
	}

	modint<M> operator+ (modint<M> right) {return (this -> val) + right.val;}
	modint<M> operator+ (long long right) {sub(right); return (this -> val) + right;}
	modint<M> operator- (modint<M> right) {return (this -> val) - right.val;}
	modint<M> operator- (long long right) {sub(right); return (this -> val) - right;}
	modint<M> operator* (modint<M> right) {return (this -> val) * right.val;}
	modint<M> operator* (long long right) {sub(right); return (this -> val) * right;}

	bool operator== (modint<M> right) {return ((this -> val) == right.val);}
	bool operator== (long long right) {sub(right); return ((this -> val) == right);}
	bool operator!= (modint<M> right) {return ((this -> val) != right.val);}
	bool operator!= (long long right) {sub(right); return ((this -> val) != right);}
	bool operator<= (modint<M> right) {return ((this -> val) <= right.val);}
	bool operator<= (long long right) {sub(right); return ((this -> val) <= right);}
	bool operator>= (modint<M> right) {return ((this -> val) >= right.val);}
	bool operator>= (long long right) {sub(right); return ((this -> val) >= right);}
	bool operator< (modint<M> right) {return ((this -> val) < right.val);}
	bool operator< (long long right) {sub(right); return ((this -> val) < right);}
	bool operator> (modint<M> right) {return ((this -> val) > right.val);}
	bool operator> (long long right) {sub(right); return ((this -> val) > right);}

	void operator+= (modint<M> right) {*this = *this + right;}
	void operator+= (long long right) {*this = *this + right;}
	void operator-= (modint<M> right) {*this = *this - right;}
	void operator-= (long long right) {*this = *this - right;}
	void operator*= (modint<M> right) {*this = *this * right;}
	void operator*= (long long right) {*this = *this * right;}

	modint<M>& operator++ () {*this += 1; return *this;}
	modint<M> operator++ (int) {*this += 1; return *this - 1;}
	modint<M>& operator-- () {*this -= 1; return *this;}
	modint<M> operator-- (int) {*this -= 1; return *this + 1;}

	modint<M> operator/ (modint<M> right) {return *this * modinv<M>(right.val);}
	modint<M> operator/ (long long right) {sub(right); return *this * modinv<M>(right);}

	void operator/= (modint<M> right) {*this = *this / right;}
	void operator/= (long long right) {*this = *this / right;}
};

std::vector<long long> factorial;
std::vector<long long> factorial_inv;

template<long long P>
void make_table(long long n) {
	factorial.resize(n + 1, 1); factorial_inv.resize(n + 1, 1);
	for (long long i = 2; i <= n; i++) {
		factorial[i] = factorial[i - 1] * i % P;
	}
	factorial_inv[n] = modinv<P>(factorial[n]);
	for (long long i = n - 1; i >= 0; i--) {
		factorial_inv[i] = factorial_inv[i + 1] * (i + 1) % P;
	}
}

template<long long P>
modint<P> permutation(long long n, long long r) {
	if (n <= factorial.size()) {
		modint<P> a = factorial[n], b = factorial_inv[n - r];
		return a * b;
	}
	else {
		std::cerr << "attention : factorial table is not constructed" << '\n';
		modint<P> ret = 1;
		for (long long i = 0; i < r; i++) ret *= n - i;
		return ret;
	}
}

template<long long P>
modint<P> combination(long long n, long long r) {
	r = std::min(r, n - r);
	if (n <= factorial.size()) {
		return permutation<P>(n, r) * factorial_inv[r];
	}
	else {
		std::cerr << "attention : factorial table is not constructed" << '\n';
		modint<P> ret = 1;
		for (long long i = 0; i < r; i++) {
			ret *= n - i;
			ret /= i + 1;
		}
		return ret;
	}
}

template<long long M>
modint<M> modpow(long long a, long long n) {
	a %= M;
	if (n == 0) return 1;
	if (a == 0) return 0;
	if (a == 1) return 1;
	long long b = 1, cnt = 0;
	while (b < M && cnt < n) {
		b *= a;
		cnt++;
	}
	modint<M> ret;
	if (b < M) ret = b;
	else {
		b %= M;
		ret = modpow<M>(b, n / cnt) * modpow<M>(a, n % cnt);
	}
	return ret;
}

template<long long M>
std::ostream &operator<< (std::ostream &out, modint<M> tgt) {out << tgt.val; return out;}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	constexpr ll P = 1e9 + 7;
	//constexpr ll P = 998244353;

	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	vector<ll> sum(n + 1, 0);
	for (ll i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];

	modint<P> ans = 0;
	for (ll i = n - 1; i >= 0; i--) {
		ans += (modint<P>)a[i] * sum[i];
	}
	cout << ans << endl;
}