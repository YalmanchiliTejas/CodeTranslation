#include "bits/stdc++.h"
#include<random>
using namespace std;
typedef long long int lint;
typedef pair<lint, lint> plint;
typedef pair<double long, double long> pld;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(lint i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(lint i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }
const lint MOD = 998244353, INF = 1e16;

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

lint N, S;
lint arr[3000];
int main() {
	cin >> N >> S;
	REP(i, N) {
		cin >> arr[i];
	}
	vector<ModInt> dp(S + 1);
	ModInt ans = 0;
	REP(i, N) {
		dp[0] += 1;
		{
			vector<ModInt> dp2(S + 1);
			REP(j, S + 1) {
				dp2[j] += dp[j];
				if (j + arr[i] <= S) dp2[j + arr[i]] += dp[j];
			}
			dp = dp2;
		}
		ans += dp[S];
	}
	cout << ans.a << endl;
}
