#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
#include <random>
#include <string.h>
#include <cmath>
#include <unordered_map>
#include <cstdio>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long ll;

ll gcd(ll x, ll y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y)*y;
}
ll kai(ll x, ll y, ll m) {
	ll res = 1;
	for (ll i = x - y + 1; i <= x; i++) {
		res *= i; res %= m;
	}
	return res;
}
ll mod_pow(ll x, ll y, ll m) {
	ll res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

ll comb(ll x, ll y, ll m) {
	if (y > x)return 0;
	return kai(x, y, m) * mod_pow(kai(y, y, m), m - 2, m) % m;
}

int n, a[100010];
vector<int> vec[100010];
map<pair<int, int>, ll> cum, cum2;
ll ans;

signed main() {
	std::random_device rnd;
	std::mt19937_64 mt(rnd());
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i; j < n; j += i)cum[make_pair(i, j)] = cum[make_pair(i, j - i)] + a[j];
		for (int j = n - 1; j >= 0; j -= i)cum2[make_pair(i, j)] = cum2[make_pair(i, j + i)] + a[j];
	}
	for (int i = 1; i <= n; i++)for (int j = i; j <= n; j += i)vec[j].push_back(i);
	for (int i = 1; i < n; i++) {
		int k = n - 1 - i;
		for (int j = 0; j < (int)vec[k].size(); j++) {
			if (i <= vec[k][j] || (i <= k && (k - i) % vec[k][j] == 0))continue;
			ans = max(ans, cum[make_pair(vec[k][j], k)] + cum2[make_pair(vec[k][j], i)]);
		}
	}
	cout << ans << endl;
}