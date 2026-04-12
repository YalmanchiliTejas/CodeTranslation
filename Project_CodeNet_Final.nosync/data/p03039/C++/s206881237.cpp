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
using namespace std;
using mint = modint<1000000007>;
mint comb(int x, int y) {
	mint ans = 1;
	for (int i = x - y + 1; i <= x; ++i) ans *= i;
	for (int i = 1; i <= y; ++i) ans *= mint(i).inv();
	return ans;
}
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	mint XP = mint(3).inv() * (N - 1) * (N + 1) * mint(N).inv();
	mint YP = mint(3).inv() * (M - 1) * (M + 1) * mint(M).inv();
	mint ZP = (XP + YP) * mint(N * M) * mint(N * M - 1).inv();
	mint ans = comb(N * M, K) * ZP * mint(1LL * K * (K - 1) / 2);
	cout << ans.get() << endl;
	return 0;
}