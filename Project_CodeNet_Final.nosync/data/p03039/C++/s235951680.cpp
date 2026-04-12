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
const ll dx[4] = { 0, -1, 1, 0 };
const ll dy[4] = { -1, 0, 0, 1 };
const int INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
///////////////////////////////////////
vector<pair<ll, ll>>prime_factorize(ll n) {
	vector<pair<ll, ll>>res;
	for (ll p = 2; p*p <= n; ++p) {
		if (n%p != 0)continue;
		int num = 0;
		while (n%p == 0) { ++num; n /= p; }
		res.push_back(make_pair(p, num));
	}
	if (n != 1)res.push_back(make_pair(n, 1));
	return res;
}
const int MAX = 210000;
ll fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; ++i) {
		fac[i] = fac[i - 1] * i%INF;
		inv[i] = INF - inv[INF%i] * (INF / i) % INF;
		finv[i] = finv[i - 1] * inv[i] % INF;
	}
}
ll COM(int n, int k) {
	if (n < k)return 0;
	if (n < 0 || k < 0)return 0;
	return fac[n] * (finv[k] * finv[n - k] % INF) % INF;
}
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	COMinit();
	ll ans = 0;
	for (ll d = 1; d <= N - 1; ++d) {
		ll key = d * (N - d)*M*M%INF;
		ans += key;
		ans %= INF;
	}
	for (ll d = 1; d <= M - 1; ++d) {
		ll key = d * (M - d)*N*N;
		ans += key;
		ans %= INF;
	}
	ll key2 = COM(N*M - 2, K - 2);
	ans *= key2;
	ans %= INF;
	cout << ans << endl;
	return 0;
}
