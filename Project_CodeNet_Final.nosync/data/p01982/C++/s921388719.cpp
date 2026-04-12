#include "bits/stdc++.h"

#define REP(i, n ,N) for(ll i = (n); i < (N); i++)
#define p(s) cout<<(s)<<endl
#define p2(a, b) cout<<(a)<<" "<<(b)<<endl
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
ll inf = 1e18;

ll n, l, r;
ll a[55];
int main() {
	while (cin >> n >> l >> r && n > 0) {
		REP(i, 0, n) {
			cin >> a[i];
		}
		ll ans = 0;
		REP(x, l, r + 1) {
			bool ok = false;
			REP(i,0,n) {
				if (x % a[i] == 0) {
					ok = true;
					if (i % 2 == 0) {
						ans++;
					}
					break;
				}
			}
			if (!ok && n % 2 == 0) {
				ans++;
			}
		}
		p(ans);
	}

	return 0;
}
