
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
	std::cin >> a;
}
template<class _T> static void getint(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template <class _T> static _T tp_abs(_T a) {
	if (a < (_T)0) {
		a *= (_T)-1;
	}
	return a;
}

static void solve();

int main()
{
	solve();
	fflush(stdout);
	return 0;
}

static void solve()
{
	int N;
	getint(N);

	std::vector<LLONG> ai(N), bi(N), ci(N);
	for (int i = 0; i < N; i++) {
		getint(ai[i]);
	}
	std::sort(ai.begin(), ai.end());

	int start = 0;
	int end = N - 1;
	int bidx = 1, cidx = 1;
	while ((start <= end) && (bidx < N)) {
		bi[bidx++] = ai[start];
		if (bidx < N) {
			bi[bidx++] = ai[end];
		}
		ci[cidx++] = ai[end];
		if (cidx < N) {
			ci[cidx++] = ai[start];
		}
		end--;
		start++;
	}
	bi[0] = ai[start];
	ci[0] = ai[start];
	LLONG bsum = 0, csum = 0;
	for (int i = 1; i < N; i++) {
		bsum += tp_abs(bi[i] - bi[i - 1]);
		csum += tp_abs(ci[i] - ci[i - 1]);
	}
	printf("%lld\n", std::max(bsum, csum));
}
