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

using modulo = modint<1000000007>;

#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	string S; int D;
	cin >> S >> D;
	int N = S.size();
	vector<vector<modulo> > dp(N, vector<modulo>(D, modulo(0)));
	dp[0][0] = modulo(1);
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < D; ++j) {
			for (int k = 0; k < 10; ++k) {
				dp[i][(j + k) % D] += dp[i - 1][j];
			}
		}
	}
	modulo ans = 0;
	int digitsum = 0;
	for (int i = N - 1; i >= 0; --i) {
		int digit = int(S[N - i - 1] - '0');
		for (int j = 0; j < digit + (i == 0 ? 1 : 0); ++j) {
			ans += dp[i][(D - (digitsum + j) % D) % D];
		}
		digitsum += digit;
	}
	cout << (ans - modulo(1)).get() << '\n';
	return 0;
}