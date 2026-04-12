#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;

long long unsigned int a[100000];

int main()
{
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%llu\n", &a[i]);
	}
	sort(a, a + n);
	long long unsigned int addVal = 0;
	long long unsigned int minusVal = 0;
	int numOfAddOne = n % 2 == 0 ? 1 : 2;
	int numOfMinusOne = n % 2 == 0 ? 1 : 0;
	int numOfAddDouble = (n - 2) / 2;
	int numOfMinusDouble = (n - 2) / 2 + (n % 2 == 0 ? 0 : 1);
	for (int i = 0; i < n; ++i)
	{
		if (numOfMinusDouble > 0)
		{
			minusVal += 2 * a[i];
			--numOfMinusDouble;
		}
		else if (numOfMinusOne > 0)
		{
			minusVal += a[i];
			--numOfMinusOne;
		}
		else if (numOfAddOne > 0)
		{
			addVal += a[i];
			--numOfAddOne;
		}
		else if (numOfAddDouble > 0)
		{
			addVal += 2 * a[i];
			--numOfAddDouble;
		}
	}
	long long unsigned int diffA = addVal - minusVal;
	addVal = 0;
	minusVal = 0;
	numOfAddOne = n % 2 == 0 ? 1 : 0;
	numOfMinusOne = n % 2 == 0 ? 1 : 2;
	numOfAddDouble = (n - 2) / 2 + (n % 2 == 0 ? 0 : 1);
	numOfMinusDouble = (n - 2) / 2;
	for (int i = 0; i < n; ++i)
	{
		if (numOfMinusDouble > 0)
		{
			minusVal += 2 * a[i];
			--numOfMinusDouble;
		}
		else if (numOfMinusOne > 0)
		{
			minusVal += a[i];
			--numOfMinusOne;
		}
		else if (numOfAddOne > 0)
		{
			addVal += a[i];
			--numOfAddOne;
		}
		else if (numOfAddDouble > 0)
		{
			addVal += 2 * a[i];
			--numOfAddDouble;
		}
	}
	long long unsigned int diffB = addVal - minusVal;
	printf("%llu\n", diffA > diffB ? diffA : diffB);
	return 0;
}