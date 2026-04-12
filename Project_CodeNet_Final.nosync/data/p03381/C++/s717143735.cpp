#include<bits/stdc++.h>
using namespace std;

const int N=200009;
int n,a[N],b[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(a+1,a+n+1);

	for(int i=1;i<=n;i++)
	{
		if(b[i]<=a[n/2])
			printf("%d\n",a[n/2+1]);
		else if(a[n/2+1]<=b[i])
			printf("%d\n",a[n/2]);
	}

	return 0;
}
