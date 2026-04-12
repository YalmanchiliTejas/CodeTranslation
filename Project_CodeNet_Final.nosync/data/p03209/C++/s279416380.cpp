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
using namespace std; using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
int ctoi(char c) {
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
ll i, j, k, l; ll N, M, K, H, W, L;
ll MOD = 1000000007; ll INF = 9999999999999; ll ans = 0;
vl flag, color, D; vll path;
//***********//
vl A = { 1 };
vl P = { 1 };
ll f(ll N, ll X) {
	if (N == 0) {
		if (X <= 0) return 0;
		else return 1;
	}
	else if (X <= 1 + A[N - 1]) return f(N - 1, X - 1);
	else return P[N - 1] + 1 + f(N - 1, X - 2 - A[N - 1]);
}
int main() {
	ll X;
	cin >> N >> X;
	for (i = 0; i < N; i++) {
		A.push_back(A[i] * 2 + 3);
		P.push_back(P[i] * 2 + 1);
	}
	cout << f(N, X);
}