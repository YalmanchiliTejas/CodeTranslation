#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::bitset;
using std::complex;
using std::vector;
using std::array;
using std::list;
using std::string;
using std::pair;
using std::queue;
using std::priority_queue;
using std::set;
using std::map;
using std::unordered_map;
using std::sort;
using std::min;
using std::max;
using std::reverse;
using std::min_element;
using std::max_element;
using std::accumulate;

using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using ll = long long int;
using vll = vector<ll>; using vvll = vector<vll>; using vvvll = vector<vvll>;
using vd = vector<double>; using vvd = vector<vd>; using vvvd = vector<vvd>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using cdouble = complex<double>;

const double eps = 1e-7;
#define Loop(i, n) for(int i = 0; i < int(n); i++)
#define Loopll(i, n) for(ll i = 0; i < ll(n); i++)
#define Loop1(i, n) for(int i = 1; i <= int(n); i++)
#define Loopll1(i, n) for(ll i = 1; i <= ll(n); i++)
#define Loopr(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define Looprll(i, n) for(ll i = ll(n) - 1; i >= 0; i--)
#define Loopr1(i, n) for(int i = int(n); i >= 1; i--)
#define Looprll1(i, n) for(ll i = ll(n); i >= 1; i--)
#define Foreach(buf, container) for(const auto &buf : container)
#define Foreachr(buf, container)  for(const auto &buf : reversed(container))
#define Loopdiag(i, j, h, w, sum) for(int i = ((sum) >= (h) ? (h) - 1 : (sum)), j = (sum) - i; i >= 0 && j < (w); i--, j++)
#define Loopdiagr(i, j, h, w, sum) for(int j = ((sum) >= (w) ? (w) - 1 : (sum)), i = (sum) - j; j >= 0 && i < (h); j--, i++)
#define Loopdiagsym(i, j, h, w, gap) for (int i = ((gap) >= 0 ? (gap) : 0), j = i - (gap); i < (h) && j < (w); i++, j++)
#define Loopdiagsymr(i, j, h, w, gap) for (int i = ((gap) > (h) - (w) - 1 ? (h) - 1 : (w) - 1 + (gap)), j = i - (gap); i >= 0 && j >= 0; i--, j--)
#define Loopitr(itr, container) for(auto itr = container.begin(); itr != container.end(); itr++)
#define quickio() std::ios::sync_with_stdio(false); std::cin.tie(0);
#define bitmanip(m,val) static_cast<bitset<(int)m>>(val)
#define Comp(type_t) bool operator<(const type_t &another) const
#define fst first
#define snd second
#define INF INFINITY
bool feq(double x, double y) { return abs(x - y) <= eps; }
bool inrange(ll x, ll t) { return x >= 0 && x < t; }
bool inrange(vll xs, ll t) { Foreach(x, xs) if (!(x >= 0 && x < t)) return false; return true; }
int ceillog2(ll x) { int m = int(log2(x)); return m + ((1LL << m) < x ? 1 : 0); }
int floorlog2(ll x) { int m = int(log2(x)); return m - ((1LL << m) > x ? 1 : 0); }
const string endl = "\n";
template<class T> T reversed(T container) { reverse(container.begin(), container.end()); return container; }
template<class T> void printv(const vector<T> &v) { for (const T &x : v) cout << x << " "; cout << endl; }
template<class T> void printmx(const vector<vector<T>> &mx) { for (const vector<T> &v : mx) printv(v); }
ll rndf(double x) { return (ll)(x + (x >= 0 ? 0.5 : -0.5)); }
ll floorsqrt(ll x) { ll m = (ll)sqrt((double)x); return m + (m*  m <= x ? 0 : -1); }
ll ceilsqrt(ll x) { ll m = (ll)sqrt((double)x); return m + (x <= m * m ? 0 : 1); }
ll rnddiv(ll a, ll b) { return (a / b + (a % b * 2 >= b ? 1 : 0)); }
ll ceildiv(ll a, ll b) { return (a / b + (a % b == 0 ? 0 : 1)); }
ll gcd(ll m, ll n) { if (n == 0) return m; else return gcd(n, m % n); }
ll lcm(ll m, ll n) { return ll(m) * ll(n) / gcd(m, n); }

//========================================================================//

