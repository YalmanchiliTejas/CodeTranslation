/*DavitMarg*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <stack>
#include <cassert>
#include <iterator>
#include <ctype.h>
#include <fstream>
#include <unordered_map>
#define mod 1000000007ll
#define LL long long
#define LD long double
#define MP make_pair
#define PB push_back
#define all(v) v.begin(),v.end()
using namespace std;

LL n, a[3005], dp[3005][3005],sum;

void dfs(LL l, LL r)
{
	if (dp[l][r] != -1)
		return;
	if (l == r)
	{
		dp[l][r] = a[l];
		return;
	}
	else if (l + 1 == r)
	{
		dp[l][r] = max(a[l], a[r]);
		return;
	}

	dfs(l + 1, r);
	dfs(l + 2, r);
	dfs(l + 1, r - 1);
	dp[l][r] = a[l] + min(dp[l + 2][r], dp[l + 1][r - 1]);

	dfs(l, r-1);
	dfs(l, r - 2);
	dfs(l + 1, r - 1);
	dp[l][r] = max(a[r] + min(dp[l][r - 2], dp[l + 1][r - 1]),dp[l][r]);
	
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", a + i);
		sum += a[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = -1;
	dfs(1,n);
	cout << dp[1][n] * 2 - sum << endl;
	return 0;
}
/*

*/