#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

/***** type *****/
using namespace std;
using ll = long long;
using ld = long double;
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
template <class T> using vvvt = vector<vector<vector<T>>>;
template <class T1, class T2> using umap = unordered_map<T1, T2>;
using ml = boost::multiprecision::cpp_int;

/***** define *****/
#define all(c) (c).begin(), (c).end()            // begin to end
#define rep(i, b, e) for (ll i = b; i < e; i++)  // repeat
#define repr(i, b, e) for (ll i = b; e < i; i--) // repeat reverse
#define val(itr) *(itr)                          // get value
/***** const value *****/
#define llong_max 9223372036854775807            // 9 * 10^18
#define ldbl_max 1.79769e+308                    // 1.7 * 10^308
#define mod 1000000007                           // 1e9 + 7
#define pi 3.14159265                            // 3.14 ...
/***** for each macro *****/
#define fori(i, ...) if(ll i = -1) for(__VA_ARGS__) if(i++, true)
#define each(i, e, c) fori(i, auto e = c.begin(); e != c.end(); ++e)
#define forir(i, v, ...) if(ll i = Size(v)) for(__VA_ARGS__) if(i--, true)
#define eachr(i, e, c) forir(i, auto e = c.rbegin(); e != c.rend(); ++e)

/***** lambda *****/
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto CtoN = [] // char to number
(auto c) { return (ll)(c - '0'); };
auto DivC = [] // long double div ceiling
(auto a, auto b) { return ceil((ld)a / (ld)b); };
auto Fix = [] // fix value
(auto b, auto e, auto fix)
{ for (auto it = b; it != e; ++it)* it += fix; };
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
template <class T> vvt<T> VVT
(ll ys, ll xs, T fill = T())
{	// vector<vector<T>> resize + fill
	vvt<T> v(ys);
	each(i, y, v) { val(y).resize(xs, fill); } return v;
}
template <class T> vvvt<T> VVVT
(ll zs, ll ys, ll xs, T fill = T())
{	// vector<vector<vector<T>>> resize + fill
	vvvt<T> v(zs);
	each(i, z, v) { val(z) = VVT(ys, xs, fill); } return v;
}
template <class T> vt<T> InputVT
(ll size, T fix = T())
{	// input vector<T> (T != struct) + fix
	vt<T> v(size);
	each(i, e, v) { cin >> val(e); val(e) += fix; } return v;
}
template <class T> vvt<T> InputVVT
(ll ys, ll xs, T fix = T())
{	// input vector<vector<T>> (T != struct) + fix
	vvt<T> v(ys); each(i, y, v) val(y).resize(xs);
	each(i, y, v) each(j, x, val(y)) { cin >> val(x); val(x) += fix; } return v;
}
template <class T> vvvt<T> InputVVVT
(ll zs, ll ys, ll xs, T fix = T())
{	// input vector<vector<vector<T>>> (T != struct) + fix
	vvvt<T> v(zs);
	each(i, z, v) { val(z) = InputVVT<T>(ys, xs, fix); } return v;
}

namespace NyaGadget
{
	/*** MOD ライブラリ ***/

	template<ll maxv> struct ModLL
	{
		ll x;

		// コンストラクタ
		ModLL() { x = 0; }
		ModLL(ll x_)
		{
			x = x_ % maxv + maxv;
			if (x >= maxv)
				x -= maxv;
		}

		// 符号
		ModLL operator + () const { return x; }
		ModLL operator - () const { return (-x < 0) ? maxv - x : -x; }

		// 加減乗除演算子
		ModLL& operator += (ModLL r)
		{
			if ((x += r.x) >= maxv)
				x -= maxv;
			return *this;
		}
		ModLL& operator -= (ModLL r)
		{
			if ((x -= r.x) < 0)
				x += maxv;
			return *this;
		}
		ModLL& operator *= (ModLL r)
		{
			x = (unsigned long long) x * r.x % maxv;
			return *this;
		}
		ModLL& operator /= (ModLL r)
		{
			x = x * Inv(r.x, maxv) % maxv;
			return *this;
		}

		ModLL operator + (ModLL r) const { return ModLL(*this) += r; }
		ModLL operator - (ModLL r) const { return ModLL(*this) -= r; }
		ModLL operator * (ModLL r) const { return ModLL(*this) *= r; }
		ModLL operator / (ModLL r) const { return ModLL(*this) /= r; }

		// 逆元 x^{-1} (主に除算演算子で使用)
		ll Inv(ll a, ll m)
		{
			ll b = m, u = 1, v = 0;

			while (b)
			{
				ll t = a / b;
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
		friend ostream& operator << (ostream& s, ModLL<maxv> a)
		{
			s << a.x;
			return s;
		}
		friend istream& operator >> (istream& s, ModLL<maxv>& a)
		{
			s >> a.x;
			return s;
		}

		ll Pow(ll a, ll n) {
			ll res = 1;
			while (n > 0) {
				if (n & 1) res = res * a % maxv;
				a = a * a % maxv;
				n >>= 1;
			}
			return res;
		}
	};
}

namespace NyaGadget
{
	/***** 数え上げライブラリ(引数にModライブラリなどを渡すことを想定) *****/

	template< typename T > struct Counting
	{
		vector< T > fv, fvinv, inv;

		Counting(ll maxsize)
		{	// Hがn+r-1なので、vsizeをmaxsize * 2とする
			ll vsize = maxsize * 2;
			fv.resize(vsize + 1);
			fvinv.resize(vsize + 1);
			inv.resize(vsize + 1);
			fv[0] = fvinv[vsize] = inv[0] = 1;

			rep(i, 1, vsize + 1)
				fv[i] = fv[i - 1] * i;
			fvinv[vsize] /= fv[vsize];

			repr(i, vsize - 1, -1)
				fvinv[i] = fvinv[i + 1] * (i + 1);

			rep(i, 1, vsize + 1)
				inv[i] = fvinv[i] * fv[i - 1];
		}

		T Factorial(ll k) { return fv[k]; }
		T FactorialInv(ll k) { return fvinv[k]; }
		T Inv(ll k) { return inv[k]; }

		T P(ll n, ll r)
		{
			if (r < 0 || n < r)
				return 0;
			return Factorial(n) * FactorialInv(n - r);
		}

		T C(ll n, ll r)
		{
			if (r < 0 || n < r)
				return 0;
			return Factorial(n) * FactorialInv(r) * FactorialInv(n - r);
		}

		T H(ll n, ll r)
		{
			if (n < 0 || r < 0)
				return 0;
			return (r == 0) ? 1 : C(n + r - 1, r);
		}
	};
}

using namespace NyaGadget;
using mll = ModLL<1000000007>;

int main(void)
{
	ll N, M, K; cin >> N >> M >> K;

	Counting<mll> count(Pow10(6));
	
	mll xans = 0;
	rep(d, 0, M)
		xans += d * (M - d) * N * N;
	xans *= count.C(N * M - 2, K - 2);

	mll yans = 0;
	rep(d, 0, N)
		yans += d * (N - d) * M * M;
	yans *= count.C(N * M - 2, K - 2);

	cout << xans + yans;
	return 0;
}
