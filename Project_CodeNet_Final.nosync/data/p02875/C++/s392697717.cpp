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
#include <fstream>
#include <unordered_map>

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
//#define MOD 1000000007
#define MOD 998244353
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
ll f[11100000];
void cominit() {
	f[0] = 1;
	REP(i, 11000000)f[i + 1] = f[i] * (i + 1) % MOD;
}

ll com(ll n, ll r) {
	if (n < r)return 0;
	if (n < 0 or r < 0)return 0;
	return f[n] * powmod(f[r] * f[n - r], MOD - 2) % MOD;
}

ll perm(ll n, ll r) {
	if (n < r)return 0;
	if (n < 0 or r < 0)return 0;
	return f[n] * powmod(f[n - r], MOD - 2) % MOD;
}
int main() {
	cominit();
	ll n, k;
	cin >> n;
	ll ans = powmod(3, n);
	FOR(i, n / 2 + 1, n + 1) {
		ll now = com(n, i) * powmod(2, n - i) % MOD * 2 % MOD;
		ans = (ans - now + MOD) % MOD;
	}
	cout << ans << endl;
}
