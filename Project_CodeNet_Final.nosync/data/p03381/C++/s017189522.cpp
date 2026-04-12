#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

struct R
{
	int i,v;
	inline bool operator<(const R b)const{return v<b.v;}
}a[233333];

int res[233333];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].v);
		a[i].i=i;
	}
	sort(&a[1],&a[n+1]);
	for(int i=1;i<=n;i++)
	{
		if(i<=n/2)res[a[i].i]=a[n/2+1].v;
		else res[a[i].i]=a[n/2].v;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",res[i]);
	}
	return 0;
}