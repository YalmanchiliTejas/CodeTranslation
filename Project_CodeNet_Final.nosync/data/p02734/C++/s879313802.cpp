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
using namespace std; using ll = long long; using ld = long double;  using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
using vs = vector<string>; using tll = tuple<ll, ll, ll>; using vtll = vector<tll>;
const ld PI = 3.1415926535897932;
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define mp make_pair
#define mt make_tuple
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
	return firstElof.first > secondElof.first;
}
//**Snippetリスト**//
//rep, vin, all, iteLoop, bitSearch, bitList, nod//
//gcdlcm, isPrime, eratos, primeFactorize, Npow, combination, divisor, modinv, doubling, digitDP//
//dfs, bfs, dijkstra, WarshallFloyd, BellmanFord, UnionFind, Kruskal ,RMQ, LCA//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z, R, Q;
ll MOD = 1000000007, INF = 1LL << 60, ans = 0, z = 0, o = 1;
vl flag, D; vpll path;
//***********//
int main() { 
	MOD = 998244353;
	ll S;
	cin >> N >> S;
	vl A(N);
	for (i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<vll> dp(N + 1, vll(S + 1,vl(3,0)));
	dp[0][0][0] = 1;
	for (i = 0; i < N; i++) {
		for (j = 0; j <= S; j++) {
			if (j == S) {
				(dp[i + 1][S][2] += dp[i][S][2]) %= MOD;
				(dp[i + 1][S][2] += dp[i][S][1]) %= MOD;
				(dp[i + 1][S][1] += dp[i][S][1]) %= MOD;
			}
			else {
				(dp[i + 1][j][1] += dp[i][j][1]) %= MOD;
				(dp[i + 1][j][1] += dp[i][j][0]) %= MOD;
				(dp[i + 1][j][0] += dp[i][j][0]) %= MOD;
			}
			if (j + A[i] <= S) {
				if (j + A[i] == S) {
					(dp[i + 1][j + A[i]][2] += dp[i][j][0]) %= MOD;
					(dp[i + 1][j + A[i]][2] += dp[i][j][1]) %= MOD;
				}
				(dp[i + 1][j + A[i]][1] += dp[i][j][0]) %= MOD;
				(dp[i + 1][j + A[i]][1] += dp[i][j][1]) %= MOD;
			}
		}
	}
	cout << dp[N][S][2];
}