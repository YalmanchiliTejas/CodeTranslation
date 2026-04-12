#include <bits/stdc++.h>
using namespace std;
typedef long long   signed int LL;
typedef long long unsigned int LU;
#define incID(i, l, r) for(LL i = (l)    ; i <  (r); ++i)
#define incII(i, l, r) for(LL i = (l)    ; i <= (r); ++i)
#define decID(i, l, r) for(LL i = (r) - 1; i >= (l); --i)
#define decII(i, l, r) for(LL i = (r)    ; i >= (l); --i)
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
template<typename T> bool setmin  (T & a, T b) { if(b <  a) { a = b; return true; } else { return false; } }
template<typename T> bool setmax  (T & a, T b) { if(b >  a) { a = b; return true; } else { return false; } }
template<typename T> bool setmineq(T & a, T b) { if(b <= a) { a = b; return true; } else { return false; } }
template<typename T> bool setmaxeq(T & a, T b) { if(b >= a) { a = b; return true; } else { return false; } }
LL mo(LL a, LL b) { assert(b > 0); a %= b; if(a < 0) { a += b; } return a; }
LL fl(LL a, LL b) { assert(b > 0); return (a > 0 ? a / b : (a - b + 1) / b); }
LL ce(LL a, LL b) { assert(b > 0); return (a < 0 ? a / b : (a + b - 1) / b); }
template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define bit(b, i) (((b) >> (i)) & 1)
#define BC __builtin_popcountll
#define SC static_cast
#define SI(v) SC<int>(v.size())
#define SL(v) SC<LL >(v.size())
#define RF(e, v) for(auto & e: v)
#define ef else if
#define UR assert(false)

// ---- ----

int n, a[100000];

int main() {
	cin >> n;
	inc(i, n) { cin >> a[i]; }
	
	multiset<int> se;
	se.insert(2e9);
	inc(i, n) {
		if(a[i] <= (*se.begin())) { se.insert(a[i]); } else {
			auto it = --(se.lower_bound(a[i]));
			se.erase(it);
			se.insert(a[i]);
		}
	}
	
	cout << SI(se) - 1 << endl;
	
	return 0;
}
