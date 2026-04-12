#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <sstream>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <functional>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
	vector<vector<ll> > dp(n, vector<ll>(n));
	for (int i = n - 1; i >= 0; --i)
		for (int j = i; j < n; ++j) {
			if (i == j)
				dp[i][j] = v[i];
			else
				dp[i][j] = max(-dp[i + 1][j] + v[i], -dp[i][j - 1] + v[j]);
		}
	printf("%lld\n", dp[0][n - 1]);
	return 0;
}