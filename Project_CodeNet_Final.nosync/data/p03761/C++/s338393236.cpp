#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
const long long MOD = 1000000007;
using namespace std;
typedef long long ll;

map<ll, int> mp;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<string> s(n);
	vector<vector<int>> a(n, vector<int>(26, 0));
	rep(i, n) {
		cin >> s.at(i);
		rep(j, s.at(i).size()) {
			a.at(i).at(s.at(i).at(j) - 'a')++;
		}
	}
	string ans = "";
	rep(i, 26) {
		int m = INT_MAX;
		rep(j, n) {
			m = min(m, a.at(j).at(i));
		}
		rep(j, m) {
			char c = 'a' + i;
			ans += c;
		}
	}
	cout << ans << endl;
	return 0;
}