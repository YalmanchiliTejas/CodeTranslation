#include <bits/stdc++.h>
#define ADD(a, b) a = (a + ll(b)) % mod
#define MUL(a, b) a = (a * ll(b)) % mod
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define all(a) (a).begin(), (a).end()
#define sz(v) (int)(v).size()
#define pb push_back
#define sec second
#define fst first
#define debug(fmt, ...) Debug(__LINE__, ":", fmt, ##__VA_ARGS__)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> ppi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> mat;
void Debug() {cout << '\n'; }
template<class FIRST, class... REST>void Debug(FIRST arg, REST... rest){
	cout<<arg<<" ";Debug(rest...);}
template<class T>ostream& operator<<(ostream& out,const vector<T>& v) {
	out<<"[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<<", ";out<<v.back();}out<<"]";return out;}
template<class S, class T>ostream& operator<<(ostream& out,const pair<S, T>& v){
	out<<"("<<v.first<<", "<<v.second<<")";return out;}
const int MAX_N = 400010;
const int MAX_V = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = 1 << 29;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
///////////////////////////////////////////////////////////////////////////////////////////////////

struct UF {
	vector<int> par, ran;
	void init(int n) {
		par.resize(n); ran.resize(n);
		for(int i = 0; i < n; i++) {
			par[i] = i;
			ran[i] = 0;
		}
	}
	UF(int mx = 0) { init(mx); }

	int find(int x) {
		if(par[x] == x) return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(ran[x] < ran[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if(ran[x] == ran[y]) ran[x]++;
		}
	}
	bool same(int x, int y) { return find(x) == find(y); }
};

//////////////

int N, M, E;
struct edge { int u, v, cost; };

bool comp(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}

edge es[400010];
vector<pi> G[MAX_N];
int depth[MAX_N];
int par[MAX_N];
int cost[MAX_N];

ll kruskal() {
	sort(es, es + E, comp);
	UF uf(N);//init union_find
	ll res = 0;
	for(int i = 0; i < E; i++) {
		edge e = es[i];
		if(!uf.same(e.u, e.v)) {
			uf.unite(e.u, e.v);
			G[e.u].pb(pi(e.v, e.cost));
			G[e.v].pb(pi(e.u, e.cost));
			res += e.cost;
		}
	}
	return res;
}

void add_edge(int s, int t, int cost) {
	es[E++] = edge{s, t, cost};
}

void loop(int v, int p, int k) {
	depth[v] = k;
	par[v] = p;
	rep(i, 0, sz(G[v])) {
		int n = G[v][i].fst;
		if(n == p) continue;
		cost[n] = G[v][i].sec;
		loop(n, v, k + 1);
	}
}

void solve() {
	E = 0;
	cin >> N >> M;
	rep(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c; a--; b--;
		add_edge(a, b, c);
	}
	ll S = kruskal();
	loop(0, -1, 0);
	int Q; cin >> Q;
	while(Q--) {
		int a, b; cin >> a >> b; a--; b--;
		if(depth[a] < depth[b]) swap(a, b);
		int mv = -1;
		while(depth[a] > depth[b]) {
			MAX(mv, cost[a]);
			a = par[a];
		}
		// debug(depth[a], depth[b], a, b);
		while(a != b) {
			MAX(mv, cost[a]);
			MAX(mv, cost[b]);
			a = par[a]; b = par[b];
		}
		cout << S - mv << "\n";
	}
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
	srand((unsigned int)time(NULL));
#ifdef LOCAL
	//freopen("in.txt", "wt", stdout); //for tester
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

