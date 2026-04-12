#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAXN
#define MAXM
using namespace std;
int n,m;

int main()
{
	int maxn=-999,sum=0;
	scanf("%d",&n);
	for (int i=1,a;i<=n;i++)
	{
		scanf("%d",&a);
		if (a>=maxn)
		{
			maxn=a;
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
}
