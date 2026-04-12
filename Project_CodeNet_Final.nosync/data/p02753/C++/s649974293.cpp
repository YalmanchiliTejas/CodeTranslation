#include "bits/stdc++.h"
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const long long mod = 1e9 + 7;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

ll powMod(ll n, ll k, ll m) {
	if (k == 0) {
		return 1;
	} else if (k % 2 == 1) {
		return powMod(n, k - 1, m) * n % m;
	} else {
		ll t = powMod(n, k / 2, m);
		return t * t % m;
	}
}

int main() {
	string s;
	cin >> s;
	
	ll c=0;

	rep(i, 3) {
		if (s[i] == 'A') {
			c++;
		}
	}

	if (c == 3 || c == 0) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}
}