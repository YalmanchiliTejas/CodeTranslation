#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0; i<n; i++) scanf("%d",&a[i]);
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",lower_bound(a, a+n, x) - a);
	}
	return 0;
}
