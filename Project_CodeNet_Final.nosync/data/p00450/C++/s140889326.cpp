#include<bits/stdc++.h>
#define rep(i, x) for(ll i = 0; i < x; i++)
#define rep2(i, x) for(ll i = 1; i <= x; i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ld pi = 3.141592653589793238;

ll color[12345678], ko[12345678];
signed main() {
	while (true) {
		ll n, a; cin >> n;
		if (n == 0) { break; }
		ll saigo = 0, z = 0;
		rep(i, n) {
			cin >> a; a += 2;
			if (i == 0) { color[z] = a; ko[z] = 1; z++; }
			else if (i % 2 == 0) {
				if (saigo == a) { ko[z - 1]++; }
				else { color[z] = a; ko[z] = 1; z++; }
			}
			else {
				if (saigo == a) { ko[z - 1]++; }
				else {
					if (z == 1) {
						color[z - 1] = a; ko[z - 1]++;

					}
					else {
						ko[z - 2] += 1 + ko[z - 1];
						color[z - 1] = 0; ko[z - 1] = 0; z--;
					}
				}
			}
			saigo = a;
		}
		ll ans = 0;
		rep(i, z) {
			//cout << color[i] << ' ' << ko[i] << endl;
			if (color[i] == 2) { ans += ko[i]; }
		}
		cout << ans << endl;
	}
	return 0;
}
