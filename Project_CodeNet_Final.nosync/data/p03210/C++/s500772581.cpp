#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<functional>
#include<map>
#include<cstdlib>
#include<complex>
#include<numeric>
#include<set>
#include<deque>

using namespace std;
using Int = long long;
Int INF = 1LL << 60;
const Int MOD = 1000000000 + 7;

template<int Modulo = MOD> struct Mint {
	Int val;
	constexpr Mint(Int v = 0) noexcept : val(v% Modulo) {
		if (val < 0) v += Modulo;
	}
	constexpr int getmod() { return Modulo; }
	constexpr Mint operator - () const noexcept { return val ? Modulo - val : 0; }
	constexpr Mint operator + (const Mint& r) const noexcept { return Mint(*this) += r; }
	constexpr Mint operator - (const Mint& r) const noexcept { return Mint(*this) -= r; }
	constexpr Mint operator * (const Mint& r) const noexcept { return Mint(*this) *= r; }
	constexpr Mint operator / (const Mint& r) const noexcept { return Mint(*this) /= r; }
	constexpr Mint& operator += (const Mint& r) noexcept {
		val += r.val;
		if (val >= Modulo) val -= Modulo;
		return *this;
	}
	constexpr Mint& operator -= (const Mint& r) noexcept {
		val -= r.val;
		if (val < 0) val += Modulo;
		return *this;
	}
	constexpr Mint& operator *= (const Mint& r) noexcept {
		val = val * r.val % Modulo;
		return *this;
	}
	constexpr Mint& operator /= (const Mint& r) noexcept {
		Int a = r.val, b = Modulo, u = 1, v = 0;
		while (b) {
			Int t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		val = val * u % Modulo;
		if (val < 0) val += Modulo;
		return *this;
	}
	constexpr bool operator == (const Mint& r) const noexcept {
		return this->val == r.val;
	}
	constexpr bool operator != (const Mint& r) const noexcept {
		return this->val != r.val;
	}
	friend ostream& operator << (ostream& os, const Mint<Modulo>& x) noexcept {
		return os << x.val;
	}
	friend istream& operator >> (istream& is, Mint<Modulo>& x) noexcept {
		Int tmp; is >> tmp;
		x = Mint<Modulo>(tmp);
		return is;
	}
	friend constexpr Mint<Modulo> modpow(const Mint<Modulo>& a, Int n) noexcept {
		Mint res(1), tmp = a;
		while (n > 0) {
			if (n & 1) res *= tmp;
			tmp *= tmp;
			n >>= 1;
		}
		return res;
	}
};

using mint = Mint<>;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int x;
	cin >> x;

	if (x == 3)printf("YES\n");
	else if (x == 5)printf("YES\n");
	else if(x == 7)printf("YES\n");
	else printf("NO\n");


}