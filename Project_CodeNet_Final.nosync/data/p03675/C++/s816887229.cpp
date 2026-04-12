#include<cstdio>
#include<iostream>
using namespace std;

int a[300005],b[300005];
int n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	if(n%2==0)
	{
		int t=1;
		for(int i=n/2+1;i<=n;i++)
		b[i]=a[t],t+=2;
		t=2;
		for(int i=n/2;i>=1;i--)
		b[i]=a[t],t+=2;
	}
	else
	{
		int t=2;
		for(int i=n/2+2;i<=n;i++)
		b[i]=a[t],t+=2;
		t=1;
		for(int i=n/2+1;i>=1;i--)
		b[i]=a[t],t+=2;
	}
	for(int i=1;i<=n;i++)
	printf("%d ",b[i]);
}
