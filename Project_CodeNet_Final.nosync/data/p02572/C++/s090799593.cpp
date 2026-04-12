#pragma GCC diagnostic ignored "-Wunused-variable" 
#include <bits/stdc++.h>
using namespace std;

#define BOOST
#ifdef BOOST
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace boost;
using ml = multiprecision::cpp_int;
using md = multiprecision::cpp_dec_float_100;
#endif

/***** type *****/
using ll = long long;
using ld = long double;
using pll = pair<long long, long long>;
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
template <class T> using vvvt = vector<vector<vector<T>>>;
/***** define *****/
#define all(c) (c).begin(), (c).end()            // begin to end
#define coutld cout << fixed << setprecision(10) // cout double
#define output(x) do { cout << x << endl; exit(0); } while(0)
#define rep(i, b, e) for (ll i = b; i < e; i++)  // repeat
#define repr(i, b, e) for (ll i = b; e < i; i--) // repeat reverse
#define fori(i, ...) if (ll i = -1) for(__VA_ARGS__) if (i++, 1)
#define each(i, e, c) fori (i, auto&& e: c)      // for each
/***** const value *****/
#define llong_max 9223372036854775807            // 9 * 10^18
#define ldbl_max 1.79769e+308                    // 1.7 * 10^308
#define pi 3.1415926535897932                    // 3.14 ...
/***** lambda *****/
auto Ceil = [] // if (a % b != 0) return a / b + 1;
(auto x) { return (ll)ceil(x); };
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto CtoL = [] // char to number
(auto c) { return (ll)c - (ll)'0'; };
auto LtoC = [] // number to char
(auto n) { return (char)('0' + n); };
auto Pow = [] // long long pow
(auto a, auto b) { return (ll)pow(a, b); };
auto Pow2 = [] // long long pow2
(auto n) { return (1LL << n); };
auto Pow10 = [] // long long pow10
(auto n) { return (ll)pow(10, n); };
auto Size = []  // long long collection size
(auto& c) { return (ll)(c).size(); };
auto Sum = [] // long long accumulate
(auto b, auto e) { return accumulate(b, e, 0LL); };

/***** operator *****/
template <class T, class S> pair<T, S> operator + (pair<T, S> l, pair<T, S> r)
{	// pair<T, S> + pair<T, S>
	return { l.first + r.first, l.second + r.second };
}
template <class T, class S> pair<T, S> operator - (pair<T, S> l, pair<T, S> r)
{	// pair<T, S> - pair<T, S>
	return { l.first - r.first, l.second - r.second };
}

/***** template *****/
template <class T> void MakeVVT
(ll ys, ll xs, vvt<T>& v, T fill = T())
{	// vector<vector<T>> resize + fill
	v.resize(ys); rep(y, 0, ys) v[y].resize(xs, fill);
}
template <class T> void MakeVVVT
(ll zs, ll ys, ll xs, vvvt<T>& v, T fill = T())
{	// vector<vector<vector<T>>> resize + fill
	v.resize(zs); rep(z, 0, zs) MakeVVT(ys, xs, v[z], fill);
}
template <class T> void InputVVT
(ll ys, ll xs, vvt<T>& v, T fix = T())
{	// input vector<vector<T>> (T != struct) + fix
	MakeVVT(ys, xs, v, fix);
	rep(y, 0, ys) rep(x, 0, xs) { cin >> v[y][x]; v[y][x] += fix; }
}
template <class T> void InputVVVT
(ll zs, ll ys, ll xs, vvvt<T>& v, T fix = T())
{	// input vector<vector<vector<T>>> (T != struct) + fix
	v.resize(zs); rep(z, 0, zs) InputVVT(ys, xs, v[z], fix);
}

/**************************************/
/********** BEGIN OF NYA LIB **********/
/**************************************/

namespace NyaGadget {}

namespace NyaGadget
{
	/***** MOD 関数ライブラリ *****/

	struct NT_Mod
	{
		static long long Add(long long x, long long y, long long mod)
		{
			x = (x + y) % mod;
			if (x >= mod) x -= mod;
			return x;
		}

		static long long Sub(long long x, long long y, long long mod)
		{
			x = (x - y) % mod;
			if (x < 0) x += mod;
			return x;
		}

