#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	vector<vector<ll>> v(26, vector<ll>(n, 0));
	for (ll i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (char c : s) {
			++v[c - 'a'][i];
		}
	}
	for (ll i = 0; i < 26; ++i) {
		ll a = *min_element(v[i].begin(), v[i].end());
		for (ll j = 0; j < a; ++j) {
			cout << (char)('a' + i);
		}
	}
	cout << endl;
}
