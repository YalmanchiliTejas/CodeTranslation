/*
ll used[10];
ll maxi;

ll dfs(Graph& graph, ll v, ll deep) {
	used[v] = 1;
	vector<ll> maxd;
	maxd.push_back(deep);
	for (int i = 0; i < graph[v].size(); i++) {
		if (used[graph[v][i].to] == 0) {
			maxd.push_back(dfs(graph, graph[v][i].to, deep + 1));
		}
	}
	sort(all(maxd), greater<ll>());
	if (maxd.size() > 2) {
		chmax(maxi, maxd[0] - deep + maxd[1] - deep);
	}
	else {
		chmax(maxi, maxd[0] - deep);
	}
	return maxd[0];
}
*///dfs
/*
REP(i, n) {
	REP(j, n) {
		dp[i][j] = INF;
	}
}
REP(i, m) {
	ll a, b, c;
	cin >> a >> b >> c;
	dp[a][b] = c;
	dp[b][a] = c;
}
REP(i, n) {
	REP(j, n) {
		REP(k, n) {
			chmin(dp[j][k], dp[j][i] + dp[i][k]);
		}
	}
}
*///warshall floyd

#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
using namespace std;
#define MOD 1000000007
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
const long long INF = 1LL << 60;
typedef vector<ll> Array;
typedef vector<Array> Matrix;

//sortは初期で昇順 greater<hoge>()で降順
//substr　文字列取り出し
//upper_bound ある値より大きい一番左のイテレータを返す、lowerは以上(setに対して使うとO(N)なので、setのメンバ関数を使う
//stoi


struct Edge {//グラフ
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
void add_edge(Graph& G, ll from, ll to, ll cap) {//最大フロー求める Ford-fulkerson
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	G[to].push_back(Edge(from, cap, (ll)G[from].size() - 1));//最小カットの場合逆辺は0にする
}
ll max_flow_dfs(Graph & G, ll v, ll t, ll f, vector<bool> & used)
{
	if (v == t)
		return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); ++i) {
		Edge& e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			ll d = max_flow_dfs(G, e.to, t, min(f, e.cap), used);
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
ll max_flow(Graph & G, ll s, ll t)
{
	ll flow = 0;
	for (;;) {
		vector<bool> used(G.size());
		REP(i, used.size())used[i] = false;
		ll f = max_flow_dfs(G, s, t, INF, used);
		if (f == 0) {
			return flow;
		}
		flow += f;
	}
}

template<class T> inline bool chmin(T & a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T & a, T b) {
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
void divisor(ll n, vector<ll>& ret) {
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(ret.begin(), ret.end());

}

//nCrとか
class Combination {
public:
	Array fact;
	Array inv;
	ll mod;
	ll mod_inv(ll x) {
		ll n = mod - 2;
		ll res = 1LL;
		while (n > 0) {
			if (n & 1) res = res * x % mod;
			x = x * x % mod;
			n >>= 1;
		}
		return res;
	}
	ll nCr(ll n, ll r) {
		return ((fact[n] * inv[r] % mod) * inv[n - r]) % mod;
	}
	ll nPr(ll n, ll r) {
		return (fact[n] * inv[n - r]) % mod;
	}
	Combination(ll n, ll _mod) {
		mod = _mod;
		fact.resize(n + 1);
		fact[0] = 1;
		REP(i, n) {
			fact[i + 1] = (fact[i] * (i + 1LL)) % mod;
		}
		inv.resize(n + 1);
		REP(i, n + 1) {
			inv[i] = mod_inv(fact[i]);
		}
	}
};

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

ll gcd(ll m, ll n) {
	if (n == 0)return m;
	return gcd(n, m % n);
}//gcd

ll lcm(ll m, ll n) {
	return m / gcd(m, n) * n;
}


int main() {
	ll r, g, b;
	cin >> r >> g >> b;
	ll ans = r * 100 + g * 10 + b;
	if (ans % 4 == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}
