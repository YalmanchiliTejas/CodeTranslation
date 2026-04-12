#include <map>
#include <set>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring> 
#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;

long long N, A[200005];
long long suf[200005];

int main()
{
	scanf("%lld", &N);
	for(int i = 1;i <= N;++i)
		scanf("%lld", &A[i]);
	suf[N + 1] = 0;
	for(int i = N;i >= 1;--i)
		suf[i] = (suf[i + 1] + A[i]) % mod;
	long long ans = 0;
	for(int i = 1;i < N;++i)
		ans = (ans + A[i] * suf[i + 1] % mod) % mod;
	printf("%lld\n", ans);

	return 0;
}