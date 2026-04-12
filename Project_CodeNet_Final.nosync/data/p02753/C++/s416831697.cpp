#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
#include<stack>
#include<cstdio>
#include<cstring>
#include<bitset>
#include<unordered_map>
#include<climits>
#include<fstream>
#include<complex>
#include<time.h>
#include<cassert>
#include<functional>
#include<numeric>
#include<tuple>

using namespace std;
using ll = long long;
using ld = long double;
#define int long long
#define all(a) (a).begin(),(a).end()
#define fs first
#define sc second
#define xx first
#define yy second.first
#define zz second.second
#define H pair<int, int>
#define P pair<int, pair<int, int>>
#define Q(i,j,k) mkp(i,mkp(j,k))
#define R pair<pair<int, int>, pair<int, int>>
#define S(i,j,k,l) mkp(mkp(i,j),mkp(k,l))
#define rep(i,n) for(int (i) = 0 ; (i) < (n) ; (i)++)
#define rng(i,s,n) for(int (i) = (s) ; (i) < (n) ; (i)++)
#define req(n,i) for(int (i) = (n) - 1 ; (i) >= 0 ; (i)--)
#define range(i,v) for(auto& (i) : v)
#define mkp make_pair
#define mem(x,k) memset(x,k,sizeof(x))
#define vec vector
#define pb emplace_back
#define lb lower_bound
#define ub upper_bound
#define crdcomp(b) sort(all((b)));(b).erase(unique(all((b))),(b).end())
#define getidx(b,i) lower_bound(all(b),(i))-b.begin()
#define ssp(i,n) (i==n-1?"\n":" ")
#define ctoi(c) (int)(c-'0')
#define itoc(c) (char)(c+'0')
#define itn int
#define pri_que priority_queue
#define pp(x,y) pb(H{x,y})
#define ppp(x,y,z) pb(Q(x,y,z))
#define pppp(x,y,z,w) pb(S(x,y,z,w))
#define cyes cout<<"Yes\n"
#define cno cout<<"No\n"
#define endl "\n"
constexpr int mod = 1e9 + 7;
constexpr int Mod = 998244353;
constexpr ll inf = 3 * 1e18;
constexpr int Inf = 15 * 1e8;
const vec<int>dx{ -1,1,0,0 }, dy{ 0,0,-1,1 };
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
ll read() { ll u, k = scanf("%lld", &u); return u; }
string reads() { string s; cin >> s; return s; }
H readh(bool g = 0) { H u; ll k = scanf("%lld %lld", &u.fs, &u.sc); if (g) u.fs--, u.sc--; return u; }
void printh(H t) { printf("%lld %lld\n", t.fs, t.sc); }
bool inarea(H t, int h, int w) { return 0 <= t.fs && t.fs < h && 0 <= t.sc && t.sc < w; }
ll gcd(ll i, ll j) { return j ? gcd(j, i % j) : i; }
ll mod_pow(ll x, ll n, ll p = mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % p;
		x = x * x % p;
		n >>= 1;
	}
	return res;
}//x^n%p
ll bitcount(ll x) {
	int sum = 0; for (int i = 0; i < 60; i++)if ((1ll << i) & x) sum++;
	return sum;
}
/*constexpr int fn_ = 1000005;
ll fact_[fn_], comp_[fn_];
ll comb(ll x, ll y, ll Mod = mod) {
	if (!fact_[0]) {
		fact_[0] = 1; comp_[0] = 1;
		for (int i = 1; i < fn_; i++) 
			fact_[i] = fact_[i - 1] * i % Mod;
		comp_[fn_ - 1] = mod_pow(fact_[fn_ - 1], Mod - 2, Mod);
		for (int i = fn_ - 2; i > 0; i--)
			comp_[i] = comp_[i + 1] * (i + 1) % Mod;
	}
	if (x < y) return 0;
	return fact_[x] * comp_[x - y] % Mod * comp_[y] % Mod;
}*/
//--------------------------------------------------------------

signed main() {
	string s; cin >> s;
	if (s[0] == s[1] && s[1] == s[2]) {
		cout << "No\n";
	}
	else {
		cout << "Yes\n";
	}
}