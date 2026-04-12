#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? (-(a)) : (a))

typedef long long ll;

using namespace std;

int N;

ll dp[200000 + 5][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	scanf("%d", &N);

	int temp;

	scanf("%d", &temp);
	
	dp[0][0] = 0;
	dp[0][1] = temp;

	scanf("%d", &temp);
	
	dp[1][0] = max(dp[0][1], 1LL * temp);
	dp[1][1] = 0;

	for (int i = 2; i < N; ++i)
	{
		scanf("%d", &temp);
		if (i % 2 == 0)
		{
			dp[i][0] = max(dp[i - 2][0] + temp, dp[i - 1][0]);
			dp[i][1] = dp[i - 2][1] + temp;
		}
		else
		{
			dp[i][0] = max(dp[i - 2][0] + temp, dp[i - 1][1]);
			dp[i][1] = 0;
		}
	}

	printf("%lld\n", dp[N - 1][0]);

	return 0;
}