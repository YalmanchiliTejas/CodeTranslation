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
ll nod(ll F) { return log10(F) + 1; }
//**定義場所**//
//gcd, isPrime, eratos, modinv, bitSearch, dfs, bfs, dijkstra, UnionFind//
ll i, j, k, l, m, n; ll N, M, K, H, W, L; string S;
ll MOD = 1000000007; ll ans = 0; ll INF = 9999999999999;
vl flag, color; vll path; vl A, T;
//***********//
int main() {
	cin >> N >> M;
	if (N == M) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}