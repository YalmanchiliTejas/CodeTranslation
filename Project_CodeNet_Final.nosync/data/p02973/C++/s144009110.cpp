#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)), v.end());
typedef long long int ll; typedef pair<ll, ll> P; typedef complex<double> com;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int inf = INT_MAX / 2; const ll INF = LLONG_MAX / 2;
const int mod = 1e9 + 7; //998244353;
struct Mint {
	int val;
	Mint inv() const {
		unsigned tmp, a = val, b = mod; int x = 1, y = 0;
		while (b) tmp = a / b, a -= tmp * b, swap(a, b), x -= tmp * y, swap(x, y);
		return Mint(x);
	}
public:
	Mint() :val(0) {}
	Mint(ll x) :val(x >= 0 ? x % mod : x % mod + mod) {}
	int mtoi() { return this->val; }
	Mint pow(ll t) { Mint res = 1; while (t > 0) { if (t & 1) res *= *this; *this *= *this; t >>= 1; }return res; }
	Mint& operator+=(const Mint& x) { if ((val += x.val) >= mod) val -= mod; return *this; }
	Mint& operator-=(const Mint& x) { if ((val += mod - x.val) >= mod) val -= mod; return *this; }
	Mint& operator*=(const Mint& x) { val = (ll)val * x.val % mod; return *this; }
	Mint& operator/=(const Mint& x) { return *this *= x.inv(); }
	bool operator==(const Mint& x) const { return val == x.val; }
	bool operator!=(const Mint& x) const { return val != x.val; }
	bool operator<(const Mint& x) const { return val < x.val; }
	bool operator<=(const Mint& x) const { return val <= x.val; }
	bool operator>(const Mint& x) const { return val > x.val; }
	bool operator>=(const Mint& x) const { return val >= x.val; }
	Mint operator-() const { return Mint(-val); }
	Mint operator+(const Mint& x) const { return Mint(*this) += x; }
	Mint operator-(const Mint& x) const { return Mint(*this) -= x; }
	Mint operator*(const Mint& x) const { return Mint(*this) *= x; }
	Mint operator/(const Mint& x) const { return Mint(*this) /= x; }
};
struct factorial {
	vector<Mint> Fact, Finv;
public:
	factorial(int maxx) {
		Fact.resize(maxx + 1, Mint(1)); Finv.resize(maxx + 1);
		rep(i, 0, maxx) Fact[i + 1] = Fact[i] * Mint(i + 1);
		Finv[maxx] = Mint(1) / Fact[maxx];
		rrep(i, maxx, 0) Finv[i - 1] = Finv[i] * Mint(i);
	}
	Mint fact(int n) { return Fact[n]; }
	Mint finv(int n) { return Finv[n]; }
	Mint nCr(int n, int r) {
		if (n < 0 || n < r || r < 0) return Mint(0);
		return Fact[n] * Finv[r] * Finv[n - r];
	}
	Mint nPr(int n, int r) {
		if (n < 0 || n < r || r < 0) return Mint(0);
		return Fact[n] * Finv[n - r];
	}
};
class UnionFind {
	vector<int> par;
public:
	UnionFind(int n) { par = vector<int>(n, -1); }
	int root(int a) {
		if (par[a] < 0) return a;
		else return par[a] = root(par[a]);
	}
	int size(int a) { return -par[root(a)]; }
	bool connect(int a, int b) {
		a = root(a), b = root(b);
		if (a == b) return false;
		if (size(a) < size(b)) swap(a, b);
		par[a] += par[b], par[b] = a;
		return true;
	}
};
struct edge { int u, v, cost; };
vector<ll>dijkstra(vector<vector<edge>> Grp, int s) {
	priority_queue<P, vector<P>, greater<P> > que;
	vector<ll> dist(Grp.size(), INF); dist[s] = 0; que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second; if (dist[v] < p.first) continue;
		rep(i, 0, Grp[v].size()) {
			edge e = Grp[v][i];
			if (dist[e.v] > dist[v] + e.cost) {
				dist[e.v] = dist[v] + e.cost;
				que.push(P(dist[e.v], e.v));
			}
		}
	} return dist;
}
ll merge_cnt(vector<int> a) {
	ll n = a.size(), ai = 0, bi = 0, ci = 0, cnt = 0;
	if (n <= 1) return 0;
	vector<int> b(a.begin(), a.begin() + n / 2);
	vector<int> c(a.begin() + n / 2, a.end());
	cnt += merge_cnt(b) + merge_cnt(c);
	while (ai < n) {
		if (bi < b.size() && (ci == c.size() || b[bi] <= c[ci]))a[ai++] = b[bi++];
		else cnt += n / 2LL - bi, a[ai++] = c[ci++];
	}
	return cnt;
}
//template end



int main() {
	int n; cin>>n;
	vector<int> a(n);
	rep(i,0,n) cin>>a[i];
	multiset<int> st;
	rep(i,0,n){
		auto idx=st.lower_bound(a[i]);
		if(idx!=st.begin()){
			idx--; st.erase(idx);
		} 
		st.insert(a[i]);
	}
	printf("%d\n",st.size());
	return 0; 
}
