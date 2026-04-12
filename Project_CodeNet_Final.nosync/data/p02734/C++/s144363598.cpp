#include <iostream>
#include <vector>

long long modinv(long long n, long long MOD) {
	long long a = MOD, u = 1, v = 0;
	while (a) {
		long long t = n / a;
		n -= t * a; std::swap(n, a);
		u -= t * v; std::swap(u, v);
	}
	u %= MOD;
	if (u < 0) u += MOD;
	return u;
}

template<long long MOD> struct modint {
	long long value = 0;
	void f() {
		value %= MOD;
		if (value < 0) value += MOD;
	}
	modint(long long n) : value(n) {f();}
	modint() : value(0) {}
	modint<MOD> operator+(modint<MOD> right) {modint<MOD> ret = (this -> value) + right.value; return ret;}
	modint<MOD> operator-(modint<MOD> right) {modint<MOD> ret = (this -> value) - right.value; return ret;}
	modint<MOD> operator*(modint<MOD> right) {modint<MOD> ret = (this -> value) * right.value; return ret;}
	modint<MOD> operator/(modint<MOD> right) {modint<MOD> ret = (this -> value) * modinv(right.value, MOD); return ret;}
	modint<MOD> operator+=(modint<MOD> right) {return *this = *this + right;}
	modint<MOD> operator-=(modint<MOD> right) {return *this = *this - right;}
	modint<MOD> operator*=(modint<MOD> right) {return *this = *this * right;}
	modint<MOD> operator/=(modint<MOD> right) {return *this = *this / right;}
	bool operator<(modint<MOD> right) {return ((this -> value) < right.value);}
	bool operator>(modint<MOD> right) {return ((this -> value) > right.value);}
	bool operator==(modint<MOD> right) {return ((this -> value) == right.value);}
	bool operator!=(modint<MOD> right) {return ((this -> value) != right.value);}
	bool operator<=(modint<MOD> right) {return ((this -> value) <= right.value);}
	bool operator>=(modint<MOD> right) {return ((this -> value) >= right.value);}
	modint<MOD>& operator++() {*this += 1; return *this;}
	modint<MOD> operator++(int) {*this += 1; return *this - 1;}
	modint<MOD>& operator--() {*this -= 1; return *this;}
	modint<MOD> operator--(int) {*this -= 1; return *this + 1;}
};
template<long long MOD> modint<MOD> operator+(long long left, modint<MOD> right) {return right + left;}
template<long long MOD> modint<MOD> operator-(long long left, modint<MOD> right) {return right * -1 + left;}
template<long long MOD> modint<MOD> operator*(long long left, modint<MOD> right) {return right * left;}
template<long long MOD> modint<MOD> operator/(long long left, modint<MOD> right) {
	return modinv(right.value, MOD) * (left % MOD);
}

template<long long MOD> modint<MOD> modpow(modint<MOD> a, long long n) {
	if (n == 0) return 1;
	if (a == 0) return 0;
	modint<MOD> ret = a;
	long long cnt = 1;
	while (cnt * 2 <= n) {
		ret *= ret;
		cnt *= 2;
	}
	return ret * modpow<MOD>(a, n - cnt);
}

long long modpow(long long a, long long n, long long MOD) {
	if (n == 0) return 1;
	if (a == 0) return 0;
	long long ret = a % MOD, cnt = 1;
	while (cnt * 2 <= n) {
		ret *= ret; ret %= MOD;
		cnt *= 2;
	}
	return ret * modpow(a, n - cnt, MOD) % MOD;
}

std::vector<long long> factorial;
std::vector<long long> factorial_inv;

template<long long P> void make_table(int n) {
	factorial.resize(n + 1, 1);
	factorial_inv.resize(n + 1, 1);
	for (int i = 1; i <= n; i++) factorial[i] = factorial[i - 1] * i % P;
	factorial_inv[n] = modinv(factorial[n], P);
	for (int i = n - 1; i >= 0; i--) factorial_inv[i] = factorial_inv[i + 1] * (i + 1) % P;
}

template<long long P> modint<P> permutation(int n, int r) {
	if (n <= factorial.size()) return factorial[n] * factorial_inv[n - r];
	std::cerr << "attention : factorial table is not constructed" << std::endl;
	r = std::min(r, n - r);
	modint<P> ret = 1;
	for (int i = 0; i < r; i++) ret *= n - i;
	return ret;
}

template<long long P> modint<P> combination(int n, int r) {
	if (n <= factorial.size()) return permutation<P>(n, r) * factorial_inv[r];
	std::cerr << "attention : factorial table is not constructed" << std::endl;
	r = std::min(r, n - r);
	modint<P> ret = 1;
	for (int i = 0; i < r; i++) {
		ret *= n - i;
		ret /= i + 1;
	}
	return ret;
}

template<long long MOD> std::ostream& operator<<(std::ostream& os, const modint<MOD>& target) {
	os << target.value;
	return os;
}

int main() {
	constexpr int P = 998244353;
	int n, s;
	std::cin >> n >> s;
	int a[n];
	for (auto& i : a) std::cin >> i;

	modint<P> dp[n][s + 1];
	if (a[0] <= s) dp[0][a[0]]++;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < s; j++) dp[i][j] = dp[i - 1][j];
		for (int j = 1; j <= s - a[i]; j++) {
			if (dp[i - 1][j] > 0) dp[i][j + a[i]] += dp[i - 1][j];
		}
		if (a[i] <= s) dp[i][a[i]] += i + 1;
	}

	modint<P> ans = 0;
	for (int i = 0; i < n; i++) ans += dp[i][s] * (n - i);
	std::cout << ans << '\n';
  
  return 0;
}