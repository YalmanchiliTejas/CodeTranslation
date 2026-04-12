/*
--------------              |   /
      |                     |  /
      |                     | /
      |             *       |/          |    |         ------            *
      |                     |           |    |        /      \
      |             |       |\          |    |       |       |\          |
   \  |             |       | \         |    |       |       | \         |
    \ |             |       |  \        |    |        \     /   \        |
     V              |       |   \        \__/|         -----     \       |
*/
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);
#define mem(i,j) memset(i,j,sizeof (i));
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
/*-----------------------------------------------------------------------------------------------------*/

signed main() {
	EmiliaMyWife

	int n;
	cin >> n;
	vector<ll> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	ll ans = 0;
	for(ll i = 0, s = 0; i < n; i++) {
		ans = (ans + s * arr[i]) % MOD;
		s += arr[i];
		s %= MOD;
	}
	cout << ans << '\n';

	return 0;
}
