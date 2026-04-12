#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define f first
#define s second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define debug(x) cout << #x << ":\t" << x << endl
#define _ << " " <<

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

const ll N = 3e3 + 3;

ll n, a[N];
ll mx[N][N], mn[N][N];

void show() {
	for (ll i = 1; i <= n; ++i) {
		for (ll j = 1; j <= n; ++j) cout << mx[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (ll i = 1; i <= n; ++i) {
		for (ll j = 1; j <= n; ++j) cout << mx[i][j] << " ";
		cout << endl;
	}
}

int main() {
//	mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
//	freopen("in", "r", stdin)
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (ll i = 1; i <= n; ++i) cin >> a[i];
	
	for (ll i = 1; i <= n; ++i) {
		mx[1][i] = a[i];
		mx[2][i] = max(a[i], a[i-1]);
		mn[2][i] = min(a[i], a[i-1]);
	}
	mx[2][1] = mn[2][1] = 0;
	
	for (ll i = 3; i <= n; ++i) {
		for (ll j = i; j <= n; ++j) {
			ll x1 = a[j] + mn[i-1][j-1], y1 = mx[i-1][j-1];
			ll x2 = a[j - i + 1] + mn[i-1][j], y2 = mx[i-1][j];
			if (x1 < x2) {
				swap(x1, x2);
				swap(y1, y2);
			}
			mx[i][j] = x1;
			mn[i][j] = y1;
		}
	}
	cout << mx[n][n] - mn[n][n] << "\n";
	
	return 0;
}
