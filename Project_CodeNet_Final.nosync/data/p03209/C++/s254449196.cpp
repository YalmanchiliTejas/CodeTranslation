#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>

using namespace std;

long long result = 0;
long long num[51];
long long pati[51];

void burger(int n, long long x)
{
	if (x >= num[n] - 1)
		result += pati[n];
	else if (x >= num[n - 1] + 3)
	{
		result += pati[n - 1];
		result++;
		burger(n - 1, x - num[n - 1] - 2);
	}
	else if (x == num[n - 1] + 2)
	{
		result += pati[--n];
		result++;
	}
	else if (x == num[n - 1] + 1)
	{
		result += pati[--n];
	}
	else if (x > 1)
	{
		burger(--n, --x);
	}
}

int main()
{
	int n;
	long long x;
	
	num[0] = 1;
	for (int i = 1; i < 51; i++)
		num[i] = num[i - 1] * 2 + 3;
	pati[0] = 1;
	for (int i = 1; i < 51; i++)
		pati[i] = pati[i - 1] * 2 + 1;

	cin >> n >> x;
	burger(n, x);
	printf("%lld", result);

	return 0;
}
