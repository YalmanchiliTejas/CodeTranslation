#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

/***** type *****/
using namespace std;
using ll = long long;
using ld = long double;
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
template <class T> using vvvt = vector<vector<vector<T>>>;
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
#define pi 3.14159265358979323846                // 3.14 ...
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
{ for (auto it = b; it != e; ++it)*it += fix; };
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
	each(i, y, v) each(j, x, val(y)) { cin >> val(x); val(x) += fix; }
	return v;
}
template <class T> vvvt<T> InputVVVT
(ll zs, ll ys, ll xs, T fix = T())
{	// input vector<vector<vector<T>>> (T != struct) + fix
	vvvt<T> v(zs);
	each(i, z, v) { val(z) = InputVVT<T>(ys, xs, fix); }
	return v;
}

struct Work
{
	ll day;
	ll cost;
};

auto NyaSort = [](const Work& l, const Work& r)
{	// 降順は演算子>, 昇順は演算子<, if順の優先でソートされる
	return l.day < r.day;
};

bool operator< (const Work& l, const Work& r)
{	// priority_queueを降順でソートする
	// 昇順にしたいときは不等号を「>」にする
	return l.cost < r.cost;
};

int main(void)
{
	ll N, M; cin >> N >> M;

	if (N == M) cout << "Yes";
	else cout << "No";
	
	return 0;
}
