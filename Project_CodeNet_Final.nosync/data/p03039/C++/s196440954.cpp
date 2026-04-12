#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define swap(a, b)    do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while(0)
#define repd(i, a, b) for(typeof(b) i = a; i < (b); ++i)
#define rep(i, n)     repd(i, 0, n)
#define dump(x)       cerr << #x << " = " << (x) << endl
#define debug(x)      cerr << "L" << __LINE__ << ": " << #x << " = " << (x) << endl
#define YesNo(x)      cout << ((x) ? "Yes" : "No") << endl
#define YESNO(x)      cout << ((x) ? "YES" : "NO") << endl
#define absi(x)       ( ((x) >= 0) ? (x) : (-(x)) )

class modint {
private:
	std::int64_t number;
	static const std::int64_t modulo;
public:
	static vector<modint> fac;
	static vector<modint> fac_inv;
	modint() : number(0) {}
	modint(const std::uint64_t new_number) { set(new_number); }
	modint(const modint& m) : number(m.number) {}

	void set(const std::int64_t new_number) { number = new_number % modulo; if(number < 0) number += modulo; }
	std::int64_t get() const { return number; }

	modint operator++(int) { modint ret = *this; ++(*this); return ret; } // Postfix Increment
	modint operator--(int) { modint ret = *this; --(*this); return ret; } // Postfix Decrement
	modint& operator++() { *this += 1; return *this; } // Prefix Increment
	modint& operator--() { *this -= 1; return *this; } // Prefix Decrement

	bool operator!() const noexcept { return !static_cast<bool>(*this); } // Logical Not
	modint operator+() const { return *this; }                                 // Unary Plus
	modint operator-() const { modint ret(*this);ret.set(-number);return ret;} // Unary Negation
	explicit operator std::int64_t() const noexcept{ return number; }      // Cast
	explicit operator bool()         const noexcept{ return number != 0; } // Cast

	modint& operator=(const std::int64_t i) { set(i); return *this; }

	modint operator*=(const modint& m) { set(number * m.number); return *this; }
	modint operator/=(const modint& m) { *this *= modint::inv(m); return *this; }
	modint operator%=(const modint& m) { set(number % m.number); return *this; }
	modint operator+=(const modint& m) { set(number + m.number); return *this; }
	modint operator-=(const modint& m) { set(number - m.number); return *this; }
	modint operator*=(const std::int64_t& i) { set(number * i); return *this; }
	modint operator/=(const std::int64_t& i) { *this /= modint(i); return *this; }
	modint operator%=(const std::int64_t& i) { set(number % i); return *this; }
	modint operator+=(const std::int64_t& i) { set(number + i); return *this; }
	modint operator-=(const std::int64_t& i) { set(number - i); return *this; }

	modint factorial() const {
		if(get() < fac.size()) {
			return fac.at(get());
		}
		
		std::int64_t ret = static_cast<std::int64_t>(fac.back());
		for(std::int64_t i = fac.size(); i <= get(); ++i) {
			ret = (ret * i) % modulo;
		}

		return modint(ret);
	}

	static modint pow(const modint& m1, const modint& m2) {
		std::int64_t base     = m1.get();
		std::int64_t exponent = m2.get();
		std::int64_t ret = 1;

		//if(exponent == 0)      return modint(1);
		//else if(exponent == 1) return modint(base);
		//else if(base == 0)     return modint(0);
		//else if(base == 1)     return modint(1);

		while(exponent > 0) {
			if(exponent & 1) ret = (ret * base) % modulo;
			base = (base * base) % modulo;
			exponent >>= 1;
		}

		return modint(ret);
	}

	/* Inverse Element */
	static modint inv(const modint& m) {
		std::int64_t a = m.get();
		std::int64_t b = modulo;
		std::int64_t u = 1;
		std::int64_t v = 0;

		std::int64_t aa = a;

		while(b != 0) {
			std::int64_t t = a / b;
			a -= t * b;
			swap(a, b);
			u -= t * v;
			swap(u, v);
		}

		modint ret(u);
		return ret;
	}

	static modint nPr(const modint& n, const modint& r);
	static modint nCr(const modint& n, const modint& r);
	static void init_factorial(const std::int64_t max_fac_index = 510000);
};

