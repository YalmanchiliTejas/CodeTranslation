#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<set>
#include<map> 
using namespace std;

const int N=1e5+10;
priority_queue<int> q;
int a[N],b[N],u,ans,n,num;
bool bj;

int find(int x)
{
	int l,r,mid;
	l=1;r=ans;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(b[mid]<x) r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	b[1]=a[1];ans=1;
	for(int i=2;i<=n;i++)
	{
		if(b[ans]>=a[i])
		{
			b[++ans]=a[i];
		}
		else
		{
			u=find(a[i]);
			b[u]=a[i];
		}
	}
	printf("%d",ans);
	
	return 0;	
} 