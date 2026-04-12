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

#define bit(b, i) (((b) >> (i)) & 1)
#define PC __builtin_popcountll
#define BL(a) (a ? 64 - __builtin_clzll(a) : 0)

using U = long long unsigned int;

int main() {
	IN(int, n);
	vector<U> s(n), t(n), u(n), v(n);
	cin >> s >> t >> u >> v;
	
	auto ans = MV<U>(0, n, n);
	auto check = [&](int b) -> bool {
		U x;
		inc(i, n) {
			inc(j, n) {
				U B = bit(ans[i][j], b);
				if(j == 0) { x = B; }
				if(s[i] == 0) { x &= B; } else { x |= B; }
			}
			if(x != bit(u[i], b)) { return false; }
		}
		inc(j, n) {
			inc(i, n) {
				U B = bit(ans[i][j], b);
				if(i == 0) { x = B; }
				if(t[j] == 0) { x &= B; } else { x |= B; }
			}
			if(x != bit(v[j], b)) { return false; }
		}
		return true;
	};
	auto f = [&](int b) -> bool {
		auto I = [&](int i) {
			if(s[i] == 1 && bit(u[i], b) == 0) { return 0; }
			if(s[i] == 0 && bit(u[i], b) == 1) { return 1; }
			if(s[i] == 0 && bit(u[i], b) == 0) { return 2; }
			if(s[i] == 1 && bit(u[i], b) == 1) { return 3; }
			UR;
		};
		auto J = [&](int j) {
			if(t[j] == 1 && bit(v[j], b) == 0) { return 0; }
			if(t[j] == 0 && bit(v[j], b) == 1) { return 1; }
			if(t[j] == 0 && bit(v[j], b) == 0) { return 2; }
			if(t[j] == 1 && bit(v[j], b) == 1) { return 3; }
			UR;
		};
		
		auto sub = [&](int i, int j, U x) {
			assert(x == 0 || x == 1);
			ans[i][j] |= (x << b);
		};
		
		int cI0 = 0, cI1 = 0, cJ0 = 0, cJ1 = 0;
		inc(i, n) { (bit(u[i], b) == 0 ? cI0 : cI1)++; }
		inc(j, n) { (bit(v[j], b) == 0 ? cJ0 : cJ1)++; }
		
		int ci = -1, cj = 0;
		inc(i, n) { cj = 0;
		inc(j, n) {
			int II = I(i), JJ = J(j);
			if(II == 0 && JJ == 1) { return false; }
			ef(II == 1 && JJ == 0) { return false; }
			ef(II <   2) { sub(i, j, II); }
			ef(JJ <   2) { sub(i, j, JJ); }
			ef(II == JJ) { sub(i, j, II % 2); }
			else {
				if(
					(II == 2 && cJ0 == 0 && cI1 == 0) ||
					(II == 3 && cJ1 == 0 && cI0 == 0)
				) {
					if(cj == 0) { ci++; }
					sub(i, j, (ci + cj) % 2);
					cj++;
				} else {
					if(II == 2 && cJ0 > 0) { sub(i, j, 1); }
					ef(II == 2 && cI1 > 0) { sub(i, j, 0); }
					ef(II == 3 && cJ1 > 0) { sub(i, j, 0); }
					ef(II == 3 && cI0 > 0) { sub(i, j, 1); }
					else { UR; }
				}
			}
		}
		}
		
		return check(b);
	};
	
	inc(b, 64) { if(! f(b)) { OUT(-1); exit(0); } }
	RF(e, ans) { OUT(e); }
}
