#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
#define incII(i, l, r) for(LL i = (l)    ; i <= (r); i++)
#define incIX(i, l, r) for(LL i = (l)    ; i <  (r); i++)
#define incXI(i, l, r) for(LL i = (l) + 1; i <= (r); i++)
#define incXX(i, l, r) for(LL i = (l) + 1; i <  (r); i++)
#define decII(i, l, r) for(LL i = (r)    ; i >= (l); i--)
#define decIX(i, l, r) for(LL i = (r) - 1; i >= (l); i--)
#define decXI(i, l, r) for(LL i = (r)    ; i >  (l); i--)
#define decXX(i, l, r) for(LL i = (r) - 1; i >  (l); i--)
#define inc(i, n)  incIX(i, 0, n)
#define dec(i, n)  decIX(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define dec1(i, n) decII(i, 1, n)
auto inII = [](auto x, auto l, auto r) { return (l <= x && x <= r); };
auto inIX = [](auto x, auto l, auto r) { return (l <= x && x <  r); };
auto inXI = [](auto x, auto l, auto r) { return (l <  x && x <= r); };
auto inXX = [](auto x, auto l, auto r) { return (l <  x && x <  r); };
auto setmin   = [](auto & a, auto b) { return (b <  a ? a = b, true : false); };
auto setmax   = [](auto & a, auto b) { return (b >  a ? a = b, true : false); };
auto setmineq = [](auto & a, auto b) { return (b <= a ? a = b, true : false); };
auto setmaxeq = [](auto & a, auto b) { return (b >= a ? a = b, true : false); };
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define FI first
#define SE second
#define FR front()
#define BA back()
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define RV(c) reverse(ALL(c))
#define SC static_cast
#define SI(c) SC<int>(c.size())
#define SL(c) SC<LL >(c.size())
#define RF(e, c) for(auto & e: c)
#define SF(c, ...) for(auto & [__VA_ARGS__]: c)
#define until(e) while(! (e))
#define if_not(e) if(! (e))
#define ef else if
#define UR assert(false)
auto * IS = & cin;
auto * OS = & cout;
array<string, 3> SEQ = { "", " ", "" };
// input
template<typename T> T in() { T a; (* IS) >> a; return a; }
// input: tuple
template<typename U, int I> void tin_([[maybe_unused]] U & t) { }
template<typename U, int I, typename A, typename ... B> void tin_(U & t) { (* IS) >> get<I>(t); tin_<U, I + 1, B ...>(t); }
template<typename ... T> auto tin() { tuple<T ...> t; tin_<tuple<T ...>, 0, T ...>(t); return t; }
// input: array
template<typename T, int N> auto ain() { array<T, N> a; inc(i, N) { (* IS) >> a[i]; } return a; }
// input: multi-dimensional vector
template<typename T> T vin() { T v; (* IS) >> v; return v; }
template<typename T, typename N, typename ... M> auto vin(N n, M ... m) {
	vector<decltype(vin<T, M ...>(m ...))> v(n); inc(i, n) { v[i] = vin<T, M ...>(m ...); } return v;
}
// input: multi-column (tuple<vector>)
template<typename U, int I> void colin_([[maybe_unused]] U & t) { }
template<typename U, int I, typename A, typename ... B> void colin_(U & t) {
	get<I>(t).PB(in<A>()); colin_<U, I + 1, B ...>(t);
}
template<typename ... T> auto colin(int n) {
	tuple<vector<T> ...> t; inc(i, n) { colin_<tuple<vector<T> ...>, 0, T ...>(t); } return t;
}
// output
void out_([[maybe_unused]] string s) { }
template<typename A> void out_([[maybe_unused]] string s, A && a) { (* OS) << a; }
template<typename A, typename ... B> void out_(string s, A && a, B && ... b) { (* OS) << a << s; out_(s, b ...); }
auto outF = [](auto x, auto y, auto z, auto ... a) { (* OS) << x; out_(y, a ...); (* OS) << z << flush; };
auto out  = [](auto ... a) { outF("", " " , "\n", a ...); };
auto outS = [](auto ... a) { outF("", " " , " " , a ...); };
auto outL = [](auto ... a) { outF("", "\n", "\n", a ...); };
auto outN = [](auto ... a) { outF("", ""  , ""  , a ...); };
// output: multi-dimensional vector
template<typename T> ostream & operator<<(ostream & os, vector<T> const & v) {
	os << SEQ[0]; inc(i, SI(v)) { os << (i == 0 ? "" : SEQ[1]) << v[i]; } return (os << SEQ[2]);
}
template<typename T> void vout_(T && v) { (* OS) << v; }
template<typename T, typename A, typename ... B> void vout_(T && v, A a, B ... b) {
	inc(i, SI(v)) { (* OS) << (i == 0 ? "" : a); vout_(v[i], b ...); }
}
template<typename T, typename A, typename ... B> void vout (T && v, A a, B ... b) { vout_(v, a, b ...); (* OS) << a << flush; }
template<typename T, typename A, typename ... B> void voutN(T && v, A a, B ... b) { vout_(v, a, b ...); (* OS)      << flush; }

// ---- ----

class Loop {
private:
	LL n, s; // n = SI(v), v[n] == v[s]
public:
	Loop(LL nn, LL ss) : n(nn), s(ss) { assert(inIX(s, 0, n)); }
	LL index(LL i) { assert(i >= 0); return (i < s ? i : s + (i - s) % (n - s)); }
	LL count(LL N, LL i) { // #{ index(k) == i | k in [0, N) }
		assert(inIX(i, 0, n));
		if(i < s) { return (i < N ? 1 : 0); }
		i -= s;
		N -= s;
		LL L = n - s;
		return N / L + (i < N % L ? 1 : 0);
	}
};

int main() {
	auto [n, x, m] = ain<LL, 3>();
	
	vector<LL> f(m, -1), v;
	int c = 0;
	while(f[x] == -1) {
		f[x] = c++;
		v.PB(x);
		x *= x;
		x %= m;
	}
	Loop loop(SI(v), f[x]);
	
	LL ans = 0;
	inc(i, SI(v)) { ans += v[i] * loop.count(n, i); }
	out(ans);
}