const std::int64_t modint::modulo = 1000000007;
vector<modint> modint::fac;
vector<modint> modint::fac_inv;
/* Arithmetic */
const modint operator*(const modint& m1, const modint& m2) { return modint(m1) *= m2; }
const modint operator/(const modint& m1, const modint& m2) { return modint(m1) /= m2; }
const modint operator%(const modint& m1, const modint& m2) { return modint(m1) %= m2; }
const modint operator+(const modint& m1, const modint& m2) { return modint(m1) += m2; }
const modint operator-(const modint& m1, const modint& m2) { return modint(m1) -= m2; }
const modint operator*(const modint& m, const std::int64_t& i) { return modint(m) *= i; }
const modint operator/(const modint& m, const std::int64_t& i) { return modint(m) /= i; }
const modint operator%(const modint& m, const std::int64_t& i) { return modint(m) %= i; }
const modint operator+(const modint& m, const std::int64_t& i) { return modint(m) += i; }
const modint operator-(const modint& m, const std::int64_t& i) { return modint(m) -= i; }
const modint operator*(const std::int64_t& i, const modint& m) { return modint(i) *= m; }
const modint operator/(const std::int64_t& i, const modint& m) { return modint(i) /= m; }
const modint operator%(const std::int64_t& i, const modint& m) { return modint(i) %= m; }
const modint operator+(const std::int64_t& i, const modint& m) { return modint(i) += m; }
const modint operator-(const std::int64_t& i, const modint& m) { return modint(i) -= m; }
/* Shift (iostream) */
std::ostream& operator<<(std::ostream& os, const modint m) { os << m.get(); return os; }
std::istream& operator>>(std::istream& is, modint& m) { std::int64_t i; is >> i; m.set(i); return is; }
/* Compare */
bool operator<(const modint& m1, const modint& m2) { return m1.get() < m2.get(); }
bool operator>(const modint& m1, const modint& m2) { return m2 < m1; }
bool operator<=(const modint& m1, const modint& m2) { return !(m1 > m2); }
bool operator>=(const modint& m1, const modint& m2) { return !(m1 < m2); }
bool operator==(const modint& m1, const modint& m2) { return !(m1 < m2) && !(m1 > m2); }
bool operator!=(const modint& m1, const modint& m2) { return !(m1 == m2); }
/* Power (evil implementation) */
modint operator^(const modint& m1, const modint& m2) { return modint::pow(m1, m2); };

modint modint::nPr(const modint& n, const modint& r) {
	init_factorial();
	if(n < r) return 0;
	return fac[n.get()] * fac_inv[n.get() - r.get()];
}

modint modint::nCr(const modint& n, const modint& r) {
	init_factorial();
	if(n < r) return 0;
	return fac[n.get()] * fac_inv[r.get()] * fac_inv[n.get() - r.get()];
}

void modint::init_factorial(const std::int64_t max_fac_index) {
	static bool is_initted = false;
	if(is_initted) return;
	is_initted = true;

	fac     = vector<modint>(max_fac_index);
	fac[0] = fac[1] = 1;
	for(std::int64_t i = 2; i < max_fac_index; ++i) {
		fac[i] = fac[i - 1] * i;
	}

	fac_inv = vector<modint>(max_fac_index);
	fac_inv[0] = fac_inv[1] = 1;
	fac_inv[max_fac_index - 1] = inv(fac[max_fac_index - 1]);
	for(std::int64_t i = max_fac_index - 2; i >= 0; --i) {
		fac_inv[i] = fac_inv[i + 1] * (i + 1);
	}
}

/*
ある2マスの距離を何回加算することになるか：
\begin{align*}
_{NM-2}C_{K-2}
\end{align*}
X座標の差を$d$となる2マスの選び方：
\begin{align*}
(N-d) \times M^{2} \left( \begin{array}{rcl}
N-d & \dots & X座標の選び方。左側は 1 \leq X \leq N-d であり、右側は左側に合わせて決まる。 \\
M^2 & \dots & Y座標の選び方。両方とも 1 \leq Y \leq M から好きに選べる。
\end{array} \right)
\end{align*}
ありうる全ての$d(1 \leq d \leq N-1)$について、距離の総和を求めると：
\begin{align*}
\sum_{d=1}^{N-1} d \times (N-d) \times M^{2} = \frac{1}{6}M^{2}(N-1)N(N+1)
\end{align*}
Y座標については、
\begin{align*}
\sum_{d=1}^{M-1} d \times (M-d) \times N^{2} = \frac{1}{6}N^{2}(M-1)M(M+1)
\end{align*}
よって、最終的な解は、
\begin{align*}
  & _{NM-2}C_{K-2} \times \sum_{d=1}^{N-1} d \times (N-d) \times M^{2} + _{NM-2}C_{K-2} \times \sum_{d=1}^{M-1} d \times (M-d) \times N^{2} \\ 
= & _{NM-2}C_{K-2} \times \left( \sum_{d=1}^{N-1} d \times (N-d) \times M^{2} + \sum_{d=1}^{M-1} d \times (M-d) \times N^{2} \right)        \\ 
= & _{NM-2}C_{K-2} \times \left( \frac{1}{6}M^{2}(N-1)N(N+1) + \frac{1}{6}N^{2}(M-1)M(M+1) \right)                                          \\ 
= & _{NM-2}C_{K-2} \times \left( \frac{1}{6}MN \left( M(N-1)(N+1) + N(M-1)(M+1) \right) \right)                                             \\ 
= & _{NM-2}C_{K-2} \times \left( \frac{1}{6}MN (M+N)(MN-1) \right)
\end{align*}
 */

int main(int argc, const char* argv[]) {
	modint n, m, k;
	cin >> n >> m >> k;

	modint ret = modint::nCr(n * m - 2, k - 2) * m * n * (m+n) * (m*n-1) / 6;

	cout << ret << endl;

	return 0;
}
