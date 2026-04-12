#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N=200005;

struct aa
{
	int c,id;
}a[N];
bool cmp(const aa &x,const aa &y) 
{
	return x.c<y.c;
}

int pos[N],n;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].c);
		a[i].id=i;
	}
	int mid=n/2;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) pos[a[i].id]=i;
	for (int i=1;i<=n;i++) 
	{
		if (pos[i]<=mid) printf("%d\n",a[mid+1]);
		else printf("%d\n",a[mid]);
	}
	return 0;
}