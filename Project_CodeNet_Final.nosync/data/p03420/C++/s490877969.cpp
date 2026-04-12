#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	i64 ans = 0;

	for (int b = k + 1; b <= n; b++)
	{
		int sz = n / b;
		int r = n % b;

		if (r > 0 && r >= k)
		{
			ans += r - k + 1;
			if (k == 0)
				ans--;
		}

		ans += sz * (b - k);
	}

	printf("%lld\n", ans);

	return 0;
}