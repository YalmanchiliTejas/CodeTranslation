#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

int n;
int a, b, c, d;
int dp[1003][1003];
LL MOD = 1000000007;
LL ncr[1003][1003];
LL ifact[1003];

LL bigmod(LL a, LL n) {
	if (n == 0) return 1;
	LL x = bigmod(a, n / 2);
	x *= x;
	x %= MOD;
	if (n & 1) x = (x * a) % MOD;
	return x;
}

int DP(int n, int sz) {
	if (n == 0) return 1;
	if (sz > b) return 0;
	int &ret = dp[n][sz];

	if (ret != -1) return ret;

	ret = 0;
	ret = DP(n, sz + 1);
	if (sz * c > n) return ret;

	LL now = 1;
	for (int i = 1; i < c; i++) {
		now = (now * ncr[n - sz * (i - 1)][sz]) % MOD;
	}
	for (int i = c; i <= d; i++) {
		if (sz * i > n) break;
		now = (now * ncr[n - sz * (i - 1)][sz]) % MOD;
		LL z = (DP(n - sz * i, sz + 1) * now) % MOD;
		z = (z * ifact[i]) % MOD;
		ret += z;
		ret %= 1000000007;
	}
	return ret;
}

int main()
{
	ifact[0] = ifact[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		ifact[i] = (ifact[i - 1] * bigmod(i, MOD - 2)) % MOD;
	}
	ncr[0][0] = 1;
	int limncr = 1000;
	for (int i = 1; i <= limncr; i++)
		for (int j = 0; j <= limncr; j++)
		{
			if (j>i) ncr[i][j] = 0;
			else if (j == i || j == 0) ncr[i][j] = 1;
			else ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
		}

	scanf("%d", &n);
	scanf("%d %d %d %d", &a, &b, &c, &d);
	MEM(dp, -1);
	int ans = DP(n, a);
	printf("%d\n", ans);

	return 0;
}
