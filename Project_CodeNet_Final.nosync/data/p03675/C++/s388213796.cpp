#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int a[200010],b[200010];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=1,r=n;
	for(int i=n;i>=1;i--)
		if((n-i)&1) b[r--]=a[i];
		else b[l++]=a[i];
	for(int i=1;i<=n;i++) printf("%d ",b[i]);printf("\n");
}