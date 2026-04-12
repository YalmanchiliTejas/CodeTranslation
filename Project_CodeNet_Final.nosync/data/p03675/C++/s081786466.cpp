#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=400000+10;

int tmp[maxn];

int main()
{
	int n;cin>>n;int l=200000,r=199999;

	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		if(i&1) tmp[++r]=x;
		else tmp[--l]=x;
	}
	if(n&1) for(int i=r;i>=l;--i) printf("%d ",tmp[i]);
	else for(int i=l;i<=r;++i) printf("%d ",tmp[i]);
	return 0;
}
