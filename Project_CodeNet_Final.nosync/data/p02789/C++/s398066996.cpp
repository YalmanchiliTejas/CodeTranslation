#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
//typedef pair<ll, P> T;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define revrep(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define f first
#define s second
#define pb push_back

ll mod = 1000000007;
const ll INF = 100000000000010000;
//const ull B = 998244353;

//ll bit[200010];
//ll kai[3010];

//void pres(double A, ll x = 20) { printf("%.20f\n", x); }

/*ll sum(ll i)
{
	i += 1;
	ll t = 0;
	while (i > 0)
	{
		t = max(t, bit[i]);
		i -= i & -i;
	}
	return t;
}

void update(ll i, ll x)
{
	i += 1;
	while (i <= 200005)
	{
		bit[i] = max(x, bit[i]);
		i += i & -i;
	}
}*/

/*`ll SAIKI(ll S) {
	for (ll T = S; ; T = (T - 1) & S) {

	}
}*/

void test() {
	cout << "888888888888888888888888" << endl;
}

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

ll pow_mod(ll x, ll y) {
	if (y == 0) return 1;
	if (y % 2 == 1) {
		return x * pow_mod(x, y - 1) % mod;
	}
	else {
		ll half = pow_mod(x, y / 2);
		return half * half % mod;
	}
}

ll div_mod(ll x) {
	return pow_mod(x, mod - 2);
}

/*ll com(ll x, ll y) {
	return kai[x] * div_mod(kai[y] * kai[x - y] % mod) % mod;
	//毎回オーダーlog(n)かかる
}

void kaijo() {
	kai[0] = 1;
	for (ll i = 1; i <= 3004; i++) {
		kai[i] = kai[i - 1] * i % mod;
	}
}*/

ll N, M;

void solve() {
	cin >> N >> M;
	if (N == M) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	ll N;
	cin >> N;
}