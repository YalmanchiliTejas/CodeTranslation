#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[200100];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)scanf("%d",&a[i]);
	if(n % 2)
	{
		for(int i = n;i >= 1;i -= 2)
			printf("%d ",a[i]);
		for(int i = 2;i < n;i += 2)
			printf("%d ",a[i]);
	}else
	{
		for(int i = n;i > 1;i -= 2)
			printf("%d ",a[i]);
		for(int i = 1 ;i < n;i += 2)
			printf("%d ",a[i]);
	}
}