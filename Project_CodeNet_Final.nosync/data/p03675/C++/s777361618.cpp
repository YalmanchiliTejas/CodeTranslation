#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
const int MaxN = 1e5;

int n;
int a[2 * MaxN + 5];
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if(n & 1)
		{
			for(int i = n; i >= 1; i -= 2)
				printf("%d ", a[i]);
			for(int i = 2; i <= n; i += 2)
				printf("%d ", a[i]);
			printf("\n");
		}
		else 
		{
			for(int i = n; i >= 1; i -= 2)
				printf("%d ", a[i]);
			for(int i = 1; i <= n; i += 2)
				printf("%d ", a[i]);
			printf("\n");
		}
		memset(a, 0, sizeof(a));
	}
	return 0;
}