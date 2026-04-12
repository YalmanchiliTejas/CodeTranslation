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
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define lowbit(x) ((x)&(-(x)))
#define siz(v) (long long)(v).size()
typedef int64_t ll;
typedef uint64_t ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
const int MAXN    = 2e5+9;
/*-----------------------------------------------------------------------------------------------------*/

signed main() {
	EmiliaMyWife

	string s;
	cin >> s;
	int cnt[2]={0, 0};
	for(int i = 0; i < s.size(); i++) {
		cnt[s[i]-'A']++;
	}
	cout << (cnt[0]&&cnt[1] ? "Yes": "No");

	return 0;
}
