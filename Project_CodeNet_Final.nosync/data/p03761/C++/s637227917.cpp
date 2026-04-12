#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>

using namespace std;
typedef long long ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)
#define repe(i,s,n)for(ll i = s;i<=n;i++)

int main() {
	ll n; cin >> n;
	string s[50];
	ll c[26] = {};
	rep(i, 0, 26)c[i] = 1 << 29;
	rep(i, 0, n) {
		cin >> s[i];
		ll b[26] = {};
		rep(j, 0, s[i].size()) {
			b[s[i][j] - 'a']++;
		}
		rep(j, 0, 26) {
			c[j] = min(c[j], b[j]);
		}
	}
	rep(i, 0, 26) {
		rep(k, 0, c[i])cout << (char)(i + 'a');
	}
	cout << endl;
	return 0;
}