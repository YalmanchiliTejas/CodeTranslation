#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <cassert>
 
#pragma comment(linker, "/STACK:336777216")  
 
using namespace std;

const int MAXN = 200000 + 10;

int N, K;

void Work()
{
	scanf("%d%d", &N, &K);
	long long Ans = 0;
	for (int b = 1; b <= N; b ++)
	{
		// a % b >= K
		if (K == 0)
		{
			Ans += N;
			continue;
		}
		long long seq = N / b, rem = N % b;
		// 1 .. b - 1
		if (K > b - 1)
			continue;
		Ans += (b - 1 - K + 1) * seq;
		// 1 .. rem
		if (K > rem)
			continue;
		Ans += (rem - K + 1);
	}
	printf("%lld\n", Ans);
}

int main()
{
	Work();
	return 0;
}