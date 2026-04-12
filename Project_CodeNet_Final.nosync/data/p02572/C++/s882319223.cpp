#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("unroll-loops")  
 
#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<double,double>;
 
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<double>; 
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;
 
#define tcT template<class T
#define tcTUU tcT, class ...U
#define tcTU tcT, class U
#define tcTU3 tcTU, class C
#define tcTU4 tcTU3, class D
 
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using mpq = priority_queue<T, vector<T>, greater<T>>;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

tcT> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fbo find_by_order 
#define ook order_of_key 
tcTU> using ht = gp_hash_table<T,U,chash>;*/

struct chash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x^(x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x^(x >> 27)) * 0x94d049bb133111eb;
		return x^(x >> 31);
	}
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = 
			chrono::steady_clock::now()
			.time_since_epoch().count();
		return splitmix64(x+FIXED_RANDOM);
	}
};
tcTU> using um = unordered_map<T,U,chash>;

#define cbit(n, b) (((n)>>(b))&1)
#define sbit(n, b) ((n)|(1ULL<<(b)))
#define rbit(n, b) ((n)&~(1ULL<<(b)))
#define fbit(n, b) ((n)^(1ULL<<(b)))

#define ts to_string
#define fe first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(v) ((int)(v).size())
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back 
#define mt make_tuple 
#define eb emplace_back
#define mp make_pair
#define lb lower_bound 
#define ub upper_bound 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

tcTU> T fstTrue(T lo, T hi, U f) { 
	while (lo < hi) {
		T mid = (lo+hi)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	while (lo < hi) { 
		T mid = (lo+hi+1)/2;
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}

const int di[4]={-1, 0, 1, 0}, dj[4]={0, 1, 0, -1};
const int di8[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dj8[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int MOD = 1e9+7; //const int MOD =998244353;
const ld PI = acos((ld)-1);

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng);}

bool pow2(int i){ return i&&(i&-i)==i;}
constexpr int pct(int x) { return __builtin_popcount(x); } 
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 

tcT> bool chmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } 
tcT> bool chmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

tcT> void remDup(vector<T>& v) { 
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void remAll(vector<T>& v, U a){
	v.erase(remove(all(v),a),v.end());
}

// TO_STRING
tcTU3> string ts(tuple<T,U,C> p);
tcTU4> string ts(tuple<T,U,C,D> p);
string ts(char c) { return string(1,c); }
string ts(bool b) { 
    #ifdef __APPLE__
		return b ? "true" : "false"; 
	#else 
		return ts((int)b);
	#endif
}
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
tcT> string ts(complex<T> c) { 
	stringstream ss; ss << c; return ss.str(); }
string ts(vb v) { 
	string res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> string ts(bitset<SZ> b) {
	string res = ""; F0R(i,sz(b)) res += char('0'+b[i]);
	return res; }
tcTU> string ts(pair<T,U> p);
tcT> string ts(T v) { // containers with begin(), end()
	#ifdef __APPLE__
		bool fst = 1; string res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; string res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;
	#endif
}
tcTU> string ts(pair<T,U> p) {
	#ifdef __APPLE__
		return "("+ts(p.fe)+", "+ts(p.se)+")"; 
	#else
		return ts(p.fe)+" "+ts(p.se);
	#endif
}
tcTU3> string ts(tuple<T,U,C> p) { 
	#ifdef __APPLE__
	    return "("+ts(get<0>(p))+","+ts(get<1>(p))+","+ts(get<2>(p))+")";
	#else 
	    return ts(get<0>(p))+" "+ts(get<1>(p))+" "+ts(get<2>(p));
	#endif
}
tcTU4> string ts(tuple<T,U,C,D> p) {
	#ifdef __APPLE__
	    return "("+ts(get<0>(p))+","+ts(get<1>(p))+","+ts(get<2>(p))+","+ts(get<3>(p))+")";
	#else 
	    return ts(get<0>(p))+" "+ts(get<1>(p))+" "+ts(get<2>(p))+" "+ts(get<3>(p));
	#endif
}
//INPUT  void re(string& d){getline(cin,d) ;getline(cin,d); }

tcTU3> void re(tuple<T,U,C>& p);
tcTU4> void re(tuple<T,U,C,D>& p);
tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(vector<T>& v);

tcT, size_t SZ> void re(AR<T,SZ>& a);
tcT> void re(T& x) { cin >> x; }
void re(double& d) { string t; re(t); d = stod(t); }
void re(ld& d) { string t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }
tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.fe,p.se); }
tcT> void re(vector<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(array<T,SZ>& x) { trav(a,x) re(a); }
tcTU3> void re(tuple<T,U,C>& p){re(get<0>(p),get<1>(p),get<2>(p));}
tcTU4> void re(tuple<T,U,C,D>& p){re(get<0>(p),get<1>(p),get<2>(p),get<3>(p));}
// OUTPUT
tcT> void pr(T x) { cout << ts(x); }
tcTUU> void pr(const T& t, const U&... u) { 
	pr(t); pr(u...); }
void ps() { pr("\n"); } // print w/ spaces
tcTUU> void ps(const T& t, const U&... u) { 
	pr(t); if (sizeof...(u)) pr(" "); ps(u...); }
 
// DEBUG
void DBG() { cerr << "]" << endl; }
tcTUU> void DBG(const T& t, const U&... u) {
	cerr << ts(t); if (sizeof...(u)) cerr << ", ";
	DBG(u...); }
#ifdef __APPLE__ // chk -> fake assert
	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif


template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint() { v = 0; }
	mint(ll _v) { v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD; }
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	friend void re(mint& a) { ll x; re(x); a = mint(x); }
	friend string ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = (ll)v*m.v%MOD; return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};
 
typedef mint<MOD,5> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;
 
vector<vmi> scmb; // small combinations
void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	FOR(i,1,SZ) F0R(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}
vi invs, fac, ifac;
void genFac(int SZ) { // pre-compute factorial mod inverses
	invs.resize(SZ), fac.resize(SZ), ifac.resize(SZ); 
	invs[1] = fac[0] = ifac[0] = 1; 
	FOR(i,2,SZ) invs[i] = MOD-(ll)MOD/i*invs[MOD%i]%MOD;
	FOR(i,1,SZ) {
		fac[i] = (ll)fac[i-1]*i%MOD;
		ifac[i] = (ll)ifac[i-1]*invs[i]%MOD;
	}
}
	
ll comb(int a, int b) {
		if (a < b || b < 0) return 0;
		return (ll)fac[a]*ifac[b]%MOD*ifac[a-b]%MOD;
	}




ll gcd(ll a,ll b) {  return b?gcd(b,a%b):a;}
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void IOS(int n=10, string s=""){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
  cout.precision(n); cerr.precision(n); cerr << fixed; cout << fixed;
  if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

const int mxN = 1e5;

void solve(){
	int n; re(n); vmi a(n); re(a); mi ans = 0, s = 0; trav(i,a) s+=i;
	trav(i,a){
		s-=i;
		ans+=i*s;
	}
	ps(ans);
}
int main(){
	IOS();
	int t=1; //re(t);
	F0R(i,t){
		//pr("Case #",i+1,": "); 
		solve(); 
	}
#ifdef __APPLE__
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
 





