#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[200001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=n;i>1;i-=2)printf("%d ",a[i]);
	printf("%d ",a[1]);
	for(int i=(n-1)%2+2;i<n;i+=2)printf("%d ",a[i]);
	return 0;
}