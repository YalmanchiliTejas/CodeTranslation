#include<iostream>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
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
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<bitset>
#include<functional>
#include<iterator>
#include<complex>
#include<fstream>
#include<random>
#include<ctype.h>
#include<stdio.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using PII = pair<ll, ll>;
using piii = pair<pii, pii>;
using Pi = pair<int, pii>;
using Graph = vector<vector<int>>;
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };
bool check(int x, int y) {
	if (0 <= x && x<55 && 0 <= y && y<55)return true;
	else return false;
}
const ll INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
using Graph = vector<vector<int>>;

//iの逆元mod inf
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
const double PI = 3.14159265358979323846;
const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];
//テーブルをつくる前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;//mod pにおける1,2,,,nの逆元
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
double Euclidean_distance(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

//素因数分解
map<int, int>prime_factor(int n) {
	map<int, int>res;
	for (int i = 2; i*i <= n; ++i) {
		while (n%i == 0) {
			++res[i];
			n /= i;
		}
	}
	if (n != 1)res[n] = 1;
	return res;
}


ll powmod(ll a, ll k, ll mod) {
	ll ap = a, ans = 1;
	while (k) {
		if (k & 1) {
			ans *= ap;
			ans %= mod;
		}
		ap = ap * ap;
		ap %= mod;
		k >>= 1;
	}
	return ans;
}
ll invi(ll a, ll mod) {
	return powmod(a, mod - 2, mod);
}
#define PI 3.14159265358979323846  // 円周率
//逆元Aを足したときのmodで割った余りは
//+=invi(A)
//Yで割ることはY^(10^9+7)-2を掛けることは同値
///////////////////////////////////////

int main() {
	int x; cin >> x;
	if (x >= 30) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
