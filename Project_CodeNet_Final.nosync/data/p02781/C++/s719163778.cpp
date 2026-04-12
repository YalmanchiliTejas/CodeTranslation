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
#include <bitset>
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
//ll Cnt[10010];

//void pres(double A, ll x = 20) { printf("%.20f\n", x); }



/*ll sum(ll i)
{
	i += 1;
	ll t = 0;
	while (i > 0)
	{
		t += bit[i];
		i -= i & -i;
	}
	return t;
}

void add(ll i, ll x)
{
	i += 1;
	while (i <= 200005)
	{
		bit[i] += x;
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

ll pow_mod(ll x, ll k) {
	x %= mod;
	ll res = 1;
	while (k > 0) {
		if (k % 2) {
			res *= x; res %= mod;
		}
		x *= x; x %= mod;
		k /= 2;
	}
	return res;
}

ll div_mod(ll x) {
	return pow_mod(x, mod - 2);
}

//コンビネーション
const int MAXcomb = 1000010;
ll fac[MAXcomb], finv[MAXcomb], inv[MAXcomb];
//facはn!,finvは1/n!
//invは逆元
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAXcomb; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod%i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}
ll comb(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * finv[k] % mod * finv[n - k] % mod;
}


/*map<ll, ll> pres;
ll ct;

void makePrimeList(ll x) {
	ll X = x;
	for (ll j = 2; j * j <= x; j++) {
		ll cnt = 0;
		while (X % j == 0) {
			cnt++;
			X /= j;
		}
		if (cnt) {
			if (pres[j] == 0) {
				ct++;
				pres[j] = ct;
			}
			Cnt[pres[j]] += cnt;
		}
	}
	if (X != 1) {
		if (pres[X] == 0) {
			ct++;
			pres[X] = ct;
		}
		Cnt[pres[X]] += 1;
	}
}*/

ll dp[110][2][4];
string N;
ll K;

void solve() {
	cin >> N >> K;
	ll len = N.length();
	dp[0][0][0] = 1;
	rep(i, len)rep(j, 2)rep(k, 4) {
		if (N[i] == '0') dp[i + 1][j][k] += dp[i][j][k];
		else dp[i + 1][1][k] += dp[i][j][k];
		for (ll l = 1; l <= 9; l++) if (k != 3){
			if (l < N[i] - '0') dp[i + 1][1][k + 1] += dp[i][j][k];
			else if (l == N[i] - '0') dp[i + 1][j][k + 1] += dp[i][j][k];
			else if (j == 1) dp[i + 1][j][k + 1] += dp[i][j][k];
		}
	}
	cout << dp[len][0][K] + dp[len][1][K] << endl;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	ll N;
	cin >> N;
}