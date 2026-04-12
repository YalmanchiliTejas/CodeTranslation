#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <sys/timeb.h>
#include <fstream>
#include <random>
#include <regex>
#include <chrono>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <limits>

using namespace std;

#define DEBUG_

#define repr(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repr(i,0,n)
#define reprrev(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define reprev(i,n) reprrev(i,0,n)
#define repi(itr,ds) for(auto itr=ds.begin();itr!=ds.end();itr++)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define mp make_pair
#define mt make_tuple
#define INF 1050000000
#define INFR INT_MAX
#define INFL (long long)(4e18)
#define INFLR LLONG_MAX
#define EPS (1e-10)
#define MOD 1000000007
#define PI 3.141592653589793238
#define RMAX 4294967295


#ifdef DEBUG_
#define DEB
#else
#define DEB if(false)
#endif

#ifdef DEBUG_
#define dump(...) DUMPOUT<<"  "; \
dump_func(string(#__VA_ARGS__) + ":", "[" + to_string(__LINE__) + ":" + __FUNCTION__ + "]"); \
DUMPOUT<<"    "; \
dump_func(__VA_ARGS__)
#else
#define dump(...)
#endif

typedef long long ll;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<Pi> vPi;
typedef vector<Pll> vPll;
typedef vector<Pd>vPd;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;
typedef vector<vector<ll> > vvll;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<double> > vvd;
typedef vector<vector<Pi> > vvPi;
typedef vector<vector<vector<int> > > vvvi;
typedef vector<vector<vector<ll> > > vvvll;
typedef priority_queue<int, vector<int>, greater<int> > pqli;
typedef priority_queue<ll, vector<ll>, greater<ll> > pqlll;
typedef priority_queue<Pi, vector<Pi>, greater<Pi> > pqlP;
template <class T>
using vec = vector<T>;
template<class T>
using pql = priority_queue<T, vector<T>, greater<T>>;
string debug_show(Pi a) {
	return "(" + to_string(a.first) + "," + to_string(a.second) + ")";
}

#define DUMPOUT cerr

void dump_func() {
	DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail) {
	DUMPOUT << head;
	if (sizeof...(Tail) <= 1) {
		DUMPOUT << " ";
	}
	else {
		DUMPOUT << ", ";
	}
	dump_func(std::move(tail)...);
}

// vector
template<typename T>
istream& operator >> (istream& is, vector<T>& vec) {
	for (T& x : vec) is >> x;
	return is;
}
// pair
template<typename T, typename U>
ostream& operator << (ostream& os, pair<T, U>& pair_var) {
	os << "(" << pair_var.first << "," << pair_var.second << ")";
	return os;
}
// pair
template<typename T, typename U>
ostream& operator << (ostream& os, const pair<T, U>& pair_var) {
	os << "(" << pair_var.first << "," << pair_var.second << ")";
	return os;
}
// vector
template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
	os << "{";
	for (int i = 0; i < vec.size(); i++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
	}
	os << "}";
	return os;
}
// map
template<typename T, typename U>
ostream& operator << (ostream& os, map<T, U>& map_var) {
	os << "{";
	repi(itr, map_var) {
		os << "(" << itr->first << "," << itr->second << ")";
		itr++;
		if (itr == map_var.end()) os << ", ";
		itr--;
	}
	os << "}";
	return os;
}
// set
template<typename T>
ostream& operator << (ostream& os, set<T>& set_var) {
	os << "{";
	repi(itr, set_var) {
		os << "  " << *itr << endl;
		itr++;
		if (itr == set_var.end()) os << ", ";
		itr--;
	}
	os << "}";
	return os;
}
string YN(bool y, int id = 0) { if (id)cout << id; return (y ? "YES" : "NO"); }
string yn(bool y, int id = 0) { if (id)cout << id; return (y ? "Yes" : "No"); }
string ON(bool y, int id = 0) { if (id)cout << id; return (y ? "OK" : "NG"); }

int dir4[4][2] = { { 0,-1 },{ -1,0 },{ 1,0 },{ 0,1 } };
int dir8[8][2] = { { -1,-1 },{ 0,-1 },{ 1,-1 },{ -1,0 },{ 1,0 },{ -1,1 },{ 0,1 },{ 1,1 } };

// [a,b)
int irand(int a, int b) {
	static mt19937 Rand(static_cast<unsigned int>(time(nullptr)));
	uniform_int_distribution<int> dist(a, b - 1);
	return dist(Rand);
}

// [a,b)
double drand(int a, int b) {
	static mt19937 Rand(static_cast<unsigned int>(time(nullptr)));
	uniform_real_distribution<double> dist(a, b);
	return dist(Rand);
}
struct Edge {
	int from, to, cost;
};
using Graph = vec<vec<Edge>>;

//======================================================


// モジュラ逆数を求める(modが素数と仮定)
void ModInv(int n, vector<ll> &inv, int mod) {
	inv[0] = 0;
	inv[1] = 1;
	for (int i = 2; i <= n; i++) {
		inv[i] = mod - ((mod / i) * inv[mod % i] % mod);
	}
}

// n!をmodで割った余り
void FacInv(int n, vector<ll> &inv, vector<ll> &fac, vector<ll> &facInv, int mod) {
	fac[0] = facInv[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = (fac[i - 1] * i) % mod;
		facInv[i] = (facInv[i - 1] * (int)inv[i]) % mod;
	}
}

// nCkをmodで割った余りを求める。mod素数限定
// ModInv()とFacInv()が必要
long CombiMod(int n, int k, int mod, const vll &inv, const vll &fac, const vll &facInv) {
	if (n == 0 && k == 0) return 1;
	if (n <= 0 || k < 0 || k > n) return 0;
	if (k == 0) return 1;

	return (((fac[n] * facInv[k]) % mod) * facInv[n - k]) % mod;
}

ll powMod(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<ll> inv(N + 2);
	vector<ll> fac(N + 2);
	vector<ll> facInv(N + 2);
	ModInv(N + 1, inv,M);
	FacInv(N + 1, inv, fac, facInv, M);

	vll ways(N + 1, 0);
	vvll ways2(N + 1, vll(N + 1, 0));
	ways2[0][0] = 1;
	repr(i, 1, N + 1) {
		rep(j, N + 1) {
			if (j > i) {
				ways2[i][j] = 0;
			}
			else if (j == 0 || j == i) {
				ways2[i][j] = 1;
			}
			else {
				ways2[i][j] = (((j + 1) * ways2[i - 1][j]) % M + ways2[i - 1][j - 1]) % M;
			}
		}
	}
	
	/*
	rep(i, N + 1) {
		rep(j, N + 1) {
			cerr << ways2[i][j] << " ";
		}
		cerr << endl;
	}
	*/

	rep(i, N + 1) {
		rep(j, i + 1) {
			ways[i] += ways2[i][j] * powMod(2, (ll)(N - i) * j, M);
			ways[i] %= M;
		}
		ways[i] *= powMod(2, powMod(2, N - i, M - 1), M);
		ways[i] %= M;
	}

	ll ans = 0;
	rep(i, N + 1) {
		ll val = (CombiMod(N, i, M, inv, fac, facInv) * ways[i]) % M;

		if (i % 2 == 0) {
			ans = (ans + val) % M;
		}
		else {
			ans = (ans - val + M) % M;
		}
	}

	cout << ans << endl;

	return 0;
}