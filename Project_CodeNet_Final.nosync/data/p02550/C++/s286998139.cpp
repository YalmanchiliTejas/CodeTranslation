#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

ll pow_mod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) res = res * x % mod;
	return res;
}

ll gcd(ll x, ll y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

int main() {
	ll n;
	int x, m;
	cin >> n >> x >> m;
	vector<int> id(m, -1);
	vector<int> a;
	int len = 0;
	ll total = 0;
	while (id[x] == -1) {
		a.push_back(x);
		len++;
		id[x] = len;
		total += x;
		x = (ll)x * x % m;
	}
	ll ans = 0;
	if (n < len) {
		for (int i = 0; i < n; i++) ans += a[i];
	}
	else {
		ans += total;
		n -= len;
		int c_len = len - id[x] + 1;
		ll c_total = 0;
		for (int i = id[x]; i <= len; i++) c_total += a[i - 1];
		ans += (n / c_len) * c_total;
		n %= c_len;
		for (int i = 0; i < n; i++) ans += a[id[x] + i - 1];
	}
	cout << ans << endl;
	return 0;
}