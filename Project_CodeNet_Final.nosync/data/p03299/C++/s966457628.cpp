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
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N;
i64 H[100];

i64 modpow(i64 a, int pw)
{
	if (pw == 0) return 1;
	i64 ret = modpow(a, pw / 2);
	ret = ret * ret % MOD;
	if (pw % 2 == 1) ret = ret * a % MOD;
	return ret;
}

pair<i64, i64> solve(int l, int r, i64 base)
{
	i64 lowest = 1001001001;
	for (int i = l; i < r; ++i) lowest = min(lowest, H[i]);

	i64 alt = 2, nalt = 1;
	int start = -1; bool flg = false; int nl = 0;
	for (int i = l; i < r; ++i) {
		if (H[i] != lowest) {
			if (start == -1) start = i;

			if (i == r - 1 || H[i + 1] == lowest) {
				auto tmp = solve(start, i + 1, lowest);
				start = -1;

				alt = alt * tmp.first % MOD * 2 % MOD;
				nalt = nalt * (tmp.first * 2 + tmp.second) % MOD;

				alt = alt * (MOD + 1) / 2 % MOD;
				flg = true;
			}
		} else {
			nalt = nalt * 2 % MOD;
			++nl;
		}
	}
	ADD(nalt, MOD - alt);

	alt = alt * modpow(2, (lowest - base - 1)) % MOD;

	return {alt, nalt};
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%lld", H + i);

	auto sol = solve(0, N, 0);
	i64 ret = (sol.first + sol.second) % MOD;
	printf("%lld\n", ret);
	return 0;
}
