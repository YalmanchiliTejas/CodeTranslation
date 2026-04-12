#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	deque<int> a;
	for(int i = 0, j; i < n; ++i)
	{
		scanf("%d", &j);
		if(i % 2)
		{
			a.push_front(j);
		}
		else
		{
			a.push_back(j);
		}
	}
	if(n % 2)
	{
		for(int i = n - 1; i >= 0; --i)
		{
			printf("%d ", a[i]);
		}
	}
	else
	{
		for(int i = 0; i < n; ++i)
		{
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}