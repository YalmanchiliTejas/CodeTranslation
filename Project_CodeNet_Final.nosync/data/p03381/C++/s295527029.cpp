#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[200010],b[200010];
int main()
{
	scanf("%d",&n);for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	{
		if (b[i]<=a[n/2]) printf("%d\n",a[n/2+1]);
		else printf("%d\n",a[n/2]);
	}
}