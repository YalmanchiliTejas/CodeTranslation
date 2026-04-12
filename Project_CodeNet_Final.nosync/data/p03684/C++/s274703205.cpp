#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#include <random>
#include <unordered_map>
#include <unordered_set>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp>

using namespace std;

//呪文
#define DUMPOUT cerr
#define dump(...) DUMPOUT<<"  ";DUMPOUT<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl;DUMPOUT<<"    ";dump_func(__VA_ARGS__)

typedef unsigned uint; typedef long long ll; typedef unsigned long long ull; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<double, double> pdd; typedef pair<string, string> pss;
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const pair<_KTy, _Ty>& m) { ostr << "{" << m.first << ", " << m.second << "}"; return ostr; }
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const map<_KTy, _Ty>& m) { if (m.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const unordered_map<_KTy, _Ty>& m) { if (m.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const vector<_Ty>& v) { if (v.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << v.front(); for (auto itr = ++v.begin(); itr != v.end(); itr++) { ostr << ", " << *itr; }	ostr << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const set<_Ty>& s) { if (s.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) { ostr << ", " << *itr; }	ostr << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const unordered_set<_Ty>& s) { if (s.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) { ostr << ", " << *itr; }	ostr << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const stack<_Ty>& s) { if (s.empty()) { ostr << "{ }"; return ostr; } stack<_Ty> t(s); ostr << "{" << t.top(); t.pop(); while (!t.empty()) { ostr << ", " << t.top(); t.pop(); } ostr << "}";	return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const list<_Ty>& l) { if (l.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << l.front(); for (auto itr = ++l.begin(); itr != l.end(); ++itr) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
template <typename _KTy, typename _Ty> istream& operator >> (istream& istr, pair<_KTy, _Ty>& m) { istr >> m.first >> m.second; return istr; }
template <typename _Ty> istream& operator >> (istream& istr, vector<_Ty>& v) { for (size_t i = 0; i < v.size(); i++) istr >> v[i]; return istr; }
namespace aux { // print tuple
	template<typename Ty, unsigned N, unsigned L> struct tp { static void print(ostream& os, const Ty& v) { os << get<N>(v) << ", "; tp<Ty, N + 1, L>::print(os, v); } };
	template<typename Ty, unsigned N> struct tp<Ty, N, N> { static void print(ostream& os, const Ty& value) { os << get<N>(value); } };
}
template<typename... Tys> ostream& operator<<(ostream& os, const tuple<Tys...>& t) { os << "{"; aux::tp<tuple<Tys...>, 0, sizeof...(Tys)-1>::print(os, t); os << "}"; return os; }

template<typename A, size_t N, typename T> inline void Fill(A(&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }

void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head&& head, Tail&&... tail) { DUMPOUT << head; if (sizeof...(Tail) == 0) { DUMPOUT << " "; } else { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#define PI 3.14159265358979323846
#define EPS 1e-10
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fake false



const ll MAX = 101010;
ll par[MAX];
ll rnk[MAX];

void init(ll n) {
	for (ll i = 0; i < n; i++) {
		par[i] = i;
		rnk[i] = 0;
	}
}

ll find(ll x) {
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

void unite(ll x, ll y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;

	if (rnk[x] < rnk[y])
		par[x] = y;
	else {
		par[y] = x;
		if (rnk[x] == rnk[y])
			rnk[x]++;
	}
}

bool same(ll x, ll y) {
	return find(x) == find(y);
}

struct edge {
	ll u, v, cost;
	edge() {}
	edge(ll u, ll v, ll cost) : u(u), v(v), cost(cost) {}
};

bool comp(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}

ll kruskal(vector<edge> es, ll V) {
	ll E = es.size();
	sort(all(es), comp);
	init(V);
	ll res = 0;
	for (ll i = 0; i < E; i++) {
		edge e = es[i];
		if (!same(e.u, e.v)) {
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;
	
	typedef pair<ll, pll> pl3; // (idx, point)
	vector<pl3> pts(N);
	for (int i = 0; i < N; i++) {
		pts[i].first = i;
		cin >> pts[i].second;
	}

	vector<edge> es;

	// sort by x
	sort(all(pts), [&](const pl3& a, const pl3& b) {
		return a.second.first < b.second.first;
	});
	// add edges
	for (int i = 0; i < N - 1; i++) {
		ll cost = pts[i + 1].second.first - pts[i].second.first;
		ll v = pts[i].first, w = pts[i + 1].first;
		if (v > w)
			swap(v, w);
		es.push_back(edge(v, w, cost));
	}

	// sort by y
	sort(all(pts), [&](const pl3& a, const pl3& b) {
		return a.second.second < b.second.second;
	});
	// add edges
	for (int i = 0; i < N - 1; i++) {
		ll cost = pts[i + 1].second.second - pts[i].second.second;
		ll v = pts[i].first, w = pts[i + 1].first;
		if (v > w)
			swap(v, w);
		es.push_back(edge(v, w, cost));
	}

	cout << kruskal(es, N) << endl;

	return 0;
}