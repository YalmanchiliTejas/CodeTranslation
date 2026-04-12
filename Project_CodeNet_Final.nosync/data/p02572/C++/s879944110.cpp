#include "bits/stdc++.h"
#include<random>
using namespace std; typedef unsigned long long _ulong; typedef long long int lint; typedef pair<lint, lint> plint; typedef pair<double long, double long> pld;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define FOR(i, begin, end) for(lint i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(lint i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define endk '\n'
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const lint MOD = 1e9 + 7, INF = 1e18;
lint dx[8] = { 0, -1, 1, 0, 1, -1, 1, -1 }, dy[8] = { 1, 0, 0, -1, -1, -1, 1, 1 };
typedef pair<double, lint> Pa;
typedef pair<plint, lint> tlint;
struct edge {
	lint cost;
	lint u, v;
};



template <std::int_fast64_t Modulus>
class modint
{
	using u64 = std::int_fast64_t;

public:
	u64 a;
	constexpr modint(const u64 x = 0) noexcept : a(x% Modulus) {}
	constexpr u64& value() noexcept { return a; }
	constexpr const u64& value() const noexcept { return a; }
	constexpr modint operator+(const modint rhs) const noexcept
	{
		return modint(*this) += rhs;
	}
	constexpr modint operator-(const modint rhs) const noexcept
	{
		return modint(*this) -= rhs;
	}
	constexpr modint operator*(const modint rhs) const noexcept
	{
		return modint(*this) *= rhs;
	}
	constexpr modint operator/(const modint rhs) const noexcept
	{
		return modint(*this) /= rhs;
	}
	constexpr modint& operator+=(const modint rhs) noexcept
	{
		a += rhs.a;
		if (a >= Modulus)
		{
			a -= Modulus;
		}
		return *this;
	}
	constexpr modint& operator-=(const modint rhs) noexcept
	{
		if (a < rhs.a)
		{
			a += Modulus;
		}
		a -= rhs.a;
		return *this;
	}
	constexpr modint& operator*=(const modint rhs) noexcept
	{
		a = a * rhs.a % Modulus;
		return *this;
	}
	constexpr modint& operator/=(modint rhs) noexcept
	{
		u64 exp = Modulus - 2;
		while (exp)
		{
			if (exp % 2)
			{
				*this *= rhs;
			}
			rhs *= rhs;
			exp /= 2;
		}
		return *this;
	}
};
typedef modint<MOD> ModInt;

ModInt mod_pow(ModInt x, lint n) {
	ModInt ret = 1;
	while (n > 0) {
		if (n & 1) (ret *= x);
		(x *= x);
		n >>= 1;
	}
	return ret;
}

ModInt func[200000];
void funcinit(int N)
{
	func[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		func[i] = func[i - 1] * i;
	}
}
ModInt comb(ModInt n, ModInt r)
{
	if (n.a <= 0 || n.a < r.a)
	{
		return 1;
	}
	return func[n.a] / (func[r.a] * func[(n - r).a]);
}
ModInt ans;
lint N, arr[200000];
int main() {
	cin >> N;
	ModInt sum = 0;
	REP(i, N) {
		cin >> arr[i];
		sum += arr[i];
	}
	REP(i, N) {
		sum -= arr[i];
		ans += sum * arr[i];
	}
	cout << ans.a << endk;
}
