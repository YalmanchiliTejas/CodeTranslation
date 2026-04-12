#include "bits/stdc++.h"

using namespace std;

#define Rep(b, e, i) for (int i = b; i <= e; i++)
#define rep(n, i) Rep(0, n - 1, i)

const int MOD = 1e9 + 7;
const int MAX = 200020;

typedef long long ll;

//階乗とその逆元
ll fac[MAX + 1], facInv[MAX + 1];

ll power(ll e, ll x)
{ //e^x % MOD
	if (x == 0)
		return 1LL;
	if (x % 2 != 0)
		return ((power(e, x - 1) * e) % MOD);
	ll temp = power(e, x / 2);
	return (temp * temp) % MOD;
}

ll nck(ll n, ll k)
{
	if (!(n >= k && k >= 0))
		return 0;
	ll temp = (fac[n] * facInv[n - k]) % MOD;
	return ((temp * facInv[k]) % MOD);
}

void fact(void)
{
	//階乗とその逆元
	fac[0] = facInv[0] = 1; //0! = 1
	//(x!)^(-1) ≡ (x!)^(p-2) (mod p)
	Rep(1, MAX, i) fac[i] = (fac[i - 1] * i) % MOD;
	facInv[MAX] = power(fac[MAX], MOD - 2);
	Rep(1, MAX - 1, i) facInv[MAX - i] = (facInv[MAX - i + 1] * (MAX - i + 1)) % MOD;
}

template <int p>
struct Modint
{
	int value;

	Modint() : value(0) {}
	Modint(long x) : value(x >= 0 ? x % p : (p + x % p) % p) {}

	inline Modint &operator+=(const Modint &b)
	{
		if ((this->value += b.value) >= p)
			this->value -= p;
		return (*this);
	}
	inline Modint &operator-=(const Modint &b)
	{
		if ((this->value += p - b.value) >= p)
			this->value -= p;
		return (*this);
	}
	inline Modint &operator*=(const Modint &b)
	{
		this->value = (int)((1LL * this->value * b.value) % p);
		return (*this);
	}
	inline Modint &operator/=(const Modint &b)
	{
		(*this) *= b.inverse();
		return (*this);
	}

	Modint operator+(const Modint &b) const { return Modint(*this) += b; }
	Modint operator-(const Modint &b) const { return Modint(*this) -= b; }
	Modint operator*(const Modint &b) const { return Modint(*this) *= b; }
	Modint operator/(const Modint &b) const { return Modint(*this) /= b; }

	inline Modint &operator++(int) { return (*this) += 1; }
	inline Modint &operator--(int) { return (*this) -= 1; }

	inline bool operator==(const Modint &b) const { return this->value == b.value; }
	inline bool operator!=(const Modint &b) const { return this->value != b.value; }
	inline bool operator<(const Modint &b) const { return this->value < b.value; }
	inline bool operator<=(const Modint &b) const { return this->value <= b.value; }
	inline bool operator>(const Modint &b) const { return this->value > b.value; }
	inline bool operator>=(const Modint &b) const { return this->value >= b.value; }

	//requires that "this->value and p are co-prime"
	// a_i * v + a_(i+1) * p = r_i
	// r_i = r_(i+1) * q_(i+1) * r_(i+2)
	// q == 1 (i > 1)
	// reference: https://atcoder.jp/contests/agc026/submissions/2845729 (line:93)
	inline Modint inverse() const
	{
		assert(this->value != 0);
		int r0 = p, r1 = this->value, a0 = 0, a1 = 1;
		while (r1)
		{
			int q = r0 / r1;
			r0 -= q * r1;
			swap(r0, r1);
			a0 -= q * a1;
			swap(a0, a1);
		}
		return Modint(a0);
	}

	friend istream &operator>>(istream &is, Modint<p> &a)
	{
		long t;
		is >> t;
		a = Modint<p>(t);
		return is;
	}
	friend ostream &operator<<(ostream &os, const Modint<p> &a)
	{
		return os << a.value;
	}
};

using Int = Modint<MOD>;

void solve(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	fact();
	Int ans = 0;
	for (int d = 1; d < n; d++)
	{
		ans += Int(1L * d * (n - d) * m * m) * Int(nck(n*m-2, k-2));
	}
	for (int d = 1; d < m; d++)
	{
		ans += Int(1L * d * (m - d) * n * n) * Int(nck(n*m-2, k-2));
	}
	cout << ans << endl;
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
