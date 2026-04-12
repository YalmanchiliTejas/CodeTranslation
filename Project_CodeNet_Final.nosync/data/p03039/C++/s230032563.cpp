#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

#define REP(i, n) for(ll i = 0;i < n;i++)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define FORR(i, m, n) for(ll i = m;i >= n;i--)
#define REPO(i, n) for(ll i = 1;i <= n;i++)
#define ll long long
#define INF (ll)1 << 60
#define MINF (-1 * INF)
#define ALL(n) n.begin(),n.end()
#define MOD (ll)1000000007
#define P pair<ll, ll>

ll powmod(ll a, ll b) {
	a %= MOD;
	ll res = 1;
	while (b > 0) {
		if (b % 2 == 1)res = res * a % MOD;
		a = a * a % MOD;
		b /= 2;
	}
	return res;
}

ll f[210000];
void cominit() {
	f[0] = 1;
	REP(i, 200000)f[i + 1] = f[i] * (i + 1) % MOD;
}

ll com(ll n, ll r) {
	return f[n] * powmod(f[r] * f[n - r], MOD - 2) % MOD;
}

ll perm(ll n, ll r) {
	return f[n] * powmod(f[n - r], MOD - 2) % MOD;
}

ll n, m, k, nans, mans, cnt;
int main() {
	cin >> n >> m >> k;
	cominit();
	cnt = com(n * m - 2, k - 2);
	REPO(i, n - 1) {
		nans += i * cnt % MOD * m * m % MOD * (n - i) % MOD;
		nans %= MOD;
	}
	REPO(i, m - 1) {
		mans += i * cnt * n * n % MOD * (m - i) % MOD;
		mans %= MOD;
	}
	cout << (nans + mans) % MOD << endl;
}