#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fsp(x) fixed << setprecision(x)
#define xout cerr
const ll inf = LLONG_MAX;
const long double pi = acosl(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

//ModInt
//#include <vector>
template<long long M>
long long modpow(long long a, long long n) {
	a %= M;
	if (a == 0 && n == 0) return 1;
	if (a == 0) return 0;
	if (a == 1) return 1;
	long long b = 1, cnt = 0;
	while (b < M && cnt < n) {
		b *= a;
		cnt++;
	}
	if (b < M) return b;
	b %= M;
	return modpow<M>(b, n / cnt) * modpow<M>(a, n % cnt) % M;
}

template<long long M>
struct modint {
	long long val;

	void sub(long long &n) {
		if (n < 0) {
			long long m = (-n) % M;
			n = M - m;
		}
		else n %= M;
	}

	//コンストラクタ
	modint<M>(long long right) : val(right) {sub(val);}

	modint<M> operator+ (modint<M> right) {
		modint<M> ret = (this -> val) + right.val;
		return ret;
	}
	modint<M> operator+ (long long right) {
		sub(right);
		modint<M> ret = (this -> val) + right;
		return ret;
	}
	modint<M> operator- (modint<M> right) {
		modint<M> ret = (this -> val) - right.val;
		return ret;
	}
	modint<M> operator- (long long right) {
		sub(right);
		modint<M> ret = (this -> val) - right;
		return ret;
	}
	modint<M> operator* (modint<M> right) {
		modint<M> ret = (this -> val) * right.val;
		return ret;
	}
	modint<M> operator* (long long right) {
		sub(right);
		modint<M> ret = (this -> val) * right;
		return ret;
	}

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

	modint<M>& operator++ () {*this += 1; return *this - 1;}
	modint<M> operator++ (int) {*this += 1; return *this;}
	modint<M>& operator-- () {*this -= 1; return *this + 1;}
	modint<M> operator-- (int) {*this -= 1; return *this;}

	modint<M> operator/ (modint<M> right) {
		modint<M> ret = *this * modpow<M>(right.val, M - 2);
		return ret;
	}
	modint<M> operator/ (long long right) {
		sub(right);
		modint<M> ret = *this * modpow<M>(right, M - 2);
		return ret;
	}

	void operator/= (modint<M> right) {*this = *this / right;}
	void operator/= (long long right) {*this = *this / right;}
};

std::vector<long long> factorial;
std::vector<long long> factorial_inv;

template<long long M>
void make_table(long long n) {
	factorial.resize(n + 1, 1);
	factorial_inv.resize(n + 1, 1);
	for (long long i = 2; i <= n; i++) {
		factorial[i] = factorial[i - 1] * i % M;
	}
	factorial_inv[n] = modpow<M>(factorial[n], M - 2);
	for (long long i = n - 1; i >= 0; i--) {
		factorial_inv[i] = factorial_inv[i + 1] * (i + 1) % M;
	}
}

template<long long M>
modint<M> permutation(long long n, long long r) {
	if (n <= factorial.size()) {
		modint<M> a = factorial[n], b = factorial_inv[n - r];
		return a * b;
	}
	else {
		std::cerr << "attention: factorial table is not constructed." << std::endl;
		modint<M> ret = 1;
		for (long long i = 0; i < r; i++) ret *= n - i;
		return ret;
	}
}

template<long long M>
modint<M> combination(long long n, long long r) {
	r = std::min(r, n - r);
	if (n <= factorial.size()) {
		return permutation<M>(n, r) * factorial_inv[r];
	}
	else {
		std::cerr << "attention: factorial table is not constructed." << std::endl;
		modint<M> ret = 1;
		for (long long i = 0; i < r; i++) {
			ret *= n - i;
			ret *= modpow<M>(i + 1, M - 2);
		}
		return ret;
	}
}

template<long long M>
std::ostream &operator<< (std::ostream &out, modint<M> tgt) {out << tgt.val; return out;}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//const ll p = 1e9 + 7;
	const ll p = 998244353;

	ll n, s;
	cin >> n >> s;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	vector<vector<modint<p>>> dp(n, vector<modint<p>>(s + 1, 0));
	dp[0][0]++;
	if (a[0] <= s) dp[0][a[0]]++;
	for (ll i = 1; i < n; i++) {
		dp[i][0] += dp[i - 1][0] + 1;
		if (a[i] <= s) dp[i][a[i]] += dp[i - 1][0] + 1;
		for (ll j = 1; j < s; j++) {
			dp[i][j] += dp[i - 1][j];
			if (j + a[i] <= s) dp[i][j + a[i]] += dp[i - 1][j];
		}
	}

	modint<p> ans = 0;
	for (ll i = 0; i < n; i++) {
		ans += dp[i][s] * (n - i);
	}
	cout << ans << endl;
}
