#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
#define incID(i, l, r) for(int i = (l)    ; i <  (r); ++i)
#define decID(i, l, r) for(int i = (r) - 1; i >= (l); --i)
#define incII(i, l, r) for(int i = (l)    ; i <= (r); ++i)
#define decII(i, l, r) for(int i = (r)    ; i >= (l); --i)
#define inc(i, n)  incID(i, 0, n)
#define dec(i, n)  decID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define dec1(i, n) decII(i, 1, n)
#define inID(v, l, r) ((l) <= (v) && (v) <  (r))
#define inII(v, l, r) ((l) <= (v) && (v) <= (r))
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define FR front()
#define BA back()
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
auto setmin   = [](auto & a, auto b) { return (b <  a ? a = b, true : false); };
auto setmax   = [](auto & a, auto b) { return (b >  a ? a = b, true : false); };
auto setmineq = [](auto & a, auto b) { return (b <= a ? a = b, true : false); };
auto setmaxeq = [](auto & a, auto b) { return (b >= a ? a = b, true : false); };
#define SI(v) static_cast<int>(v.size())
#define RF(e, v) for(auto & e: v)
#define until(e) while(! (e))
#define if_not(e) if(! (e))
#define ef else if
#define UR assert(false)
#define IN(T, ...) T __VA_ARGS__; IN_(__VA_ARGS__);
void IN_() { };
template<typename T, typename ... U> void IN_(T & a, U & ... b) { cin >> a; IN_(b ...); };
template<typename T> void OUT(T && a) { cout << a << endl; }
template<typename T, typename ... U> void OUT(T && a, U && ... b) { cout << a << " "; OUT(b ...); }

// ---- ----

template<typename T> istream & operator>>(istream & s, vector<T> & v) { RF(e, v) { s >> e; } return s; }
template<typename T> ostream & operator<<(ostream & s, vector<T> const & v) {
	inc(i, SI(v)) { s << (i == 0 ? "" : " ") << v[i]; }
	return s;
}

template<typename T> T MV(T v) { return v; }
template<typename T, typename ... U> auto MV(T v, int a, U ... b) { return vector<decltype(MV(v, b ...))>(a, MV(v, b ...)); }

int main() {
	IN(int, n);
	vector<LL> a(n);
	cin >> a;
	LL INF = 1e18;
	auto dp = MV<LL>(-INF, n + 1, 3 + 1);
	dp[0][0] = 0;
	inc(i, n) {
		incII(j, 0, 1 + n % 2) {
			bool f ((i + j) % 2 != 0);
			if(f) {
				setmax(dp[i + 1][j], dp[i][j]);
			} else {
				setmax(dp[i + 1][j], dp[i][j] + a[i]);
				setmax(dp[i + 1][j + 1], dp[i][j]);
			}
		}
	}
	LL ans = -INF;
	incII(j, 0, 1 + n % 2) {
		setmax(ans, dp[n][j]);
	}
	OUT(ans);
}
