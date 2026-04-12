#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define LOWBIT(x) x & (-x)
#define Pair pair<int,int>
#define LL long long
using namespace std;

struct node
{
	int x,y;
	int num;
}a[100048];

struct node2
{
	int x,y;
	int l;
}edge[300048];

bool cmp1(node x,node y)
{
	return x.x<y.x;
}

bool cmp2(node x,node y)
{
	return x.y<y.y;
}

bool cmp(node2 x,node2 y)
{
	return x.l<y.l;
}

int n,top;
int pre[100048];
inline int find_anc(int x)
{
	if (pre[x]!=x) pre[x]=find_anc(pre[x]);
	return pre[x];
}
inline void merge(int x,int y)
{
	x=find_anc(x);y=find_anc(y);
	pre[x]=y;
}

int main ()
{
	int i;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].num=i;
	}
	sort(a+1,a+n+1,cmp1);
	top=0;
	for (i=1;i<=n-1;i++)
	{
		edge[++top].x=a[i].num;
		edge[top].y=a[i+1].num;
		edge[top].l=a[i+1].x-a[i].x;
	}
	sort(a+1,a+n+1,cmp2);
	for (i=1;i<=n-1;i++)
	{
		edge[++top].x=a[i].num;
		edge[top].y=a[i+1].num;
		edge[top].l=a[i+1].y-a[i].y;
	}
	for (i=1;i<=n;i++) pre[i]=i;
	sort(edge+1,edge+top+1,cmp);
	int cnt=0;i=0;
	LL ans=0;
	while (cnt<n-1)
	{
		i++;
		if (find_anc(edge[i].x)!=find_anc(edge[i].y))
		{
			ans+=edge[i].l;
			merge(edge[i].x,edge[i].y);
			cnt++;
		}
	}
	cout<<ans<<endl;
	return 0;
}