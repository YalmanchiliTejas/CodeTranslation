#include<bits/stdc++.h>
using namespace std;
struct EDGE
{
	int x,y,data;
}edge[2*100000+10];
struct node
{
	int x,y,id;
}arr[100000+10];
int fa[100500];
int find(int x)
{
	if(x==fa[x]) return fa[x];
	return fa[x] = find(fa[x]);
}
bool cmp1(node a,node b)
{
	return a.x<b.x;
}
bool cmp2(node a,node b)
{
	return a.y<b.y;
}
bool cmp(EDGE a,EDGE b)
{
	return a.data<b.data;
}
int cnt = 0;
void built(int x,int y,int data)
{
	edge[++cnt].x=x;
	edge[cnt].y=y;
	edge[cnt].data=data;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		scanf("%d%d",&arr[i].x,&arr[i].y);
		arr[i].id = i;
	}
	sort(arr+1,arr+1+n,cmp1);
	for(int i=2;i<=n;i++)
	built(arr[i-1].id,arr[i].id,arr[i].x-arr[i-1].x);
	sort(arr+1,arr+1+n,cmp2);
	for(int i=2;i<=n;i++)
	built(arr[i-1].id,arr[i].id,arr[i].y-arr[i-1].y);
	long long res = 0;
	sort(edge+1,edge+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	if(find(edge[i].x)!=find(edge[i].y))
	{
		res += edge[i].data;
		fa[fa[edge[i].x]] = fa[edge[i].y];
	}
	printf("%d\n",res);
	return 0;
}
