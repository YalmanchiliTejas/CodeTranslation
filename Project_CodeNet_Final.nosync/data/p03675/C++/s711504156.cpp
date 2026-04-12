#include<bits/stdc++.h>
int n;
int a[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i>=1;i-=2)
	{
		printf("%d ",a[i]);
	}
		for(int i=1+(n&1);i<=n;i+=2)
		{
			printf("%d ",a[i]);
		}
	return 0;
}