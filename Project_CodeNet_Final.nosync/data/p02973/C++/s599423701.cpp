
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

static void ABC134E();

#if 1
int main()
{
	ABC134E();
	fflush(stdout);
	return 0;
}
#endif

static void ABC134E()
{
	int N;
	getint(N);

	std::vector<int> ai(N);
	for (int i = 0; i < N; i++) {
		getint(ai[i]);
	}
	
	std::multiset<int> colors;
	colors.insert(ai[0]);
	for (int i = 1; i < N; i++) {
		auto it = colors.lower_bound(ai[i]);
		if (it != colors.begin()) {
			colors.erase(--it);
		}
		colors.insert(ai[i]);
	}
	printf("%u\n", colors.size());
}
