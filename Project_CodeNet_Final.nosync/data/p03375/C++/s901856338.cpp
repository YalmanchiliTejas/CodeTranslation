#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9)+7;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
ll dp[3001][3001] = {};
ll pas[3001][3001] = {};
ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x%mod;
		x = x * x%mod;
		n >>= 1;
	}
	return res;
}
int main() {
	ll n; ll m; cin >> n >> m;
	rep(i, 3001) {
		dp[i][0] = 1;
		Rep(j, 1, i) {
			dp[i][j] = (dp[i - 1][j - 1] + ((ll)(j+1))*dp[i - 1][j]%m) % m;
		}
		dp[i][i] = 1;
	}
	rep(i, 3001) {
		rep(j, 3001) {
			if (i == 0 || j == 0)pas[i][j] = 1;
			else pas[i][j] = (pas[i - 1][j] + pas[i][j - 1]) % m;
		}
	}
	ll sum = 0;
	for (ll i = 0; i <= n; i++) {
		ll csum = mod_pow((ll)2, n - i, (m-(ll)1));
		csum = mod_pow((ll)2, csum, m);
		csum = csum * pas[n - i][i] % m;
		ll nex = 0;
		for (ll j = 0; j <= i; j++) {
			ll ccsum = mod_pow((ll)2, (n - i)*j, m);
			ccsum = ccsum * dp[i][j] % m;
			nex = (nex + ccsum) % m;
		}
		csum = csum * nex%m;
		if ((int)i % 2==0) {
			sum = (sum + csum) % m;
		}
		else {
			sum = (sum - csum + m) % m;
		}
	}
	cout << sum << endl;
	return 0;
}