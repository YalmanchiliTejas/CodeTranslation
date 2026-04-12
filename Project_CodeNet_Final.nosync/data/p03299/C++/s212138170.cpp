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

//#define DEBUG_

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
typedef vector<vector<vector<Pi> > > vvvPi;
typedef vector<vector<vector<vector<Pi> > > > vvvvPi;
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
char dirchar[4] = { '<','^','>','v' };

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
	bool operator<(Edge e) {
		return cost < e.cost;
	}
};
using Graph = vec<vec<Edge>>;

ostream& operator << (ostream& os, Edge &edge) {
	os << "(" << edge.from << "->" << edge.to << ":" << edge.cost << ")";
	return os;
}
//======================================================

ll powMod(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

vll h;
Graph G;
vector<Pll> node;
vector<Pll> dp;

int addChild(int par, Pll val) {
	static int next = 0;

	if(par != -1) G[par].push_back(Edge{ par,next,1 });
	node[next] = val;
	next++;
	return next - 1;
}

// [left, right)で部分木作成
void makeTree(int par, int height, int left, int right) {
	if (right <= left)return;
	cerr << left << "-" << right << endl;

	bool same = true;
	ll minheight = h[left];
	repr(i, left + 1, right) {
		if (h[i] != h[i - 1]) {
			same = false;
		}
		minheight = min(minheight, h[i]);
	}
	int pos = addChild(par, mp(right - left, minheight - height));
	if (same) {
		return;
	}

	int l = left;
	repr(i, left, right) {
		if (h[i] == minheight) {
			makeTree(pos, minheight, l, i);
			l = i + 1;
		}
	}
	makeTree(pos, minheight, l, right);
}

void solve(int pos) {
	ll x = node[pos].second;
	ll w = node[pos].first;
	for (auto e : G[pos]) {
		w -= node[e.to].first;
	}

	ll dp1 = powMod(2, x, MOD);
	ll dp21 = powMod(2, w, MOD);
	ll dp22 = (powMod(2, x, MOD) - 2 + MOD) % MOD;

	for (auto e : G[pos]) {
		solve(e.to);
		dp1 *= dp[e.to].first;
		dp1 %= MOD;
		dp21 *= dp[e.to].first + dp[e.to].second;
		dp21 %= MOD;
		dp22 *= dp[e.to].first;
		dp22 %= MOD;
	}
	dp[pos].first = dp1;
	dp[pos].second = (dp21 + dp22) % MOD;
}

int main() {
	int N;
	cin >> N;
	h.resize(N);
	cin >> h;

	G.resize(N);
	node.resize(N, mp(-1,-1));
	dp.resize(N, mp(-1,-1));

	makeTree(-1, 0, 0, N);

	solve(0);

	cout << dp[0].second << endl;

	return 0;
}