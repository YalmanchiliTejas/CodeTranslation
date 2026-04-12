#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter" 
#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define BOOST
#ifdef BOOST
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using ml = boost::multiprecision::cpp_int;
using md = boost::multiprecision::cpp_dec_float_100;
#endif

/***** type *****/
using ll = long long;
using ld = long double;
using pll = pair<long long, long long>;
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
template <class T> using vvvt = vector<vector<vector<T>>>;
using mg = vector<vector<long long>>;
using lg = vector<vector<long long>>;
using wlg = vector<vector<pair<long long, long long>>>;
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
template <class A, class B, class C> struct triple
{	// tuple<A, B, C>
	A a = A(); B b = B(); C c = C();
};
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

/**************************************/
/*********** END OF NYA LIB ***********/
/**************************************/

using namespace NyaGadget;
//using mll = NT_ModLL< 1000000007 >;
//using mll = NT_ModLL< 998244353 >;

int main()
{
	ll N; cin >> N;
	vt<ll> A(N); each(i, e, A) cin >> e;
	vt<ll> sl = A; sort(all(sl));
	vt<ll> ls = A; sort(all(ls), greater<ll>());
	if (N == 2) output(abs(A[0] - A[1]));

	ll ans = 0;
	vt<ll> test;
	auto slit = sl.begin();
	auto lsit = ls.begin();
	if (N % 2 == 0)
	{
		while (std::distance(sl.begin(), slit) != (N - 2) / 2 || std::distance(ls.begin(), lsit) != (N - 2) / 2)
		{
			if (std::distance(sl.begin(), slit) != (N - 2) / 2) test.push_back(*slit), slit++;
			if (std::distance(ls.begin(), lsit) != (N - 2) / 2) test.push_back(*lsit), lsit++;
		}
		ll nyaa = 0;
		rep(i, 1, Size(test)) nyaa += abs(test[i] - test[i - 1]);
		ans = max({ ans, nyaa + abs(test.front() - *slit) + abs(test.back() - *lsit), nyaa + abs(test.front() - *lsit) + abs(test.back() - *slit) }); 
		test.clear();
		slit = sl.begin();
		lsit = ls.begin();
		while (std::distance(sl.begin(), slit) != (N - 2) / 2 || std::distance(ls.begin(), lsit) != (N - 2) / 2)
		{
			if (std::distance(ls.begin(), lsit) != (N - 2) / 2) test.push_back(*lsit), lsit++;
			if (std::distance(sl.begin(), slit) != (N - 2) / 2) test.push_back(*slit), slit++;
		}
		nyaa = 0;
		rep(i, 1, Size(test)) nyaa += abs(test[i] - test[i - 1]);
		ans = max({ ans, nyaa + abs(test.front() - *slit) + abs(test.back() - *lsit), nyaa + abs(test.front() - *lsit) + abs(test.back() - *slit) });
	}
	else
	{
		while (std::distance(sl.begin(), slit) != (N - 2) / 2 || std::distance(ls.begin(), lsit) != (N - 2) / 2 + 1)
		{
			if (std::distance(ls.begin(), lsit) != (N - 2) / 2 + 1) test.push_back(*lsit), lsit++;
			if (std::distance(sl.begin(), slit) != (N - 2) / 2) test.push_back(*slit), slit++;
		}
		ll nyaa = 0;
		rep(i, 1, Size(test)) nyaa += abs(test[i] - test[i - 1]);
		ans = max({ ans, nyaa + abs(test.front() - *slit) + abs(test.back() - *lsit), nyaa + abs(test.front() - *lsit) + abs(test.back() - *slit) });
		test.clear();
		slit = sl.begin();
		lsit = ls.begin();
		while (std::distance(sl.begin(), slit) != (N - 2) / 2 + 1 || std::distance(ls.begin(), lsit) != (N - 2) / 2)
		{
			if (std::distance(sl.begin(), slit) != (N - 2) / 2 + 1) test.push_back(*slit), slit++;
			if (std::distance(ls.begin(), lsit) != (N - 2) / 2) test.push_back(*lsit), lsit++;
		}
		nyaa = 0;
		rep(i, 1, Size(test)) nyaa += abs(test[i] - test[i - 1]);
		ans = max({ ans, nyaa + abs(test.front() - *slit) + abs(test.back() - *lsit), nyaa + abs(test.front() - *lsit) + abs(test.back() - *slit) });

	}
	cout << ans << endl;
	return 0;
}