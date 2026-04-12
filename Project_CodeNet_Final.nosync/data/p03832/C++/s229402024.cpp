#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int n, a, b, c, d;

using ll = long long;


//負数がないMOD関数
inline long long imod(long long a, long long b)
{
	return (a >= 0) ? (a % b) : (a % b + b);
}

//mint_base型用の累乗関数
template <long long MOD> class mint_base;
template <long long MOD> mint_base<MOD> m_pow(long long x, long long n);

//mod計算を自動で行う整数テンプレートクラス
template <long long MOD = 1000000007>
class mint_base
{
public:
	mint_base<MOD> operator+(const mint_base<MOD> &other)const
	{
		return mint_base<MOD>((a + other.a < MOD) ? (a + other.a) : (a + other.a - MOD));
	}
	mint_base<MOD> operator-(const mint_base<MOD> &other)const
	{
		return mint_base<MOD>((a - other.a >= 0) ? (a - other.a) : (a - other.a + MOD));
	}
	mint_base<MOD> operator*(const mint_base<MOD> &other)const
	{
		return mint_base<MOD>(imod(a * other.a, MOD));
	}
	mint_base<MOD> operator+=(const mint_base<MOD> &other)
	{
		//a = imod(a + other.a, MOD);
		(*this) = (*this) + other;
		return mint_base<MOD>(a);
	}
	mint_base<MOD> operator-=(const mint_base<MOD> &other)
	{
		//a = imod(a - other.a, MOD);
		(*this) = (*this) - other;
		return mint_base<MOD>(a);
	}
	mint_base<MOD> operator*=(const mint_base<MOD> &other)
	{
		a = imod(a * other.a, MOD);
		return mint_base<MOD>(a);
	}
	mint_base<MOD> operator+()const
	{
		return *this;
	}
	mint_base<MOD> operator-()const
	{
		return mint_base<MOD>(-a);
	}
	mint_base<MOD>& operator++()
	{
		*this += 1;
		return *this;
	}
	mint_base<MOD> operator++(int)
	{
		auto tmp = *this;
		*this += 1;
		return tmp;
	}
	mint_base<MOD>& operator--()
	{
		*this -= 1;
		return *this;
	}
	mint_base<MOD> operator--(int)
	{
		auto tmp = *this;
		*this -= 1;
		return tmp;
	}
	mint_base<MOD> operator~()const
	{
		return m_pow<MOD>(a, (long long)e_phi - 1);
	}
	mint_base<MOD>& operator=(const mint_base<MOD> &other)
	{
		a = other.a;
		return *this;
	}
	explicit operator long long()const
	{
		return a;
	}
	explicit operator int()const
	{
		return (int)a;
	}

	//無効な数値を指定された場合
	static_assert(MOD >= 2, "MOD cannot be below 2.");
	mint_base(long long a_) :a(a_)
	{
		if (a < 0 || a >= MOD)
		{
			a = imod(a_, MOD);
		}
		if (e_phi > 0)return;
		//オイラー値の導出
		e_phi = MOD;
		long long m_ = MOD;
		for (int i = 2; i * i <= m_; ++i)
		{
			if (m_ % i == 0)
			{
				e_phi = e_phi / i * (i - 1);
				for (; m_ % i == 0; m_ /= i);
			}
		}
		if (m_ != 1)e_phi = e_phi / m_ * (m_ - 1);
	}
	mint_base() :a(0) {}
private:
	static long long e_phi;
	long long a;
};

//mint_base型用の累乗関数
template<long long MOD>mint_base<MOD> m_pow(long long x, long long n)
{
	mint_base<MOD> res = 1;
	while (n > 0)
	{
		if (n & 1)res *= x;
		x *= x;
		x %= MOD;
		n >>= 1;
	}
	return res;
}


//mint_baseの階乗計算
//O(x)時間が必要のため、fact_set関数を推奨する。
template<long long MOD>mint_base<MOD> fact(mint_base<MOD> x)
{
	mint_base<MOD> res(1);
	for (long long i = 1; i <= (long long)x; ++i)
	{
		res *= i;
	}
	return res;
}

//mint_baseの階乗計算
//0からxまでの階乗をsetに出力する
template<long long MOD>void fact_set(std::vector<mint_base<MOD>> &set, mint_base<MOD> x = mint_base<MOD>(-1))
{
	set.clear();
	set.reserve((long long)(x) + 1);
	mint_base<MOD> res(1);
	set.push_back(1);
	for (long long i = 1; i <= (long long)x; ++i)
	{
		res *= i;
		set.push_back(res);
	}
}

template<long long MOD>long long mint_base<MOD>::e_phi = -1;

//mint_base型のstreamへの出力
template<long long MOD> std::ostream& operator<<(std::ostream& os, mint_base<MOD> i)
{
	os << (long long)i;
	return os;
}

//mint_base型のstreamからの入力
template<long long MOD> std::istream& operator >> (std::istream& is, mint_base<MOD>& i)
{
	long long tmp;
	is >> tmp;
	i = tmp;
	return is;
}

typedef mint_base<> mint;


vector<mint>infact;
vector<mint>revfact;

ll memo[1234][1234];
const ll MOD = 1000000007;
ll dp(int i, int j)
{
	if (i < 0)return 0;
	if (j == b + 1)
	{
		if (i != 0)return 0;
		return 1;
	}
	if (memo[i][j] >= 0)return memo[i][j];
	ll ret = dp(i, j + 1);
	for (int a = c; a <= d; ++a)
	{
		if (i < 0 || i - j * a < 0 || j < 0)continue;
		mint mult = infact[i] * revfact[i - j * a];
		//mult *= ~m_pow<1000000007>((long long)infact[j], a);
		mult *= m_pow<1000000007>((long long)revfact[j], a);
		mult *= revfact[a];
		ret += dp(i - j * a, j + 1) * (ll)mult;
		ret %= MOD;
	}
	return memo[i][j] = ret;
}

int main(void)
{
	memset(memo, 0xff, sizeof(memo));
	fact_set(infact, mint(1234));
	revfact.reserve(infact.size());
	for (auto& i: infact)
	{
		revfact.push_back(~i);
	}
	cin >> n >> a >> b >> c >> d;
	cout << dp(n, a) << endl;
	return 0;
}