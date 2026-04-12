#include<iostream> 
#include<cstdio>
#include<algorithm>
using namespace std;
int one,two,a[1000001],c[1000001],d[1000001];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i+=2)
	{
		c[++one]=a[i];
	}
	for(int i=2;i<=n;i+=2)
	{
		d[++two]=a[i];
	}
	if(n%2==0)
	{
		for(int i=two;i>=1;i--)
		printf("%d ",d[i]);
		for(int i=1;i<=one;i++)
		printf("%d ",c[i]);		
	}
	if(n%2==1)
	{
		for(int i=one;i>=1;i--)
		printf("%d ",c[i]);
		for(int i=1;i<=two;i++)
		printf("%d ",d[i]);		
	}
}