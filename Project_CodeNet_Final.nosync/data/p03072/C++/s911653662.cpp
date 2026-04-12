#include<stdio.h>
#include<iostream>
using namespace std;
int n,a;
int main()
{
	scanf("%d",&n);
	int maxn=0,ans=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(a>=maxn)
		{
			ans++;
			maxn=a;
		}
	}
	printf("%d\n",ans);
	return 0;
}