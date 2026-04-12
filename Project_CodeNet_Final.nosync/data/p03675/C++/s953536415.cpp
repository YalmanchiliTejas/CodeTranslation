
#define _CRT_SECURE_NO_WARNINGS

#define N (1<<18)
#define MODULO (1000000007)

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

int n;
int a[N];
int b[N];

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", &a[i]);
	}
	if (n & 1)
	{
		b[(n >> 1)] = a[0];
		for (int i = 1;i <= (n >> 1);i++)
		{
			b[(n >> 1) + i] = a[((i - 1) << 1) + 1];
			b[(n >> 1) - i] = a[((i - 1) << 1) + 2];
		}
	}
	else
	{
		for (int i = 0;i < (n >> 1);i++)
		{
			b[(n >> 1) + i] = a[(i << 1)];
			b[(n >> 1) - i - 1] = a[(i << 1) + 1];
		}
	}
	for (int i = 0;i < n;i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
//	system("pause");
	return 0;
}

