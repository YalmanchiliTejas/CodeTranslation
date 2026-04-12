#ifndef ___CLASS_MODINT
#define ___CLASS_MODINT

#include <cstdint>

template<std::uint32_t mod>
class modint {
private:
	std::uint32_t n;
public:
	modint() : n(0) {};
	modint(std::uint64_t n_) : n(n_ % mod) {};
	bool operator==(const modint& m) const { return n == m.n; }
	bool operator!=(const modint& m) const { return n != m.n; }
	std::uint32_t get() const { return n; }
	modint& operator+=(const modint& m) { n += m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator-=(const modint& m) { n += mod - m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator*=(const modint& m) { n = std::uint64_t(n) * m.n % mod; return *this; }
	modint operator+(const modint& m) const { return modint(*this) += m; }
	modint operator-(const modint& m) const { return modint(*this) -= m; }
	modint operator*(const modint& m) const { return modint(*this) *= m; }
	modint binpow(std::uint64_t b) const {
		modint ans = 1, m = modint(*this);
		while (b) {
			if (b & 1) ans *= m;
			m *= m;
			b >>= 1;
		}
		return ans;
	}
	modint inv() { return (*this).binpow(mod - 2); }
};

#endif // ___CLASS_MODINT

#include <vector>
#include <iostream>
using namespace std;
using modulo = modint<1000000007>;
int main() {
	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	vector<modulo> fact(N + 1), factinv(N + 1);
	for (int i = 0; i <= N; ++i) {
		fact[i] = (i > 0 ? fact[i - 1] * i : 1);
		factinv[i] = fact[i].inv();
	}
	vector<modulo> dp(N + 1);
	dp[0] = fact[N];
	for (int i = A; i <= B; ++i) {
		for (int j = N; j >= 0; --j) {
			modulo pw = factinv[i].binpow(C);
			for (int k = C; k <= D && k * i <= j; ++k) {
				dp[j] += dp[j - k * i] * pw * factinv[k];
				pw *= factinv[i];
			}
		}
	}
	cout << dp[N].get() << endl;
	return 0;
}