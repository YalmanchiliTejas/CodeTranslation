#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;
const int MOD = 1000000007;
#define MAX_N (110)

static ll heights[MAX_N], patties[MAX_N];

static ll f(int N, ll X)
{
	ll ret;
	if (N == 0)
		ret = 1;
	else if (X <= 1)
		ret = 0;
	else if (X <= 1 + heights[N - 1])
		ret = f(N - 1, X - 1);
	else if (X == 2 + heights[N - 1])
		ret = patties[N - 1] + 1;
	else if (X <= 2 + 2 * heights[N - 1])
		ret = f(N - 1, X - heights[N - 1] - 2) + patties[N - 1] + 1;
	else
		ret = patties[N];
	return ret;
}

int main()
{
	int N;
	ll X;
	scanf("%d%lld", &N, &X);

	heights[0] = 1;
	patties[0] = 1;
	for (int i = 1; i <= N; i++) {
		heights[i] = heights[i - 1] * 2 + 3;
		patties[i] = patties[i - 1] * 2 + 1;
	}
	printf("%lld\n", f(N, X));

	return 0;
}
