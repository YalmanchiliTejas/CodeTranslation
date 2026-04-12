
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#ifndef ULLONG
typedef unsigned long long ULLONG;
#endif
#ifndef LLONG
typedef long long LLONG;
#endif
template <class _T> static _T tp_min(_T a, _T b) {
	return a < b ? a : b;
}
template <class _T> static _T tp_abs(const _T& a) {
	//	usage:  tp_abs<type name>(a);
	return ((a < 0) ? (a * -1) : a);
}

static const ULLONG UL_HUGE_DIVIDER = 1000000007LLU;
static const LLONG LL_HUGE_DIVIDER = 1000000007LL;

//static void ABC111D_RobotArms();
static void ABC114A_753();

#if 1
int main()
{
	//ABC111D_RobotArms();
	ABC114A_753();
	fflush(stdout);
	return 0;
}
#endif

static void ABC114A_753()
{
	int X;
	scanf(" %d", &X);

	const char *ans = "NO\n";
	switch (X) {
	case 3:
	case 5:
	case 7:
		ans = "YES\n";
		break;
	default:
		break;
	}
	printf(ans);
}
