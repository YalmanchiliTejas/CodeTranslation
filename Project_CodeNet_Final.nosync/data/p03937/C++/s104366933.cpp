#include <iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include <set>
#include <cassert>
#include<cmath>
#include<climits>
#include<iomanip>
using namespace std;
#define MOD 1000000007
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define all(hoge) (hoge).begin(),(hoge).end()
const long long INF = 1LL << 60;
typedef vector<ll> Array;
typedef vector<Array> Matrix;



struct Edge {//グラフ
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
void add_edge(Graph &G, ll from, ll to, ll cap) {//最大フロー求める Ford-fulkerson
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	G[to].push_back(Edge(from, 0, (ll)G[from].size() - 1));
}
ll max_flow_dfs(Graph &G, ll v, ll t, ll f,vector<bool> &used)
{
	if (v == t)
		return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); ++i) {
		Edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			ll d = max_flow_dfs(G,e.to, t, min(f, e.cap),used);
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
ll max_flow(Graph &G, ll s, ll t)
{
	ll flow = 0;
	for (;;) {
		vector<bool> used(G.size());
		REP(i, used.size())used[i] = false;
		ll f = max_flow_dfs(G,s, t, INF,used);
		if (f == 0) {
			return flow;
		}
		flow += f;
	}
}

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

class UnionFind {
	vector<int> data;
public:
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};


//約数求める //約数
void divisor(ll n,vector<ll> &ret) {
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(ret.begin(), ret.end());
	
}
//階乗
long long factorial(long long n, long long mod) {
	long long ret = 1;
	for (long long i = 1; i <= n; i++) {
		ret = (ret * i) % mod;
	}
	return ret;
}
//モジュラ逆数
long long inv_mod(long long n, long long mod) {
	long long a = n % mod, b = mod - 2, ret = 1;
	while (b > 0) {
		if (b & 1) ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}

long long nPr(long long n, long long r, long long mod) {
	long long ret = 1;
	for (long long i = n; i >= n - r + 1; i--) {
		ret = ret * (i % mod) % mod;
	}
	return ret;
}

long long nCr(long long n, long long r, long long mod) {
	return nPr(n, r, mod) * inv_mod(factorial(r, mod), mod) % mod;
}

bool compare_by_b(pair<ll, ll> a, pair<ll, ll> b) {//降順second
	if (a.second != b.second) {
		return a.second > b.second;
	}
	else {
		return a.first > b.first;
	}
}

bool compare_by_a(pair<ll, ll> a, pair<ll, ll> b) {//降順first
	if (a.first != b.first) {
		return a.first > b.first;
	}
	else {
		return a.second > b.second;
	}
}

ll gcd(ll m, ll n){
	if (n == 0)return m;
	return gcd(n, m%n);
}//gcd


int main() {
	ll h, w;
	cin >> h >> w;
	vector<vector<char>> a(h);
	ll cnt = 0;
	REP(i, h) {
		a[i].resize(w);
		REP(j, w) {
			cin >> a[i][j];
			if (a[i][j] == '#')cnt++;
		}
	}
	if (cnt == h + w - 1) {
		cout << "Possible";
	}
	else {
		cout << "Impossible";
	}
	return 0;
}
