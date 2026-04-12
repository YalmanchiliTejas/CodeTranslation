#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/*
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;*/
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
typedef long long ll;
typedef pair<ll, ll> Pa;

/*
template <std::int_fast64_t Modulus> class modint {
	using u64 = std::int_fast64_t;
public:
	u64 a;
	constexpr modint(const u64 x = 0) noexcept : a(x% Modulus) {}
	constexpr u64& value() noexcept { return a; }
	constexpr const u64& value() const noexcept { return a; }
	constexpr modint operator+(const modint rhs) const noexcept {
		return modint(*this) += rhs;
	}
	constexpr modint operator-(const modint rhs) const noexcept {
		return modint(*this) -= rhs;
	}
	constexpr modint operator*(const modint rhs) const noexcept {
		return modint(*this) *= rhs;
	}
	constexpr modint operator/(const modint rhs) const noexcept {
		return modint(*this) /= rhs;
	}
	constexpr modint& operator+=(const modint rhs) noexcept {
		a += rhs.a;
		if (a >= Modulus) {
			a -= Modulus;
		}
		return *this;
	}
	constexpr modint& operator-=(const modint rhs) noexcept {
		if (a < rhs.a) {
			a += Modulus;
		}
		a -= rhs.a;
		return *this;
	}
	constexpr modint& operator*=(const modint rhs) noexcept {
		a = a * rhs.a % Modulus;
		return *this;
	}
	constexpr modint& operator/=(modint rhs) noexcept {
		u64 exp = Modulus - 2;
		while (exp) {
			if (exp % 2) {
				*this *= rhs;
			}
			rhs *= rhs;
			exp /= 2;
		}
		return *this;
	}
};
#pragma endregion

typedef modint<MOD> m;
m func[400001];
void funcinit(int N)
{
	func[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		func[i] = func[i - 1] * i;
	}
}
m comb(m n, m r)
{
	if (n.a <= 0 || n.a < r.a)
	{
		return 0;
	}
	return func[n.a] / (func[r.a] * func[(n - r).a]);
}*/

string s;
int main() {
	cin >> s;
	if (s != "AAA" && s != "BBB") cout << "Yes";
	else cout << "No";
}
