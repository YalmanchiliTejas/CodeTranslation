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
#define lowbit(x) ((x)&(-(x)))
#define siz(v) (long long)(v).size()
typedef int64_t ll;
typedef uint64_t ull;
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
/*-----------------------------------------------------------------------------------------------------*/

vector<int> edge[10];

int solve(int now, int has, int goal) {
	//cout << now << ' ';
	if(has == goal)
		return 1;//cout << '\n', 1;
	int res = 0;
	for(int &a : edge[now]) {
		if((has>>a)&1)
			continue;
		res += solve(a, has|(1<<a), goal);
	}
	return res;
}

signed main() {
	EmiliaMyWife

	int n, m;
	cin >> n >> m;
	for(int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	cout << solve(0, 1, (1<<n)-1);

	return 0;
}
