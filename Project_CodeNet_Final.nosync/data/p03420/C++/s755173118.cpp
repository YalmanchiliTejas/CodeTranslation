#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;

#define INF 987654321
#define ll long long

int N, K;

int main()
{
	scanf("%d %d", &N, &K);
	if (K == 0) return !printf("%lld", (ll)N*N);
	
	ll res = 0;
	for (int i = K + 1; i <= N; i++) // mod
	{
		int val = N / i * (i - K) + max(0, N % i - K + 1);
		res += val;
	}
	printf("%lld", res);
	return 0;
}