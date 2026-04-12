#include <bits/stdc++.h>
#include <vector>
#include <queue>
 
using namespace std;
typedef long long int64;
 
const int P = 998244353;
const int MAXN = 3011;
int dp[MAXN];
int n, s, ans;
 
inline int add(int x, int y) { x += y; x -= x >= P ? P : 0; return x; }
inline int mul(int x, int y) { return 1ll * x * y % P; }
inline void incr(int& x,int y) { x = add(x, y); }
 
int main(void)
{
	cin >> n >> s;
	for (int i = 1;i <= n; ++i)
	{
		int v;
		cin >> v;
		for (int j = s - v; j >= 0; --j)
			incr(dp[j + v], dp[j]);
		incr(dp[v], i);
		incr(ans, dp[s]);
	}
	cout << ans << '\n';
	return 0;
}