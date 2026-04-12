#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
#define maxn 200005
using namespace std;
struct nod
{
	int val,id;
	nod(int a,int b)
	{
		val=a;
		id=b;
	}
	nod(){}
}b[maxn];
bool operator<(nod a,nod b)
{
	return a.val!=b.val ? a.val<b.val : a.id<b.id;
}
int n,maxx=0,minn=123456789;
int a[maxn];
set<nod> s1,s2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),b[i].val=a[i],b[i].id=i;
	sort(b+1,b+1+n);
	for(int i=1;i<=n/2;i++)
		s1.insert(b[i]);
	for(int i=n/2+1;i<=n;i++)
		s2.insert(b[i]);
	maxx=b[n/2].val;
	minn=b[n/2+1].val;
	for(int i=1;i<=n;i++)
	{
		if(s1.find(nod(a[i],i))!=s1.end())
			printf("%d\n",minn);
		else
			printf("%d\n",maxx);
	}
}
