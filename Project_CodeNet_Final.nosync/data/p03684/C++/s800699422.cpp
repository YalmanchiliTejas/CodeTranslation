#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, parent[100009], x, y;
ll ans;
struct Edge
{
	int from, to, cost;
};
vector<pair<pair<int, int>, int> > a;
vector<Edge> edges;
int find_set(int v)
{
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if (a != b)
		parent[b] = a;
}
bool sortx(pair<pair<int, int>, int>  aa, pair<pair<int, int>, int>  bb)
{
	return aa.f.f<bb.f.f;
}
bool sorty(pair<pair<int, int>, int>  aa, pair<pair<int, int>, int>  bb)
{
	return aa.f.s<bb.f.s;
}
bool sortedges(Edge aa, Edge bb)
{
	return aa.cost<bb.cost;
}
int main()
{
	IO;
	cin>>n;
	for (int i=0; i<n; i++)
	{
		parent[i]=i;
		cin>>x>>y;
		a.push_back(make_pair(make_pair(x,y), i));
	}
	sort(a.begin(), a.end(), sortx);
	for (int i=1; i<a.size(); i++)
	{
		x=a[i].s, y=a[i-1].s;
		int dx=abs(a[i].f.f-a[i-1].f.f);
		int dy=abs(a[i].f.s-a[i-1].f.s);
		Edge e;
		e.from=x;
		e.to=y;
		e.cost=min(dx, dy);
		edges.push_back(e);
	}
	sort(a.begin(), a.end(), sorty);
	for (int i=1; i<a.size(); i++)
	{
		x=a[i].s, y=a[i-1].s;
		int dx=abs(a[i].f.f-a[i-1].f.f);
		int dy=abs(a[i].f.s-a[i-1].f.s);
		Edge e;
		e.from=x;
		e.to=y;
		e.cost=min(dx, dy);
		edges.push_back(e);
	}
	sort(edges.begin(),edges.end(),sortedges);
	for (Edge e : edges)
	{
		if (find_set(e.from) != find_set(e.to))
		{
			ans += e.cost;
			union_sets(e.from, e.to);
		}
	}
	cout<<ans;
}
