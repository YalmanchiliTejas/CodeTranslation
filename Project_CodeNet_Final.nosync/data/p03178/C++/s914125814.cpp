#pragma warning (disable:4996)
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace std;

/***** type *****/
using ll = long long;
using ld = long double;
using ml = boost::multiprecision::cpp_int;
using md = boost::multiprecision::cpp_dec_float_100;
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
template <class T> using vvvt = vector<vector<vector<T>>>;
template <class T> using uset = unordered_set<T>;
template <class T1, class T2> using umap = unordered_map<T1, T2>;

/***** define *****/
#define all(c) (c).begin(), (c).end()            // begin to end
#define coutd cout << fixed << setprecision(10)  // cout double
#define rep(i, b, e) for (ll i = b; i < e; i++)  // repeat
#define repr(i, b, e) for (ll i = b; e < i; i--) // repeat reverse
#define pair NyaaPair                            // nyaa pair
#define pll  NyaaPair<ll,ll>                     // nyaa pair ll
#define first f                                  // pair::first
#define second s                                 // pair::second
/***** const value *****/
#define llong_max 9223372036854775807            // 9 * 10^18
#define ldbl_max 1.79769e+308                    // 1.7 * 10^308
#define pi 3.1415926535897932                    // 3.14 ...
#define loop_end 9223372036854775806             // LLONG_MAX-1
/***** for each macro *****/
#define fori(i, ...) if(ll i = -1) for(__VA_ARGS__) if(i++, true)
#define each(i, e, c) fori(i, auto& e: c)
#define forir(i, v, ...) if(ll i=(ll)v.size())for(__VA_ARGS__)if(i--,true)
#define eachr(i, e, c) forir(i, auto e = c.rbegin(); e != c.rend(); ++e)

/***** lambda *****/
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto CtoL = [] // char to number
(auto c) { return (ll)c - '0'; };
auto CeilD = [] // long double ceiling div
(auto a, auto b) { return (ll)ceil((ld)a / (ld)b); };
auto Fix = [] // fix value
(auto b, auto e, auto fix)
{ for (auto it = b; it != e; ++it) *it += fix; };
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
template <class T> void InputVT
(ll xs, vt<T>& v, T fix = T())
{	// input vector<T> (T != struct) + fix
	v.resize(xs); rep(i, 0, xs) { cin >> v[i]; v[i] += fix; }
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
template <class T1, class T2> struct NyaaPair
{	// nyaa pair template
	T1 f; T2 s;
};
template <class T1, class T2> bool
operator < (const NyaaPair<T1, T2>& l, const NyaaPair<T1, T2>& r)
{	// nyaa pair template operator <
	return (l.f != r.f) ? l.f < r.f : l.s < r.s;
}
template <class T1, class T2> bool
operator > (const NyaaPair<T1, T2>& l, const NyaaPair<T1, T2>& r)
{	// nyaa pair template operator >
	return (l.f != r.f) ? l.f > r.f : l.s > r.s;
}

/**************************************/
/********** BEGIN OF NYA LIB **********/
/**************************************/

namespace NyaGadget {}

namespace NyaGadget
{
	/*** MOD ライブラリ ***/

	template<long long mod> struct ModLL
	{	// 非型テンプレートパラメータ
		long long x;

		// コンストラクタ
		ModLL() { x = 0; }
		ModLL(long long x_)
		{
			x = x_ % mod + mod;
			if (x >= mod)
				x -= mod;
		}

		// 符号
		ModLL operator + () const { return x; }
		ModLL operator - () const { return (-x < 0) ? mod - x : -x; }

		// 加減乗除演算子
		ModLL& operator += (ModLL r)
		{
			if ((x += r.x) >= mod)
				x -= mod;
			return *this;
		}
		ModLL& operator -= (ModLL r)
		{
			if ((x -= r.x) < 0)
				x += mod;
			return *this;
		}
		ModLL& operator *= (ModLL r)
		{
			x = (unsigned long long) x * r.x % mod;
			return *this;
		}
		ModLL& operator /= (ModLL r)
		{
			x = x * Inv(r.x, mod) % mod;
			return *this;
		}

		ModLL operator + (ModLL r) const { return ModLL(*this) += r; }
		ModLL operator - (ModLL r) const { return ModLL(*this) -= r; }
		ModLL operator * (ModLL r) const { return ModLL(*this) *= r; }
		ModLL operator / (ModLL r) const { return ModLL(*this) /= r; }

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
		bool operator == (ModLL& r) const { return x == r.x; }
		bool operator != (ModLL& r) const { return x != r.x; }
		bool operator <  (ModLL& r) const { return x < r.x; }
		bool operator <= (ModLL& r) const { return x <= r.x; }
		bool operator >  (ModLL& r) const { return x > r.x; }
		bool operator >= (ModLL& r) const { return x >= r.x; }

		// 入出力演算子
		friend ostream& operator << (ostream& s, ModLL<mod> a)
		{
			s << a.x;
			return s;
		}
		friend istream& operator >> (istream& s, ModLL<mod>& a)
		{
			s >> a.x;
			return s;
		}

		ModLL Pow(long long x, long long n)
		{
			ModLL res = 1;
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
using mll = ModLL< 1000000007 >;
//using mll = ModLL< 998244353 >;

int main(void)
{
	string K; cin >> K;
	ll D; cin >> D;

	const ll stEQ = 0;
	const ll stLT = 1;

	vvvt<mll> dp; MakeVVVT(Size(K), D, 2, dp);
	rep(j, 0, 10)
	{
		if      (j <  CtoL(K[0])) dp[0][j % D][stLT] += 1;
		else if (j == CtoL(K[0])) dp[0][j % D][stEQ] += 1;
	}
	rep(i, 1, Size(K)) rep(j, 0, 10) rep(k, 0, D)
	{
		ll next = (j + k) % D;
		if (j < CtoL(K[i]))
		{
			dp[i][next][stLT] += dp[i - 1][k][stEQ];
			dp[i][next][stLT] += dp[i - 1][k][stLT];
		}
		else if (j == CtoL(K[i]))
		{
			dp[i][next][stEQ] += dp[i - 1][k][stEQ];
			dp[i][next][stLT] += dp[i - 1][k][stLT];
		}
		else
		{
			dp[i][next][stLT] += dp[i - 1][k][stLT];
		}
	}

	// 0 は除く
	cout << dp[Size(K) - 1][0][stEQ] + dp[Size(K) - 1][0][stLT] - 1;
	return 0;
}
