#include <bits/stdc++.h>
#define ADD(a, b) a = (a + (ll)b) % mod
#define MUL(a, b) a = (a * (ll)b) % mod
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rer(i, a, b) for(int i = a - 1; i >= b; i--)
#define all(a) (a).begin(), (a).end()
#define sec second
#define fst first
#define debug(fmt, ...) Debug(__LINE__, ":", fmt, ##__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> ppi;
typedef vector<ll> vec;

const int MAX_N = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = 1 << 30;

void Debug() {cout << '\n'; }

template<class FIRST, class... REST> 
void Debug(FIRST arg, REST... rest) { cout << arg << " "; Debug(rest...); }

template<class T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "[";
	if(!v.empty()) {
		rep(i, 0, (int)v.size() - 1) out << v[i] << ", ";
		out << v.back();
	}
	out << "]";
  return out;
}

template<class S, class T>
ostream& operator<< (ostream& out, const pair<S, T>& v) {
	out << "(" << v.first << ", " << v.second << ")";
	return out;
}

///g++ -g3 -std=c++0x -DLOCAL -Wall -ftrapv -D_GLIBCXX_DEBUG -Wl,-stack,268435456 -o
///g++ -O2 -std=c++0x -DLOCAL -Wall -Wl,-stack,268435456 -o

///////////////////////////////////////////////////////////////////////

//////////////
//unionfind

int N, E;
int par[MAX_N];
int ran[MAX_N];

void init(int n) {
	for(int i = 0; i < n; i++) {
		par[i] = i;
		ran[i] = 0;
	}
}

int find(int x) {
	if(par[x] == x) {
		return x;
	}
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

bool same(int x, int y) {
	return find(x) == find(y);
}

//////////////


struct edge { int u, v, cost; };

bool comp(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}

//int N, E; add this////////////////////////////
edge es[200010];

int kruskal() {
	sort(es, es + E, comp);
	init(N);//init union_find
	int res = 0;
	for(int i = 0; i < E; i++) {
		edge e = es[i];
		if(!same(e.u, e.v)) {
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}

void add_edge(int s, int t, int cost) {
	es[E++] = edge{s, t, cost};
}

pi X[MAX_N], Y[MAX_N];

void solve() {
	cin >> N;
	rep(i, 0, N) {
		int a, b;
		cin >> a >> b;
		X[i] = pi(a, i);
		Y[i] = pi(b, i);
	}
	sort(X, X + N);
	sort(Y, Y + N);
	rep(i, 0, N - 1) {
		add_edge(X[i].sec, X[i + 1].sec, X[i + 1].fst - X[i].fst);
		add_edge(Y[i].sec, Y[i + 1].sec, Y[i + 1].fst - Y[i].fst);
	}
	cout << kruskal() << "\n";
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);	
    cout << fixed;
	cout.precision(20);
#ifdef LOCAL
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}


