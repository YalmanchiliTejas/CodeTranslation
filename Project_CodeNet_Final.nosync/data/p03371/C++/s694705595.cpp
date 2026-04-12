
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

#ifndef U_L_LONG
typedef unsigned long long ULLONG;
#endif
#ifndef L_LONG
typedef long long LLONG;
#endif
template <class _T> static _T tp_abs(const _T& a) {
	//	usage:  tp_abs<type name>(a);
	return ((a < 0) ? (a * -1) : a);
}
template <class _T> static _T tp_min(_T a, _T b) {
	return a < b ? a : b;
}
template <class _T> static _T tp_max(_T a, _T b) {
	return a > b ? a : b;
}
template<class _T> static void get1int(_T& a) {
	const char* fmt = " %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld";
	}

	if (scanf(fmt, &a) < 0) {
		printf("g1int Error\n");
	}
}
template<class _T> static void get2int(_T& a, _T& b) {
	const char* fmt = " %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld";
	}

	if (scanf(fmt, &a, &b) < 0) {
		printf("g2int Error\n");
	}
}
template<class _T> static void get3int(_T& a, _T& b, _T& c) {
	const char* fmt = " %d %d %d";
	if (sizeof(_T) == sizeof(long long)) {
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

static void ABC095C_HalfandHalf();

#if 1
int main()
{
	ABC095C_HalfandHalf();
	fflush(stdout);
	return 0;
}
#endif

static void ABC095C_HalfandHalf()
{
	int A, B, C, X, Y;
	get3int(A, B, C);
	get2int(X, Y);

	//	全部ハーフでそろえるとき
	int count = tp_max(X, Y) * 2;
	int AllHalfV = count * C;

	//	全部 それぞれで買うとき
	int AllEachV = A * X + B * Y;

	//	共通部分をハーフで買って，あまりはそれぞれ買い足すとき
	int halfV = tp_min(X, Y) * 2 * C;
	//	足りない分を単体で買い足す
	int rest;
	if (X > Y) {
		rest = (X - Y) * A;
	}
	else {
		rest = (Y - X) * B;
	}
	int halfEachV = halfV + rest;
	
	printf("%d\n", std::min({ AllHalfV, AllEachV, halfEachV }));

}
