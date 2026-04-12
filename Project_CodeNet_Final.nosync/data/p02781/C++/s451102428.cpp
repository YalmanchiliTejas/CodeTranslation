
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007;

template<class _T> static void getint(_T& a) {
	const char* fmt = " %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld";
	}

	if (scanf(fmt, &a) < 0) {
		printf("g1int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b) {
	const char* fmt = " %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld";
	}

	if (scanf(fmt, &a, &b) < 0) {
		printf("g2int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	const char* fmt = " %d %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld %lld";
	}

	if (scanf(fmt, &a, &b, &c) < 0) {
		printf("g3int Error\n");
	}
}

static void ABC154E();

#if 1
int main()
{
	ABC154E();
	fflush(stdout);
	return 0;
}
#endif

static void ABC154E()
{
	std::string orgs;
	std::cin >> orgs;

	int digitCount = orgs.size();
	int K;
	getint(K);
	
	std::vector<std::vector<std::vector<LLONG>>> dp(digitCount + 1, std::vector<std::vector<LLONG>>(2, std::vector<LLONG>(K + 2, 0)));
	dp[0][0][0] = 1;
	for (int digit = 1; digit <= digitCount; digit++) {
		int num = orgs[digit - 1] - '0';

		for (int smaller = 0; smaller < 2; smaller++) {
			int count = 9;
			if (!smaller) {
				count = num;
			}
			for (int n = 0; n <= count; n++) {
				for (int k = 0; k <= K; k++) {
					if (n == 0) {
						dp[digit][smaller || (n < num)][k] += dp[digit - 1][smaller][k];
					}
					else {
						dp[digit][smaller || (n < num)][k + 1] += dp[digit - 1][smaller][k];
					}
				}
			}
		}
	}
	printf("%lld\n", dp[digitCount][0][K] + dp[digitCount][1][K]);
}

