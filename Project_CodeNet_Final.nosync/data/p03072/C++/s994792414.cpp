#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

const double PI = 3.1415926535897932384626433832795;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int gcd(int x, int y) { return y ? gcd(y, x % y) : abs(x); }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : abs(x); }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> h(n);
	for (auto &v : h) {
		cin >> v;
	}

	int ans = 1;
	int ma = h[0];
	for (int i = 1; i < n; i++) {
		if (ma <= h[i]) {
			ans++;

			ma = max(ma, h[i]);
		}
	}

	cout << ans << endl;
	return 0;
}
