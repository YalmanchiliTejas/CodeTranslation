#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fsp(x) fixed << setprecision(x)
#define xout cerr
const ll inf = LLONG_MAX;
const long double pi = acosl(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//const ll p = 1e9 + 7;
	//const ll p = 998244353;

	ll n, m;
	cin >> n >> m;
	vector<vector<bool>> nx(n, vector<bool>(n, false));
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		nx[a][b] = true;
		nx[b][a] = true;
	}

	vector<ll> p(n);
	for (ll i = 0; i < n; i++) p[i] = i;
	ll ans = 0;
	do {
		if (p[0]) break;
		for (ll i = 0; i < n - 1; i++) {
			if (!nx[p[i]][p[i + 1]]) break;
			if (i == n - 2) ans++;
		}
	} while (next_permutation(all(p)));
	cout << ans << endl;
}
