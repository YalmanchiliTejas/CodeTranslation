#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <list>
#include <functional>
#include <numeric>
#include <iostream>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); ++i)

int main() {

	ll N, K;

	scanf("%lld %lld", &N, &K);

	ll sum = 0;

	rep(i, N) {
		sum += max(0ll, (N + 1) / (i + 1) * max(0ll, i + 1 - K) + max(0ll, (N % (i + 1) == i) ? 0ll : N % (i + 1) - K + 1) - (K ? 0 : 1));
	}


	printf("%lld\n", sum);

	return 0;
}