		static long long Mul(long long x, long long y, long long mod)
		{
			x = (unsigned long long) x * y % mod;
			return x;
		}

		static long long Div(long long x, long long y, long long mod)
		{
			x = x * Inv(y, mod) % mod;
			return x;
		}

		static long long Pow(long long x, long long n, long long mod)
		{
			long long res = 1;
			if (0 < n)
			{
				res = Pow(x, n / 2, mod);
				res = Mul(res, res, mod);
				if (n % 2 != 0) res = Mul(res, x, mod);
			}
			return res;
		}

		static long long Inv(long long a, long long mod)
		{
			long long b = mod, u = 1, v = 0;
			while (b)
			{
				long long t = a / b;
				a -= t * b; std::swap(a, b);
				u -= t * v; std::swap(u, v);
			}
			u %= mod;
			return (u < 0) ? u + mod : u;
		}
	};

	/***** MOD 型ライブラリ *****/

	template<long long mod> struct NT_ModLL
	{	// 非型テンプレートパラメータ
		long long x;

		// コンストラクタ
		NT_ModLL() { x = 0; }
		NT_ModLL(long long x_)
		{
			x = x_ % mod + mod;
			if (x >= mod) x -= mod;
		}

		// 符号
		NT_ModLL operator + () const { return x; }
		NT_ModLL operator - () const { return (-x < 0) ? mod - x : -x; }

		// 加減乗除演算子
		NT_ModLL& operator += (NT_ModLL r)
		{
			if ((x += r.x) >= mod) x -= mod;
			return *this;
		}
		NT_ModLL& operator -= (NT_ModLL r)
		{
			if ((x -= r.x) < 0) x += mod;
			return *this;
		}
		NT_ModLL& operator *= (NT_ModLL r)
		{
			x = (unsigned long long) x * r.x % mod;
			return *this;
		}
		NT_ModLL& operator /= (NT_ModLL r)
		{
			x = x * Inv(r.x, mod) % mod;
			return *this;
		}

		NT_ModLL operator + (NT_ModLL r) const { return NT_ModLL(*this) += r; }
		NT_ModLL operator - (NT_ModLL r) const { return NT_ModLL(*this) -= r; }
		NT_ModLL operator * (NT_ModLL r) const { return NT_ModLL(*this) *= r; }
		NT_ModLL operator / (NT_ModLL r) const { return NT_ModLL(*this) /= r; }

		// 逆元 x^{-1} (主に除算演算子で使用)
		long long Inv(long long a, long long m)
		{
			long long b = m, u = 1, v = 0;
			while (b)
			{
				long long t = a / b;
				a -= t * b; swap(a, b);
				u -= t * v; swap(u, v);
			}
			u %= m;
			return (u < 0) ? u + m : u;
		}

		// 比較演算子
		bool operator == (NT_ModLL& r) const { return x == r.x; }
		bool operator != (NT_ModLL& r) const { return x != r.x; }
		bool operator <  (NT_ModLL& r) const { return x < r.x; }
		bool operator <= (NT_ModLL& r) const { return x <= r.x; }
		bool operator >  (NT_ModLL& r) const { return x > r.x; }
		bool operator >= (NT_ModLL& r) const { return x >= r.x; }
		// 入出力演算子
		friend ostream& operator << (ostream& s, NT_ModLL<mod> a) { s << a.x; return s; }
		friend istream& operator >> (istream& s, NT_ModLL<mod>& a) { s >> a.x; return s; }

		NT_ModLL Pow(long long x, long long n)
		{
			NT_ModLL res = 1;
			if (0 < n)
			{
				res = Pow(x, n / 2);
				res = res * res;
				if (n % 2 != 0) res *= x;
			}
			return res;
		}
	};
}

/**************************************/
/*********** END OF NYA LIB ***********/
/**************************************/

using namespace NyaGadget;
using mll = NT_ModLL< 1000000007 >;
//using mll = ModLL< 998244353 >;

int main(void)
{
	ll N; cin >> N;
	vt<mll> A(N); each(i, e, A) cin >> e;

	mll ans = 0;
	mll sum = 0;
	each(i, e, A) sum += e;
	each(i, e, A) ans += e * (sum - e);
	cout << ans / 2;
	return 0;
}
