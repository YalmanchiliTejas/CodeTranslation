#include <bits/stdc++.h>
#define Maxn 400007
using namespace std;
int a[Maxn],c[Maxn],n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[i]=a[i];
	}
	sort(c+1,c+n+1);
	for (int i=1;i<=n;i++)
		if (a[i]<=c[n/2]) printf("%d\n",c[n/2+1]); else printf("%d\n",c[n/2]);
	return 0;
}
