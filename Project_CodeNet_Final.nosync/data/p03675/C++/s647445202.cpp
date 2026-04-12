#include<bits/stdc++.h>
using namespace std;

int n,x,H,T,q[400010];

int main()
{
#ifdef h10
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int i;
	scanf("%d",&n);
	H=n; T=n;
	while (n--)
	{
		scanf("%d",&x);
		if (n&1) q[T++]=x;
		else q[--H]=x;
	}
	for (i=H;i<T;i++)
		printf("%d ",q[i]);
}