class MaxFlow_with_LB {
private:
	struct edge_t {
		int from; int to; ll cap; edge_t* rev;
	};
	struct node_t {
		int skip = false;
		list<edge_t*> edges;
	};
	struct graph_t {
		int n, m;
		int s, t;
		vector<node_t> nodes;
	};
	void add_edge(int a, int b, ll c) {
		edge_t *e_pre;
		edge_t *e_rev;
		if (pre_edges[{a, b}] == nullptr) {
			e_pre = new edge_t({ a, b, c, nullptr });
			e_rev = new edge_t({ b, a, 0, nullptr });
			e_pre->rev = e_rev;
			e_rev->rev = e_pre;
			pre_edges[{a, b}] = e_pre;
			this->G.nodes[a].edges.push_back(e_pre);
			this->G.nodes[b].edges.push_back(e_rev);
		}
		else {
			pre_edges[{a, b}]->cap += c;
		}
	}
	void make_level_graph(int s, int t) {
		LG.n = G.n;
		LG.m = 0;
		LG.s = s;
		LG.t = t;
		LG.nodes = vector<node_t>(G.n);
		vi levels(G.n, INT_MAX);
		queue<int> que;
		levels[s] = 0;
		que.push(s);
		while (que.size()) {
			int a = que.front(); que.pop();
			for (edge_t* e : G.nodes[a].edges) {
				if (e->cap > 0) {
					if (levels[e->to] == INT_MAX) {
						levels[e->to] = levels[a] + 1;
						que.push(e->to);
					}
					if (levels[e->to] == levels[a] + 1) {
						LG.nodes[a].edges.push_back(e);
						LG.m += 1;
					}
				}
			}
		}
		if (levels[t] == INT_MAX) LG.t = -1;
	}
	ll add_flow_on_LG(int a, ll f) {
		if (a == LG.t) return f;
		ll ret = 0;
		for (auto itr = LG.nodes[a].edges.begin(); itr != LG.nodes[a].edges.end();) {
			if (f == 0) break;
			edge_t* e = *itr;
			if (LG.nodes[e->to].skip) {
				itr = LG.nodes[a].edges.erase(itr);
			}
			else {
				ll df = add_flow_on_LG(e->to, min(e->cap, f));
				if (df > 0) {
					e->cap -= df;
					e->rev->cap += df;
					ret += df;
					f -= df;
					if (e->cap == 0) itr = LG.nodes[a].edges.erase(itr);
					else itr++;
				}
				else {
					LG.nodes[e->to].skip = true;
					itr = LG.nodes[a].edges.erase(itr);
				}
			}
		}
		return ret;
	}
	// return achieved flow
	ll add_flow_sub(int s, int t, ll f) {
		ll ret = 0;
		Loop(_, G.n) {
			if (f == 0) break;
			make_level_graph(s, t);
			if (LG.t == -1) break;
			ll df = add_flow_on_LG(LG.s, f);
			if (df == 0) break;
			ret += df;
			f -= df;
		}
		return ret;
	}
	map<P, edge_t*> pre_edges;
	graph_t G, LG;
	bool feasible_flag;
	ll sum_flow = 0;
public:
	// make sure that bnd <= cap, solve required flow in constructor
	MaxFlow_with_LB(const vvi &lst, const vvll &bnd, const vvll &cap, int s, int t) {
		this->G.n = lst.size() + 2;
		this->G.s = lst.size();
		this->G.t = lst.size() + 1;
		this->G.nodes = vector<node_t>(G.n);
		Loop(i, lst.size()) {
			Loop(k, lst[i].size()) {
				int j = lst[i][k];
				ll b = bnd[i][k];
				ll c = cap[i][k];
				if (b > 0) {
					add_edge(G.s, j, b);
					add_edge(i, G.t, b);
					sum_flow -= b;
				}
				if (c - b > 0) {
					add_edge(i, j, c - b);
				}
			}
		}
		ll f00 = add_flow_sub(G.s, G.t, LLONG_MAX);
		ll f01 = add_flow_sub(G.s, t, LLONG_MAX);
		ll f10 = add_flow_sub(s, G.t, LLONG_MAX);
		add_edge(t, G.t, LLONG_MAX);
		add_edge(G.s, s, LLONG_MAX);
		pre_edges[{t, G.t}]->cap -= f01;
		pre_edges[{t, G.t}]->rev->cap += f01;
		pre_edges[{G.s, s}]->cap -= f10;
		pre_edges[{G.s, s}]->rev->cap += f10;
		this->feasible_flag = (this->sum_flow + f00 + f01 == 0) && (this->sum_flow + f00 + f10 == 0);
		this->sum_flow += f00 + f01 + f10;
	}
	~MaxFlow_with_LB() {
		for (const auto &x : this->pre_edges) {
			edge_t *e = x.snd;
			delete e->rev;
			delete e;
		}
	}
	// return achieved flow, Dinic's algorithm, O(min(n^2 m, fm))
	void add_flow(ll f = LLONG_MAX) {
		this->sum_flow += add_flow_sub(this->G.s, this->G.t, f);
	}
	ll get_flow() {
		return sum_flow;
	}
	bool is_feasible() {
		return this->feasible_flag;
	}
};

bool solve(int n, int m, const vector<P> &p, int l, int r) {
	vvi lst(1 + m + n + 1);
	vvll bnd(1 + m + n + 1);
	vvll cap(1 + m + n + 1);
	Loop(i, p.size()) {
		lst[1 + i].push_back(1 + m + p[i].fst);
		bnd[1 + i].push_back(0);
		cap[1 + i].push_back(1);
		lst[1 + i].push_back(1 + m + p[i].snd);
		bnd[1 + i].push_back(0);
		cap[1 + i].push_back(1);
	}
	Loop(i, m) {
		lst[0].push_back(1 + i);
		bnd[0].push_back(1);
		cap[0].push_back(1);
	}
	Loop(i, n) {
		lst[1 + m + i].push_back(1 + m + n);
		bnd[1 + m + i].push_back(l);
		cap[1 + m + i].push_back(r);
	}
	MaxFlow_with_LB *mf = new MaxFlow_with_LB(lst, bnd, cap, 0, 1 + m + n);
	bool ans = mf->is_feasible();
	delete mf;
	return ans;
}

int main() {
	quickio();
	vector<P> acc;
	while (true) {
		int n, m; cin >> n >> m;
		if (n == 0 && m == 0) break;
		vector<P> p(m);
		Loop(i, m) {
			cin >> p[i].fst >> p[i].snd;
			p[i].fst--;
			p[i].snd--;
		}
		pair<ll, ll> ans = { 0, n };
		for (ll l = 0, r = 0; l <= n && r <= n;) {
			if (l * n > m) break;
			if (l > r) r++;
			else {
				bool judge = solve(n, m, p, l, r);
				if (judge) {
					if (r - l <= ans.snd - ans.fst) {
						ans = { l, r };
					}
					l++;
				}
				else {
					r++;
				}
			}
		}
		acc.push_back(ans);
	}
	Loop(i, acc.size()) {
		cout << acc[i].fst << " " << acc[i].snd << endl;
	}
	return 0;
}
