#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int a[200050],b[200050];
int mid,cnt;

void work()
{
	if(n%2==1)
		mid=(n-1)/2+1;
	if(n%2==0)
		mid=n/2+1;
	b[mid]=a[1];
	for(int i=2;i<=n;i++)
	{
		if(i%2==1)
		{
			b[mid+cnt]=a[i];
		}
		if(i%2==0)
		{
			cnt++;
			b[mid-cnt]=a[i];
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	work();
	if(n%2==0)
		for(int i=1;i<=n;i++)
			printf("%d ",b[i]);
	if(n%2==1)
		for(int i=n;i>=1;i--)
			printf("%d ",b[i]);
	return 0;
}