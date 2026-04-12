#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)
#define repe(i,s,n)for(ll i = s;i<=n;i++)
int main() {
	ll min_c[26] = {};
	rep(i, 0, 26) {
		min_c[i] = 1 << 21;
	}

	ll n; cin >> n;
	rep(i, 0, n) {
		string s; cin >> s;

		ll c[26] = {};
		rep(j, 0, s.size()) {
			c[s[j] - 'a']++;
		}

		rep(j, 0, 26) {
			min_c[j] = min(c[j], min_c[j]);
		}
	}

	rep(i, 0, 26) {
		rep(j, 0, min_c[i]) {
			cout << (char)(i + 'a');
		}
	}
	cout << endl;

	return 0;
}