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
using namespace std; using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
//**デバッグ準備**//
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
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
//rep, vin, all, iteLoop//
//gcdlcm, isPrime, eratos, divisor, modinv, bitSearch, bitList, dfs, bfs//
//dijkstra, UnionFind, COM, digitDP//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z;
ll MOD = 1000000007; ll INF = 1LL << 60; ll ans = 0;
vl flag, color; vll path; ll start = 0;
//***********//
int main() {
	cin >> N;
	vl A(N);
	for (i = 0; i < N; i++) {
		cin >> A[i];
	}
	vll dp(N + 1, vl(3, 0));
	for (i = 0; i < N + 1; i++) {
		for (j = 0; j < 3; j++) {
			dp[i][j] = INF * (-1);
		}
	}
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[1][2] = 0;
	dp[1][0] = A[0];
	dp[2][1] = A[1];
	if (N != 2) dp[3][2] = A[2];
	for (i = 2; i < N; i++) {
		dp[i + 1][0] = max(dp[i + 1][0], dp[i - 1][0] + A[i]);
		dp[i + 1][1] = max(dp[i + 1][1], dp[i - 1][1] + A[i]);
		dp[i + 1][1] = max(dp[i + 1][1], dp[i - 2][0] + A[i]);
		if (N % 2 == 1 && i > 2) {
			dp[i + 1][2] = max(dp[i + 1][2], dp[i - 1][2] + A[i]);
			dp[i + 1][2] = max(dp[i + 1][2], dp[i - 2][1] + A[i]);
			dp[i + 1][2] = max(dp[i + 1][2], dp[i - 3][0] + A[i]);
		}
	}
	if (N % 2 == 1) {
		cout << max(max(dp[N - 2][0], dp[N - 1][1]), dp[N][2]);
	}
	else {
		cout << max(dp[N - 1][0], dp[N][1]);
	}
}
