#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };
const int INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}

template<class T1, class T2> void chmin(T1 &a, T2 b) { if (a>b)a = b; }

template<class T1, class T2> void chmax(T1 &a, T2 b) { if (a<b)a = b; }
template<class T>
void Add(T &a, const T &b, const T &mod = 1000000007) {
	int val = ((a % mod) + (b % mod)) % mod;
	if (val < 0) { val += mod; }
	a = val;
}
////////////////////////////////////////
ll P[55];
ll L[55];
ll dfs(ll x,ll n) {
	if (n == 0)return 1;
	if (x == 1)return 0;
	else if (x <= 1 + L[n - 1])return dfs(x - 1, n-1);
	else if (x == 2 + L[n - 1])return P[n - 1] + 1;
	else if (x <= 2 + 2 * L[n - 1])return 1 + P[n - 1] + dfs(x - 2 - L[n - 1],n-1);
	else return 2 * P[n - 1] + 1;
}
int main() {
	ll N, X;
	cin >> N >> X;
	P[0] = 1;
	L[0] = 1;
	for (int i = 0; i < N; ++i) {
		P[i + 1] = 2 * P[i] + 1;
		L[i + 1] = 2 * L[i] + 3;
	}
	cout << dfs(X, N) << endl;
	return 0;
}
