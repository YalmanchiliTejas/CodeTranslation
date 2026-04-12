#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N;
i64 A[55];

i64 rup(i64 a, i64 b)
{
	return a / b + (a % b ? 1 : 0);
}

bool check(i64 step)
{
	i64 ret = 0;
	for (int i = 0; i < N; ++i) {
		ret += rup(max(0LL, A[i] + step - (N - 1)), N + 1);
	}
	return ret <= step;
}

bool checkrelka(i64 step)
{
	for (int i = 0; i < 100; ++i) {
		if (check(step - i)) return true;
	}
	return false;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%lld", A + i);
	}

	i64 left = 0, right = 1e18;
	while (left < right) {
		i64 mid = (left + right) / 2;
		if (checkrelka(mid)) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}

	i64 ret = left;
	for (int i = 0; i < 100; ++i) {
		if (check(left - i)) ret = left - i;
	}
	printf("%lld\n", ret);

	return 0;
}
