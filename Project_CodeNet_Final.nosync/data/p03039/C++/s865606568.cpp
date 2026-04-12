#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr ll mod = static_cast<ll>(1e9 + 7);

template<long long Mod, int Max>
class Comb
{
public:
	Comb() :fac(Max), finv(Max)
	{
		std::vector<long long> inv(Max);

		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for (int i = 2; i < Max; ++i)
		{
			fac[i] = fac[i - 1] * i % Mod;
			inv[i] = Mod - inv[Mod % i] * (Mod / i) % Mod;
			finv[i] = finv[i - 1] * inv[i] % Mod;
		}
	}

	constexpr long long C(int n, int k) {
		if (n < k) return 0;
		if (n < 0 || k < 0) return 0;
		return fac[n] * (finv[k] * finv[n - k] % Mod) % Mod;
	}

private:
	std::vector<long long> fac;
	std::vector<long long> finv;
};

int n, m;
int k;
Comb<mod, 200005> com;
long long solve(int rows, int columns) {
	ll ans = 0;

	for (int i = 1; i < columns; ++i) {
		ans = (ans + i * static_cast<ll>(rows) * (static_cast<ll>(columns) - i) % mod * rows % mod) % mod;
	}

	ans = ans * com.C(n * m - 2, k - 2) % mod;

	return ans;
}

int main() {
	std::cin >> n >> m >> k;

	auto x = solve(n, m);
	auto y = solve(m, n);

	std::cout << (x + y) % mod << std::endl;

	return 0;
}
