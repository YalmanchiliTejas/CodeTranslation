#include <bits/stdc++.h>
#define LL long long
#define FOR(i,c) for(__typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define F first
#define S second
using namespace std;

const LL mod = 1e9 + 7;

template<typename T> T gcd(T a, T b) { return b == 0?a: gcd(b, a % b); }
template<typename T> T LCM(T a, T b) { return a*(b/gcd(a, b)); }
template<typename T> T expo(T base, T e, T mod) { T res = 1;
  while(e > 0) { if(e&1) res = res * base % mod; base = base * base % mod; e >>= 1; }
  return res;
}
template<typename T, typename S> T expo(T b, S e){if(e <= 1)return e == 0?1: b;\
	return (e&1) == 0?expo((b*b), e>>1): (b*expo((b*b), e>>1));}
template<typename T, typename S> T modinv(T a, S mod) { return expo(a, mod-2, mod); }
template<class T, class S> std::ostream& operator<<(std::ostream &os, const std::pair<T, S> &t) {
	os<<"("<<t.first<<", "<<t.second<<")";
	return os;
}
template<class T> std::ostream& operator<<(std::ostream &os, const std::vector<T> &t) {
	os<<"["; FOR(it,t) { if(it != t.begin()) os<<", "; os<<*it; } os<<"]";
	return os;
}

const int MAXN = 1e5 + 100;

int n;
pair<LL, LL> arr[MAXN];
vector<pair<LL, int> > xs;
vector<pair<LL, int> > ys;

struct dsu {
  vector<int> Rank, P;
  int V;
  dsu(int v = 0) : V(v) {
    Rank = vector<int>(v + 1, 0);
    P = vector<int>(v + 1, 0);
    for(int i = 0; i < P.size(); i++) {
      P[i] = i, Rank[i] = 1;
    }
  }
  int find_root(int x) { return x == P[x] ? x : P[x] = find_root(P[x]); }
  void merge(int x, int y) {
    int xr = find_root(P[x]), yr = find_root(P[y]);
    if(xr == yr) return ;
    if(Rank[xr] < Rank[yr]) swap(xr, yr), swap(x, y);
    Rank[xr] += Rank[yr];
    P[yr] = xr;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i].F >> arr[i].S;
	}
	sort(arr, arr + n);
	n = unique(arr, arr + n) - arr;
	for(int i = 0; i < n; i++) {
		xs.push_back({arr[i].F, i});
		ys.push_back({arr[i].S, i});
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	dsu tester(n);
	vector<pair<LL, pair<int, int> > > edges;
	for(int i = 0; i < n; i++) {
		LL x = arr[i].F, y = arr[i].S;
		auto it = lower_bound(xs.begin(), xs.end(), make_pair(x, i));
		if(next(it) != xs.end()) {
			int other = next(it)->S;
			edges.push_back({min(abs(arr[other].F - arr[i].F), abs(arr[other].S - arr[i].S)), {i, other}});
		}
		if(it != xs.begin()) {
			int other = prev(it)->S;
			edges.push_back({min(abs(arr[other].F - arr[i].F), abs(arr[other].S - arr[i].S)), {i, other}});
		}
		it = lower_bound(ys.begin(), ys.end(), make_pair(y, i));
		if(next(it) != ys.end()) {
			int other = next(it)->S;
			edges.push_back({min(abs(arr[other].F - arr[i].F), abs(arr[other].S - arr[i].S)), {i, other}});
		}
		if(it != ys.begin()) {
			int other = prev(it)->S;
			edges.push_back({min(abs(arr[other].F - arr[i].F), abs(arr[other].S - arr[i].S)), {i, other}});
		}
	}
	sort(edges.begin(), edges.end());
	LL res = 0;
	for(auto &elem: edges) {
		LL wt = elem.F;
		int u = elem.S.F, v = elem.S.S;
		if(tester.find_root(u) != tester.find_root(v)) {
			tester.merge(u, v);
			res += elem.F;
		}
	}
	cout << res << '\n';
  return 0;
}
