
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

using ll = long long;

ll chart[234][234];
ll INF = 1234567890123456;
ll memo[456][234][234];
ll h, w;
ll dp(int d, int i, int j)
{
	if (i < 0 || i > d || j < 0 || j > d || d - i >= w || d - j >= w || i >= h || j >= h)return -INF;
	if (memo[d][i][j] != -1)return memo[d][i][j];
	ll score = chart[i][d - i];
	if (i != j)
	{
		score += chart[j][d - j];
	}
	ll ans = 0;
	for (int bit = 0; bit < 4; ++bit)
	{
		ans = max(ans, dp(d - 1, i - (bit % 2), j - (bit / 2)));
	}
	return memo[d][i][j] = ans + score;
}

int main(void)
{
	memset(memo, 0xff, sizeof(memo));
	scanf("%lld %lld", &h, &w);
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			scanf("%lld", &chart[i][j]);
		}
	}
	memo[0][0][0] = chart[0][0];
	printf("%lld\n", dp(h + w - 2, h - 1, h - 1));
	return 0;
}
