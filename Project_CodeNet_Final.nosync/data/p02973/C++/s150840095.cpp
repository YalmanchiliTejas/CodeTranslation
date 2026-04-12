#include <bits/stdc++.h>
using namespace std;

/***** type *****/
using ll = long long;
using ld = long double;
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
template <class T> using vvvt = vector<vector<vector<T>>>;
template <class T> using uset = unordered_set<T>;
template <class T1, class T2> using umap = unordered_map<T1, T2>;

/***** define *****/
#define all(c) (c).begin(), (c).end()            // begin to end
#define coutld cout << fixed << setprecision(10) // cout long double
#define rep(i, b, e) for (ll i = b; i < e; i++)  // repeat
#define repr(i, b, e) for (ll i = b; e < i; i--) // repeat reverse
#define pair NyaaPair                            // nyaa pair
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
auto CtoN = [] // char to number
(auto c) { return (ll)(c - '0'); };
auto CeilD = [] // long double ceiling div
(auto a, auto b) { return ceil((ld)a / (ld)b); };
auto Fix = [] // fix value
(auto b, auto e, auto fix)
{ for (auto it = b; it != e; ++it) *it += fix; };
auto NtoC = [] // number to char
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
	/***** 最長減少部分列ライブラリ *****/

	template <class T> struct ResultLDS
	{
		vector<T> dsub;         // 最長減少部分列
		vector<vector<T>> isub; // 分解個数最小の増加部分列集合
	};

	/**
	@brief 最長減少部分列を返す関数
	@param v 入力数列
	@param res 出力
	@param eq false=狭義減少部分列, true=広義減少部分列
	@note
	 計算量O(NlogN)で最長減少部分列(LDS)が得られる。
	 内部的には配列vを分解個数が最小になるよう増加部分列集合に分解している。
	 よって、副産物として分解個数最小の増加部分列集合が得られる。
	 分解個数最小であり、最長増加部分列でないことに注意。
	 第三引数についてfalseにすると「狭義減少部分列」「分解個数最小の広義増加部分列集合」
	 trueにすると「広義減少部分列」「分解個数最小の狭義増加部分列集合」が得られる。
	**/
	template <class T> void DS_NyaaLDS
	(const vector<T>& v, ResultLDS<T>& res, bool eq = false)
	{	// Longest Decreasing Subsequence
		vt<ll> test(v.size() + 1, LLONG_MIN);
		if (eq)
		{	// 同値を含める、つまり広義減少部分列を得る
			for (auto& e : v)
			{
				auto it = --lower_bound(test.begin(), test.end(), e);
				if ((long long)res.isub.size() <= (long long)v.size() - distance(test.begin(), it))
					res.isub.resize(res.isub.size() + 1);
				res.isub[(long long)v.size() - distance(test.begin(), it)].push_back(e);
				*it = e;
			}
		}
		else
		{	// 同値を含めない、つまり狭義減少部分列を得る
			for (auto& e : v)
			{
				auto it = --upper_bound(test.begin(), test.end(), e);
				if ((long long)res.isub.size() <= (long long)v.size() - distance(test.begin(), it))
					res.isub.resize(res.isub.size() + 1);
				res.isub[(long long)v.size() - distance(test.begin(), it)].push_back(e);
				*it = e;
			}
		}
		for (auto& e : res.isub) res.dsub.push_back(e.front());
	}
}

/**************************************/
/*********** END OF NYA LIB ***********/
/**************************************/

using namespace NyaGadget;
//using mll = ModLL< 1000000007 >;
//using mll = ModLL< 998244353 >;

int main(void)
{
	ll N; cin >> N;
	vt<ll> A; InputVT(N, A);

	ResultLDS<ll> res;
	DS_NyaaLDS(A, res, true);
	cout << Size(res.dsub);
	return 0;
}