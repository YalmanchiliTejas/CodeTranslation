#include <bits/stdc++.h>
#define int long long
using namespace std;

int p[100010];
int n, k = 0;

struct node
{
	int x,y,id;
} nodes[100010];

struct edge
{
	int u,v,cost;
} mst[100010];

int Union(int u)
{
	if (p[u] == u) {return p[u];}
    return p[u] = Union(p[u]);
}

bool cmp1(node &a, node &b)
{
	return a.x < b.x;
}

bool cmp2(node &a, node &b)
{
	return a.y < b.y;
}
bool cmp3(edge &a, edge &b)
{
	return a.cost < b.cost;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> nodes[i].x >> nodes[i].y;
		nodes[i].id=i;
	}
	sort(nodes+1,nodes+1+n,cmp1);
	for(int i=1;i<=n-1;i++)
	{
		mst[k].u=nodes[i].id;
		mst[k].v=nodes[i+1].id;
		mst[k].cost=abs(nodes[i].x-nodes[i+1].x);
		k++;
	}
	sort(nodes+1,nodes+1+n,cmp2);
	for(int i=1;i<=n-1;i++)
	{
		mst[k].u=nodes[i].id;
		mst[k].v=nodes[i+1].id;
		mst[k].cost=abs(nodes[i].y-nodes[i+1].y);
		k++;
	}
	sort(mst,mst+k,cmp3);
	for(int i=0;i<=n;i++)
	{
		p[i]=i;
	}
	int ans = 0;
	for(int i=0;i<k;i++)
	{
		int a=mst[i].u,b=mst[i].v;
		a=Union(a);
		b=Union(b);
		if(a!=b)
		{
			ans+=mst[i].cost;
			p[a]=b;
		}
	}
	cout << ans;
	return 0;
}
