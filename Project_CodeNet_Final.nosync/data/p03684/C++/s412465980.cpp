#include<bits/stdc++.h>
using namespace std;
int n,parent[100010];
vector<pair<int,int> > x,y;
vector<pair<int,pair<int,int> > > v;

int findP(int a)
{
	if(parent[a] == a) return a;
	return parent[a] = findP(parent[a]);
}
void unite(int a, int b)
{
	int fa = findP(a);
	int fb = findP(b);
	parent[fa] = fb;
	return;
}
int main()
{
	int i,j;
	int a,b;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		parent[i] = i;
		scanf("%d %d",&a,&b);
		x.push_back({a,i});
		y.push_back({b,i});
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	
	for(i=1;i<x.size();i++)
	{
		v.push_back({x[i].first - x[i-1].first , {x[i].second , x[i-1].second}});
	//	printf("{%d , {%d , %d} } \n",x[i].first - x[i-1].first , x[i].second , x[i-1].second);
	}
	for(i=1;i<y.size();i++)
	{
		v.push_back({y[i].first - y[i-1].first , {y[i].second , y[i-1].second}});
//		printf("{%d , {%d , %d} } \n",y[i].first - y[i-1].first , y[i].second , y[i-1].second);
	}
	sort(v.begin(), v.end());
	
	int edge=0;
	long long totalsum = 0;
	for(i=0;i<v.size();i++)
	{
		a = v[i].second.first;
		b = v[i].second.second;
		
	//	printf("look cost = %d ,  %d===%d \n",v[i].first ,a,b);
		if(findP(a) != findP(b))
		{
	//		printf("yes\n");
			edge++;
			unite(a,b);
			totalsum += v[i].first;
			
		}
		
		
	}
	
	
	printf("%lld\n",totalsum);
	
}