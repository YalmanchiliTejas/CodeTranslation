
#define _CRT_SECURE_NO_WARNINGS

#define N (1<<17)
#define MODULO (1000000007)
#define HA1 (2420609)
#define HA2 (19260817)

#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

inline int GetRand()
{
	int Res = rand()*rand()*rand();
	Res -= rand()*rand();
	Res += rand();
	return Res;
}

int n;
long long a[N];
long long Ans;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%lld", &a[i]);
	}
	while (true)
	{
		long long Res = 0LL;
		for (int i = 0;i < n;i++)
		{
			long long Tmp = a[i] / (long long)n;
			Res += Tmp;
			a[i] %= (long long)n;
			a[i] -= Tmp;
		}
		if (Res == 0LL)
		{
			break;
		}
		Ans += Res;
		for (int i = 0;i < n;i++)
		{
			a[i] += Res;
		}
	}
	printf("%lld\n", Ans);
	//system("pause");
	return 0;
}

