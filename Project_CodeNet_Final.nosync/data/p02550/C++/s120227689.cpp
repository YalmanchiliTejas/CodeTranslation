#include "bits/stdc++.h"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using ll = long long int;

ll mpow(ll a, ll n, ll mod)
{
	ll r = 1;
	while (n) {
		if (n&1) r = r*a%mod;
		a = a*a%mod;
		n >>= 1;
	}
	return r;
}

ll sum[100001][40];
int link[100001][40];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	ll n, x, m; cin >> n >> x >> m;
	const int LOGN = 40;
	for (int i = 0; i < m; ++i) {
		sum[i][0] = i;
		link[i][0] = (1LL*i*i)%m;
	}
	for (int level = 1; level < LOGN; ++level) {
		for (int i = 0; i < m; ++i) {
			link[i][level] = link[link[i][level-1]][level-1];
			sum[i][level] = sum[i][level-1] + sum[link[i][level-1]][level-1];
		}
	}
	ll ans = 0;
	int node = x;
	for (int bit = LOGN-1; bit >= 0; --bit) {
		if ((n>>bit)&1) {
			ans += sum[node][bit];
			node = link[node][bit];
		}
	}
	cout << ans;
}