#include<iostream>
#include<cstdio>

const int MAXN=2e5+5;

int n;
int a[MAXN],b[2][MAXN];

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=2;i<=n;i+=2) b[0][i/2]=a[i];
	for(i=1;i<=n;i+=2) b[1][i/2+1]=a[i];
	if(n%2==0)
	{
		for(i=n/2;i>=1;i--) printf("%d ",b[0][i]);
		for(i=1;i<=n/2;i++) printf("%d ",b[1][i]);
	}else
	{
		for(i=n/2+1;i>=1;i--) printf("%d ",b[1][i]);
		for(i=1;i<=n/2;i++) printf("%d ",b[0][i]);
	}
	return 0;
}
