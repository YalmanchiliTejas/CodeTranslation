#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e5+4;
int link[4*N],size[4*N];
int n;
vector <pair<ll, pair<int,int> > > edge;

struct point
{
	int x,y,pos;
} coor[N];

bool cmp1(point a,point b)
{
	if(a.x != b.x)
		return (a.x < b.x);

	return (a.y < b.y);
}

bool cmp2(point a,point b)
{
	if(a.y != b.y)
		return (a.y < b.y);

	return (a.x < b.x);
}

void init(int V)
{
	for(int i=1;i<=n;i++) link[i] = i;
	for(int i=1;i<=n;i++) size[i] = 1;
}

int find(int x)
{
	while(x != link[x]) x = link[x];
	return x;
}

bool same(int a,int b)
{
	return find(a) == find(b);
}

void unite(int a,int b)
{
	a = find(a);
	b = find(b);
	if(size[a] < size[b]) swap(a,b);
	size[a] += size[b];
	link[b] = a;
}


int main()
{
	cin>>n;
	init(n);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d %I64d",&coor[i].x,&coor[i].y);
		coor[i].pos = i;
	}

	sort(coor+1,coor+1+n,cmp1);
	for(int i=2;i<=n;i++)
	{
		edge.pb({coor[i].x - coor[i-1].x, {coor[i].pos, coor[i-1].pos}});
	}
	
	sort(coor+1,coor+1+n,cmp2);
	for(int i=2;i<=n;i++)
	{
		edge.pb({coor[i].y - coor[i-1].y, {coor[i].pos, coor[i-1].pos}});
	}
	sort(edge.begin(),edge.end());
	ll cost = 0;

	for(auto i:edge)
	{
		//cout<<i.fi<<' ';
		if(!same(i.se.fi, i.se.se))
		{
			unite(i.se.fi, i.se.se);
			cost += i.fi;	
		}
	}

	cout<<cost<<'\n';
}