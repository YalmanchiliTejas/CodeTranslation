#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;
int main()
{
	int n, k;
	LL ans = 0;
	scanf("%d%d", &n, &k);
	for (int i = k + 1; i <= n; i++) // 枚举的是除数 
		ans += (n / i) * (i - k) + max(0, ((n % i) - (k == 0 ? k : (k - 1)))); // n / i: 一共可以分成多少个格子, (n % i - k): 最后那个零散的格子提供的贡献 
	printf("%lld", ans);
	return 0;
}

/*
10: 0
9: 1
8: 2
7: 3
6: 4
5: 5
4: 6
3: 7
2: 8
1: 9
0: 10
*/