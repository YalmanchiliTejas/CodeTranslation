#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
typedef long long LL;
const int inf = 1 << 30;
const LL INF = 1LL << 60;
const int MaxN = 305;

LL N, K;

int main()
{
	while(scanf("%lld %lld", &N, &K) != EOF)
	{
		LL ans = 0;
		if(K == 0) ans = N * N;
		else {
			for(LL b = K + 1; b <= N; b++) {
				ans += (b - K) * (N / b) + max(0LL, (N % b - K + 1));
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}