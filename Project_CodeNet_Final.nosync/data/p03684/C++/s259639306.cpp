#include<iostream>
#include<vector>
#include<stack>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
#define LL long long int
using namespace std;
const int maxn = 120000;
struct CITY
{
	int x,y;
	int num;
};
vector<CITY> city;

bool cmp1(CITY a, CITY b)
{
	return a.x < b.x;
}

bool cmp2(CITY a, CITY b)
{
	return a.y<b.y;
}
int n;

int fa[maxn];
int findset(int x)
{
	if(x != fa[x])
	{
		fa[x] = findset(fa[x]);
	}
	return fa[x];
}

struct Edge
{
	int u,v;
	int w;
	bool operator < (Edge tar) const
	{
		return w < tar.w;
	}
};

vector<Edge> E;

void init()
{
	city.clear();
	E.clear();
	for(int i = 0;i<maxn;i++) fa[i] = i;
}





int main()
{
	while(cin >> n)
	{
		init();
		for(int i = 0;i<n;i++)
		{
			int xx,yy;
			scanf("%d %d",&xx,&yy);
			CITY tmp;
			tmp.x = xx;
			tmp.y = yy;
			tmp.num = i;
			city.push_back(tmp);	
		}	
		sort(city.begin(),city.end(),cmp1);
		for(int i = 0;i<city.size() - 1;i++)
		{
			Edge tmp;
			tmp.u = city[i].num;
			tmp.v = city[i+1].num;
			tmp.w = abs(city[i].x - city[i+1].x);
			E.push_back(tmp);
		}
		sort(city.begin(),city.end(),cmp2);
		for(int i = 0;i<city.size() - 1;i++)
		{
			Edge tmp;
			tmp.u = city[i].num;
			tmp.v = city[i+1].num;
			tmp.w = abs(city[i].y - city[i+1].y);
			E.push_back(tmp);
		}
		
		LL ans = 0;
		sort(E.begin(),E.end());
		for(int i = 0;i<E.size();i++)
		{
			int u = E[i].u;
			int v = E[i].v;
			int w = E[i].w;
			int x = findset(u);
			int y = findset(v);
			if(x == y) continue;
			else 
			{
				fa[x] = y;
				ans = ans + w;
				findset(x);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}