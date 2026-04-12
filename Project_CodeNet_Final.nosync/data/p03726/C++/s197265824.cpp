#include<bits/stdc++.h>
using namespace std;
set<int> des[300010],mp;
bool erz[300010];
int main()
{
	//freopen("in.txt","r",stdin);
	int n;scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		des[u].insert(v);des[v].insert(u);
	}
	for (int i=1;i<=n;i++) if (des[i].size()==2) mp.insert(i);
	while (mp.size())
	{
		int s=*mp.begin();mp.erase(s);n-=2;
		
		int p1=*des[s].begin();des[s].erase(p1);int p2=*des[s].begin();des[s].erase(p2);
		if (des[p1].size()>des[p2].size()) swap(p1,p2);
		
		des[p1].erase(s);des[p2].erase(s);
		for (set<int>::iterator it=des[p1].begin();it!=des[p1].end();it++)
		{
			des[*it].erase(p1);
			des[*it].insert(p2);
			des[p2].insert(*it);
		}
		
		mp.erase(p1);
		if (des[p2].size()==2) mp.insert(p2);else mp.erase(p2);
	}
	//cout<<n<<endl;
	if (n==2) printf("Second\n");else printf("First\n");
}