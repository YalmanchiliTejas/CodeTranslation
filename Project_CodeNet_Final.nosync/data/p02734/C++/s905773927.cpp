#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <cmath>
#include <time.h>
#include <unordered_set>
#include <unordered_map>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define PI 3.14159265
#define RAND (rand()*rand())
#define MAX(x, y) ((x) > (y) ? (x):(y)) 
#define MIN(x, y) ((x) > (y) ? (y):(x))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define CEIL(x, y) (((x) + (y) - 1)/(y))
using namespace std;
const int MAXN = 1e5 + 5;
const ll MOD = 998244353LL;
const double eps = 1e-7;
int N, M, K, Q, T;
ll gcd(ll a, ll b) {
	if (b == 0LL) return a;
	return gcd(b, a % b);
}
int A[3010];
ll dp[3010][3010];

int main()
{
	int i, j;
	int S;
	scanf("%d%d", &N, &S);
	for (i = 1; i <= N; ++i) scanf("%d", &A[i]);
	for (i = 1; i <= N; ++i) {
		if (i == 1) {
			dp[i][A[i]]++;
			continue;
		}
		for (j = S; j >= 1; --j) {
			dp[i][j] = dp[i - 1][j];
			if (j - A[i] > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - A[i]]) % MOD;
		}
		dp[i][A[i]] = (dp[i][A[i]] + i) % MOD;
	}
	ll ans = 0LL;

	for (i = 1; i <= N; ++i) ans = (ans + dp[i][S]) % MOD;
	printf("%lld", ans);
	return 0;
}