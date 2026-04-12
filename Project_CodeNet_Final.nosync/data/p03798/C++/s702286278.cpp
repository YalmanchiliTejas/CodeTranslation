#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)

bool a[100005] = {};
bool b[4][100005] = {};
int main() {
	ll n; string s; cin >> n >> s;

	rep(i, 0, s.size())	a[i] = ((s[i] == 'o') ? true : false);
	a[n] = a[0];
	a[n + 1] = a[1];

	b[0][0] = 1; b[0][1] = 1; // SS
	b[1][0] = 1; b[1][1] = 0; // SW
	b[2][0] = 0; b[2][1] = 1; // WS
	b[3][0] = 0; b[3][1] = 0; // WW
	rep(i, 0, 4) {
		rep(j, 1, n + 2) {
			if (b[i][j]) {
				if (a[j]) b[i][j + 1] = b[i][j - 1];
				else  b[i][j + 1] = !b[i][j - 1];
			}
			else {
				if (a[j]) b[i][j + 1] = !b[i][j - 1];
				else  b[i][j + 1] = b[i][j - 1];
			}
		}

		if (b[i][n] == b[i][0] && b[i][n + 1] == b[i][1]) {
			rep(j, 0, n) cout << (b[i][j] ? 'S' : 'W');
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;

	return 0;
}