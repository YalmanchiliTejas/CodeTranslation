#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//const ll p = 1e9 + 7;
	//const ll p = 998244353;

	ll h, w;
	cin >> h >> w;
	vector<string> grid(h);
	for (ll i = 0; i < h; i++) cin >> grid[i];

	bool flag = true;
	for (ll i = 0; i < h - 1; i++) {
		for (ll j = 0; j < w - 1; j++) {
			if (grid[i][j] == '.') continue;
			if ((grid[i + 1][j] ^ grid[i][j + 1]) == 0) flag = false;
		}
	}
	for (ll i = 0; i < h - 1; i++) {
		ll j = w - 1;
		if (grid[i][j] == '#' && grid[i + 1][j] == '.') flag = false;
	}
	for (ll j = 0; j < w - 1; j++) {
		ll i = h - 1;
		if (grid[i][j] == '#' && grid[i][j + 1] == '.') flag = false;
	}

	for (ll i = 1; i < h; i++) {
		for (ll j = 1; j < w; j++) {
			if (grid[i][j] == '.') continue;
			if ((grid[i - 1][j] ^ grid[i][j - 1]) == 0) flag = false;
		}
	}
	for (ll i = 1; i < h; i++) {
		ll j = 0;
		if (grid[i][j] == '#' && grid[i - 1][j] == '.') flag = false;
	}
	for (ll j = 1; j < w; j++) {
		ll i = 0;
		if (grid[i][j] == '#' && grid[i][j - 1] == '.') flag = false;
	}

	if (flag) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}
