#include<bits/stdc++.h>
using namespace std;
multiset<int> mp;
map<int,multiset<int> >go;
int main()
{
	int n,mx=-2100000000,minn=2100000000,gmx=-2100000000,gminn=2100000000;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		if (x>y) swap(x,y);
		mx=max(mx,y);minn=min(minn,x);
		gmx=max(gmx,x);gminn=min(gminn,y);
		mp.insert(x);go[x].insert(y);go[y].insert(-1);
	}
	long long ans=(long long)(mx-gminn)*(gmx-minn);
	
	for (map<int,multiset<int> >::iterator it=go.begin();it!=go.end();it++)
	{
		ans=min(ans,(long long)(mx-minn)*((*(--mp.end()))-it->first));
		mp.erase(it->first);
		for (multiset<int>::iterator p=it->second.begin();p!=it->second.end();p++)
		{
			if ((*p)==-1) goto bomb;
			mp.insert(*p);
		}
	}
	bomb:;
	printf("%lld\n",ans);
}