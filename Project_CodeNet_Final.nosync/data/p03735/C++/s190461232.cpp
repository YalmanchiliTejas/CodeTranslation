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

int n, p[200010];
pair<int,int> x[200010];
multiset<int> st1, st2;
ll ans = 1000000000000000000;

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i].first >> x[i].second;
		if (x[i].first > x[i].second)swap(x[i].first, x[i].second);
		st1.insert(x[i].first);
		st2.insert(x[i].second);
	}
	sort(x, x + n);
	for (int i = 0; i < n; i++) {
		ans = min(ans, (ll)(*st1.rbegin() - *st1.begin())*(*st2.rbegin() - *st2.begin()));
		st1.erase(st1.lower_bound(x[i].first));
		st1.insert(x[i].second);
		st2.erase(st2.lower_bound(x[i].second));
		st2.insert(x[i].first);
	}
	cout << ans << endl;
}
