#include<iostream>
#include<cstdio>
using namespace std;
int n,a[222222],p,q,ans[222222];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		p=n-i+1;
		if (p%2) q=1+p/2;
		else q=i+p/2;
		ans[q]=a[i];
	}
	for (int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}