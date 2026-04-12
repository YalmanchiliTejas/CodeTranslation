#include<bits/stdc++.h>
#define rep(i, x) for(ll i = 0; i < x; i++)
using ll = long long;
using ld = long double;
using namespace std;

signed main() {
	ll n, k; string s; cin >> n >> s >> k;
	rep(i, n) {
		if (s[i] != s[k - 1]) { s[i] = '*'; }
	}
	cout << s << endl;
	return 0;
}