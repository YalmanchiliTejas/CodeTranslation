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
#define int ll

int cnt[51], pcnt[51];
int solve(int n, int x) {
	if(n==0)
		return (x==1);
	if(x == 1)
		return 0;
	if(x <= 1+cnt[n-1])
		return solve(n-1, x-1);
	if(x == 2+cnt[n-1])
		return pcnt[n-1]+1;
	if(x < cnt[n])
		return solve(n-1, x-cnt[n-1]-2)+1+pcnt[n-1];
	return pcnt[n];
}

signed main() {
	EmiliaMyWife

	int n, x;
	cin >> n >> x;
	pcnt[0] = cnt[0] = 1;
	for(int i = 1; i <= n; i++)
		pcnt[i] = pcnt[i-1]*2 + 1, cnt[i] = cnt[i-1]*2 + 3;
	cout << solve(n, x);

	return 0;
}
