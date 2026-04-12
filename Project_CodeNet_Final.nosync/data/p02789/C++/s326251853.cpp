#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
#define incID(i, l, r) for(int i = (l)    ; i <  (r); ++i)
#define incII(i, l, r) for(int i = (l)    ; i <= (r); ++i)
#define decID(i, l, r) for(int i = (r) - 1; i >= (l); --i)
#define decII(i, l, r) for(int i = (r)    ; i >= (l); --i)
#define inc(i, n)  incID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define dec(i, n)  decID(i, 0, n)
#define dec1(i, n) decII(i, 1, n)
#define inID(v, l, r) ((l) <= (v) && (v) <  (r))
#define inII(v, l, r) ((l) <= (v) && (v) <= (r))
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define  ALL(v)  v.begin(),  v.end()
#define RALL(v) v.rbegin(), v.rend()
auto setmin   = [](auto & a, auto b) { return (b <  a ? a = b, true : false); };
auto setmax   = [](auto & a, auto b) { return (b >  a ? a = b, true : false); };
auto setmineq = [](auto & a, auto b) { return (b <= a ? a = b, true : false); };
auto setmaxeq = [](auto & a, auto b) { return (b >= a ? a = b, true : false); };
auto fl = [](auto a, auto b) { assert(b != 0); return a / b - (a % b != 0 && ((a >= 0) != (b >= 0)) ? 1 : 0); };
auto ce = [](auto a, auto b) { assert(b != 0); return a / b + (a % b != 0 && ((a >= 0) == (b >= 0)) ? 1 : 0); };
auto mo = [](auto a, auto b) { assert(b != 0); a %= b; if(a < 0) { a += abs(b); } return a; };
LL gcd(LL a, LL b) { return (b == 0 ? a : gcd(b, a % b)); }
LL lcm(LL a, LL b) { return a / gcd(a, b) * b; }
#define bit(b, i) (((b) >> (i)) & 1)
#define SI(v) static_cast<int>(v.size())
#define RF(e, v) for(auto & e: v)
#define until(e) while(! (e))
#define if_not(e) if(! (e))
#define ef else if
#define UR assert(false)

// ---- ----

int main() {
	int n, m;
	cin >> n >> m;
	
	cout << (n == m ? "Yes" : "No") << endl;
	
	return 0;
}
