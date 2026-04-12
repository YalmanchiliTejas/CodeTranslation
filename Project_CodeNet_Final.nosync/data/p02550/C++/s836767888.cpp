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

const int M = 2e5 + 25, lgn = 40;
ll is[lgn][M];
ll sum[lgn][M];

signed main() {
	EmiliaMyWife

	ll n, x, m;
	cin >> n >> x >> m;
	for(ll i = 0; i < m; i++)
		is[0][i] = sum[0][i] = i * i % m;
	for(int j = 1; j < lgn; j++) {
		for(int i = 0; i < m; i++) {
			sum[j][i] = sum[j - 1][i] + sum[j - 1][is[j - 1][i]];
			is[j][i] = is[j - 1][is[j - 1][i]];
		}
	}
	ll res = x;
	ll ans = x;
	n--;
	for(int i = 0; i < lgn; i++)
		if((1LL << i) & n)
			ans += sum[i][res], res = is[i][res];//, cout << ans << ' ' << res << '\n';
	cout << ans << '\n';

	return 0;
}
