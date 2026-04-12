#include <bits/stdc++.h>

using namespace std;

#define MAX_N 3005

int n, y[MAX_N];
long long ps[MAX_N], dp[MAX_N][MAX_N];

long long f_imp(int, int);

long long f(int fr, int to)
{
	if (dp[fr][to] == 0)
		dp[fr][to] = f_imp(fr, to) + 1;
	return dp[fr][to] - 1;
}

long long f_imp(int fr, int to)
{
	if (fr == to)
		return y[fr];
	return max(ps[to] - ps[fr] - f(fr + 1, to) + y[fr], ps[to - 1] - ps[fr - 1] - f(fr, to - 1) + y[to]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", y + i);
	}
	for (int i = 1; i <= n; i++)
	{
		ps[i] = ps[i - 1] + y[i];
	}
	long long x = f(1, n);
	long long y = ps[n] - ps[0] - x;
	printf("%lld\n", x - y);
}
