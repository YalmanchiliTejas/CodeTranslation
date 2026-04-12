#include <iostream>
#include <fstream>
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string> 
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
using ll = long long;

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;

#define REP(i,n) for(int i = 0; i < int(n); i++)
#define FOR(i, m, n) for(int i = int(m);i < int(n);i++)
#define ALL(obj) (obj).begin(),(obj).end()

const ll MOD = (ll)1e9 + 7;
const ll HINF = (ll)1e18;
const ll LINF = (ll)1e9;
const long double PI = 3.1415926535897932384626433;

template<class T> void corner(bool flg, T hoge) { if (flg) { cout << hoge << endl; exit(0); } else return; }
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) { o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o; }
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) { o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o; }
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) { o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o; }
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) { o << "{" << obj.first << ", " << obj.second << "}"; return o; }
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) { o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o; }
void print(void) { cout << endl; }
template <class Head> void print(Head&& head) { cout << head; print(); }
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) { cout << head << " "; print(forward<Tail>(tail)...); }
template <class T> void chmax(T& a, const T b) { a = max<T>(a, b); }
template <class T> void chmin(T& a, const T b) { a = min<T>(a, b); }
void YN(bool flg) { cout << ((flg) ? "YES" : "NO") << endl; }
void Yn(bool flg) { cout << ((flg) ? "Yes" : "No") << endl; }
void yn(bool flg) { cout << ((flg) ? "yes" : "no") << endl; }

//Dijkstra
template<class T> class Dijkstra {
public:
	int N;
	T inf;
	vector<T> cost;
	vector<vector<pair<T, int>>> edge;

	Dijkstra(const int N, T inf) : N(N), inf(inf), cost(N), edge(N) {
	}

	void make_edge(int from, int to, T w) {
		edge[from].push_back({ w,to });
	}

	void solve(int start) {
		for (int i = 0; i < N; ++i) cost[i] = inf;

		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
		cost[start] = 0;
		pq.push({ 0,start });

		while (!pq.empty()) {
			T v = pq.top().first;
			int from = pq.top().second;
			pq.pop();
			for (auto u : edge[from]) {
				T w = v + u.first;
				int to = u.second;
				if (w < cost[to]) {
					cost[to] = w;
					pq.push({ w,to });
				}
			}
		}
		return;
	}
};

int main() {
	int N, M, S, T; cin >> N >> M >> S >> T;
	S--, T--;
	Dijkstra<ll> dijkS(N, HINF), dijkT(N, HINF);
	while (M--) {
		ll U, V, D; cin >> U >> V >> D;
		U--, V--;
		dijkS.make_edge(U, V, D);
		dijkS.make_edge(V, U, D);
		dijkT.make_edge(U, V, D);
		dijkT.make_edge(V, U, D);
	}
	dijkS.solve(S);
	dijkT.solve(T);
	V<ll> dpS(N, 0), dpT(N, 0);
	dpS[S] = dpT[T] = 1;
	V<P<ll, int>> ordS(N), ordT(N);
	for (int i = 0; i < N; ++i) {
		ordS[i] = { dijkS.cost[i],i };
		ordT[i] = { dijkT.cost[i],i };
	}
	sort(ALL(ordS));
	sort(ALL(ordT));
	for (int i = 0; i < N; ++i) {
		int from, to;
		ll cost;

		from = ordS[i].second;
		for (auto e : dijkS.edge[from]) {
			cost = e.first;
			to = e.second;
			if (dijkS.cost[from] + cost == dijkS.cost[to]) (dpS[to] += dpS[from]) %= MOD;
		}

		from = ordT[i].second;
		for (auto e : dijkT.edge[from]) {
			cost = e.first;
			to = e.second;
			if (dijkT.cost[from] + cost == dijkT.cost[to]) (dpT[to] += dpT[from]) %= MOD;
		}
	}
	ll d = dijkS.cost[T];
	ll ans = (dpS[T] * dpT[S]) % MOD;
	for (int i = 0; i < N; ++i) {
		if (d % 2) continue;
		if (dijkS.cost[i] == d / 2 && dijkT.cost[i] == d / 2) {
			ll cnt = 1;
			(cnt *= dpS[i]) %= MOD;
			(cnt *= dpS[i]) %= MOD;
			(cnt *= dpT[i]) %= MOD;
			(cnt *= dpT[i]) %= MOD;
			(ans += (MOD - cnt)) %= MOD;
		}
	}
	for (int l = 0; l < N; ++l) {
		for (auto e : dijkS.edge[l]) {
			int r = e.second;
			ll w = e.first;
			if (dijkS.cost[l] + w + dijkT.cost[r] != d) continue;

			if (d % 2) {
				double h = d / 2;
				if (dijkS.cost[l] < h && h < dijkS.cost[l] + w && dijkT.cost[r] < h && h < dijkT.cost[r] + w) {
					ll cnt = 1;
					(cnt *= dpS[l]) %= MOD;
					(cnt *= dpS[l]) %= MOD;
					(cnt *= dpT[r]) %= MOD;
					(cnt *= dpT[r]) %= MOD;
					(ans += (MOD - cnt)) %= MOD;
				}
			}
			else {
				if (dijkS.cost[l] == d / 2 || dijkT.cost[r] == d / 2) continue;
				if (dijkS.cost[l] < d / 2 && d / 2 < dijkS.cost[l] + w && dijkT.cost[r] < d / 2 && d / 2 < dijkT.cost[r] + w) {
					ll cnt = 1;
					(cnt *= dpS[l]) %= MOD;
					(cnt *= dpS[l]) %= MOD;
					(cnt *= dpT[r]) %= MOD;
					(cnt *= dpT[r]) %= MOD;
					(ans += (MOD - cnt)) %= MOD;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}

