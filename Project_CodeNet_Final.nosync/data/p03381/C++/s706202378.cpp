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

int N, X[212345], O[212345];

int main() {

	scanf("%d", &N);
	rep(i, N) scanf("%d", &X[i]);
	rep(i, N) O[i] = X[i];

	sort(O, O + N);
	int m = O[N / 2], n = O[N / 2 - 1];

	rep(i, N) {
		if (X[i] <= n) printf("%d\n", m);
		else/* if (X[i] >= n)*/ printf("%d\n", n);
	}

	return 0;
}
