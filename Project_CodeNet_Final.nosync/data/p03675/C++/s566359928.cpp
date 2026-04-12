#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n;
	scanf("%d",&n);
	int arr[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int ans[n+1];
	int p=1;
	if(n%2==0)
	{
		for(int i=n;i>=1;i-=2)
		{
			ans[p]=arr[i];
			p++;
		}
		for(int i=1;i<=n;i+=2)
		{
			ans[p]=arr[i];
			p++;
		}
	}
	else
	{
		for(int i=n;i>=1;i-=2)
		{
			ans[p]=arr[i];
			p++;
		}
		for(int i=2;i<=n;i+=2)
		{
			ans[p]=arr[i];
			p++;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}