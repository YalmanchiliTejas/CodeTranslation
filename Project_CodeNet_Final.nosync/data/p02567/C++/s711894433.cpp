#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std; using ll = long long; using ld = long double;  using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vlll = vector<vll>; using vpll = vector<pll>;
using vs = vector<string>; using tll = tuple<ll, ll, ll>; using vtll = vector<tll>;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const ld PI = 3.1415926535897932;
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define co(i) cout << i << endl;
#define co2(i,j) cout << i << " " << j << endl;
#define co3(i) cout << i << " ";
#define po(i) cout << i.first << " " << i.second << endl;
void in() {}
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head h, Tail... t) {
	cerr << " " << h;
	if (sizeof...(t) > 0) cerr << " :";
	debug_out(t...);
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
	for (size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	return os;
}
ll ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{
	return firstElof.second < secondElof.second;
}
//AtCoder以外ではコメントアウトを忘れずに！
#include <atcoder/all>
using namespace atcoder;
//**Snippetリスト**//
//rep, vin, all, iteLoop, bitSearch, bitList, nod, LIS, digitDP, treeDP, Rerooting//
//gcdlcm, isPrime, eratos, primeFactorize, Npow, combination, divisor, modinv, doubling//
//dfs, bfs, dijkstra, WarshallFloyd, BellmanFord, UnionFind, Kruskal, RMQ, LCA, FordFulkerson//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z, R, Q, T;
ll MOD = 1000000007, INF = 1LL << 60, ans = 0, z = 0, o = 1;
vll flag, D; vector<vpll> path; vs S;
int op(int a, int b) {
	return max(a, b);
}
int e() { return -1; }
int target;
bool f(int v) { return v < target; }
int main() {
	cin >> N >> Q;
	segtree<int, op, e> T(N);
	for (i = 0; i < N; i++) {
		ll a;
		cin >> a;
		T.set(i, a);
	}
	for (i = 0; i < Q; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			b--;
			T.set(b, c);
		}
		else if (a == 2) {
			b--;
			co(T.prod(b, c));
		}
		else {
			b--;
			target = c;
			co(T.max_right<f>(b)+1);
			//一見min_leftの方が素直に思えるが、N+1出力に対応するために敢えてmax_rightを使っている
		}
	}
}