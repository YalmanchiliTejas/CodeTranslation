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
#define output(x) do{cout<<x<<endl;exit(0);}while(0)
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
	/***** 最長減少部分列ライブラリ *****/

	template <class T> struct ResultLDS
	{
		std::vector<T> dsub;              // 最長減少部分列
		std::vector<std::vector<T>> isub; // 分解個数最小の増加部分列集合
		void Clear(void) { dsub.clear(); isub.clear(); }
	};

	template <class T> struct DS_NyaaLDS
	{	// Longest Decreasing Subsequence
		ResultLDS<T> res;

		/**
		@brief 最長減少部分列を返す関数
		@param v 入力数列
		@param eq false=狭義減少部分列, true=広義減少部分列
		@note
		計算量O(NlogN)で最長減少部分列(LDS)が得られる。
		内部的には配列vを分解個数が最小になるよう増加部分列集合に分解している。
		よって、副産物として分解個数最小の増加部分列集合が得られる。
		分解個数最小であり、最長増加部分列でないことに注意。
		第三引数についてfalseにすると「狭義減少部分列」「分解個数最小の広義増加部分列集合」
		trueにすると「広義減少部分列」「分解個数最小の狭義増加部分列集合」が得られる。
		**/
		decltype(res)& Run(const std::vector<T>& v, bool eq = false)
		{
			res.Clear();
			std::vector<T> test(v.size() + 1, (T)LLONG_MIN);
			if (eq)
			{	// 同値を含める、つまり広義減少部分列を得る
				for (auto&& e : v)
				{
					auto it = --lower_bound(test.begin(), test.end(), e);
					if ((long long)res.isub.size() <= (long long)v.size() - std::distance(test.begin(), it))
						res.isub.resize(res.isub.size() + 1);
					res.isub[(long long)v.size() - std::distance(test.begin(), it)].push_back(e);
					*it = e;
				}
			}
			else
			{	// 同値を含めない、つまり狭義減少部分列を得る
				for (auto&& e : v)
				{
					auto it = --upper_bound(test.begin(), test.end(), e);
					if ((long long)res.isub.size() <= (long long)v.size() - std::distance(test.begin(), it))
						res.isub.resize(res.isub.size() + 1);
					res.isub[(long long)v.size() - std::distance(test.begin(), it)].push_back(e);
					*it = e;
				}
			}
			for (auto&& e : res.isub) res.dsub.push_back(e.front());
			return res;
		}
	};
}

/**************************************/
/*********** END OF NYA LIB ***********/
/**************************************/

using namespace NyaGadget;
//using mll = NT_ModLL< 1000000007 >;
//using mll = ModLL< 998244353 >;

int main(void)
{
	ll N; cin >> N;
	vt<ll> A(N); each(i, e, A) cin >> e;

	DS_NyaaLDS<ll> lds;
	auto res = lds.Run(A, true);
	cout << Size(res.isub) << endl;	
	return 0;
}
