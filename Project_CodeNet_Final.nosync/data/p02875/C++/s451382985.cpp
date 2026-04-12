#ifndef CLASS_MODINT
#define CLASS_MODINT

#include <cstdint>

template <std::uint32_t mod>
class modint {
private:
	std::uint32_t n;
public:
	modint() : n(0) {};
	modint(std::int64_t n_) : n((n_ >= 0 ? n_ : mod - (-n_) % mod) % mod) {};
	static constexpr std::uint32_t get_mod() { return mod; }
	std::uint32_t get() const { return n; }
	bool operator==(const modint& m) const { return n == m.n; }
	bool operator!=(const modint& m) const { return n != m.n; }
	modint& operator+=(const modint& m) { n += m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator-=(const modint& m) { n += mod - m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator*=(const modint& m) { n = std::uint64_t(n) * m.n % mod; return *this; }
	modint operator+(const modint& m) const { return modint(*this) += m; }
	modint operator-(const modint& m) const { return modint(*this) -= m; }
	modint operator*(const modint& m) const { return modint(*this) *= m; }
	modint inv() const { return (*this).pow(mod - 2); }
	modint pow(std::uint64_t b) const {
		modint ans = 1, m = modint(*this);
		while (b) {
			if (b & 1) ans *= m;
			m *= m;
			b >>= 1;
		}
		return ans;
	}
};

#endif // CLASS_MODINT

#include <vector>
#include <iostream>
#include <functional>
using namespace std;
using mint = modint<998244353>;
int main() {
	int N;
	cin >> N;
	vector<mint> fact(N + 1), inv(N + 1), factinv(N + 1);
	fact[0] = 1, inv[1] = 1, factinv[0] = 1;
	for (int i = 1; i <= N; ++i) fact[i] = fact[i - 1] * i;
	for (int i = 2; i <= N; ++i) inv[i] = inv[mint::get_mod() % i] * mint(-int(mint::get_mod() / i));
	for (int i = 1; i <= N; ++i) factinv[i] = factinv[i - 1] * inv[i];
	function<mint(int, int)> comb = [&](int x, int y) {
		if (x < y || y < 0) return mint(0);
		return fact[x] * factinv[y] * factinv[x - y];
	};
	mint ans = 0, sum = mint(2).pow(N / 2);
	for (int i = N / 2; i <= N; ++i) {
		mint mul = comb(N, i);
		ans += mul * sum;
		sum *= 2;
		sum -= comb(i, N / 2);
	}
	cout << ans.get() << endl;
	return 0;
}