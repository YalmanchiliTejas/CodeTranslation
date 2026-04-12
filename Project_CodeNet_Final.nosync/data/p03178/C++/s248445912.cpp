#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#ifndef ULLONG
typedef unsigned long long ULLONG;
#endif
#ifndef LLONG
typedef long long LLONG;
#endif
template <class _Ty> static _Ty tp_abs(const _Ty& a) {
	return ((a < 0) ? (a * -1) : a);
}
template <class _Ty> static _Ty tp_min(_Ty a, _Ty b) {
	return a < b ? a : b;
}
template <class _Ty> static _Ty tp_max(_Ty a, _Ty b) {
	return a > b ? a : b;
}
template<class T> static void getint(T& a) {
	const char* fmt = " %d";
	if (sizeof(T) == sizeof(long long)) {
		fmt = " %lld";
	}

	if (scanf(fmt, &a) < 0) {
		printf("g1int Error\n");
	}
}
template<class T> static void getint(T& a, T& b) {
	const char* fmt = " %d %d";
	if (sizeof(T) == sizeof(long long)) {
		fmt = " %lld %lld";
	}

	if (scanf(fmt, &a, &b) < 0) {
		printf("g2int Error\n");
	}
}
template<class T> static void getint(T& a, T& b, T& c) {
	const char* fmt = " %d %d %d";
	if (sizeof(T) == sizeof(long long)) {
		fmt = " %lld %lld %lld";
	}

	if (scanf(fmt, &a, &b, &c) < 0) {
		printf("g3int Error\n");
	}
}
static void getstring(char* buff) {
	if (scanf(" %s", buff) < 0) {
		printf("getstr error!\n");
	}
}

static const int EduDp_INF = 1100000000;
static const int MOD_NUM = 1000000007;
static void S_task();

#if 1
int main()
{
	S_task();
	fflush(stdout);
	return 0;
}
#endif

static void S_task()
{
	std::string orgs;
	std::cin >> orgs;

	int D;
	getint(D);

	int digitCount = orgs.length();
	std::vector<std::vector<std::vector<LLONG>>> dp(digitCount + 1, std::vector<std::vector<LLONG>>(2, std::vector<LLONG>(D, 0)));
	dp[0][0][0] = 1;
	for (int digit = 1; digit <= digitCount; digit++) {
		int digitNum = orgs[digit - 1] - '0';

		for (int sml = 0; sml < 2; sml++) {
			int limit = (sml ? 9 : digitNum);

			for (int d = 0; d < D; d++) {
				for (int k = 0; k <= limit; k++) {
					int nowSurp = (d + k) % D;
					dp[digit][sml || k < digitNum][nowSurp] += dp[digit - 1][sml][d] % (LLONG)MOD_NUM;
					dp[digit][sml || k < digitNum][nowSurp] %= (LLONG)MOD_NUM;
				}
			}
		}
	}
	printf("%lld\n", (dp[digitCount][0][0] + dp[digitCount][1][0] + (LLONG)MOD_NUM - 1LL) % (LLONG)MOD_NUM);
}
