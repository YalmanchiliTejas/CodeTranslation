
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007; //998244353;

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template <class _T> static _T tp_abs(_T a) {
	if (a < (_T)0) {
		a *= (_T)-1;
	}
	return a;
}

static void C();

int main()
{
	C();
	fflush(stdout);
	return 0;
}

static void C()
{
	int N;
	get(N);

	LLONG sum = 0;
	std::vector<LLONG> ai(N, 0);
	for (int i = 0; i < N; i++) {
		get(ai[i]);
		sum += ai[i];
		sum %= MOD_NUM;
	}

	LLONG ans = 0;
	LLONG nowSum = sum;
	for (int i = 0; i < N; i++) {
		nowSum = nowSum - ai[i];
		if (nowSum < 0) nowSum += MOD_NUM;
		ans += (ai[i] * nowSum) % MOD_NUM;
		ans %= MOD_NUM;
	}
	printf("%lld\n", ans);
}
