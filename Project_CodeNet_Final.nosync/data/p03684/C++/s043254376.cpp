#include<bits/stdc++.h>
using namespace std;
pair<int,int>x[1<<17],y[1<<17];int i,n,p[1<<17],s;
vector<pair<int,pair<int,int> > >G;
int f(int a){return p[a]-a?p[a]=f(p[a]):a;}
main()
{
	for(cin>>n;i++<n;x[i].second=y[i].second=p[i]=i)cin>>x[i].first>>y[i].first;
	sort(x+1,x+n+1),sort(y+1,y+n+1);
	for(i=0;++i<n;)
	{
		G.push_back(make_pair(abs(x[i].first-x[i+1].first),make_pair(x[i].second,x[i+1].second)));
		G.push_back(make_pair(abs(y[i].first-y[i+1].first),make_pair(y[i].second,y[i+1].second)));
	}
	sort(G.begin(),G.end());
	for(i=0;i<2*n-2;i++)
	{
		int x=G[i].second.first,y=G[i].second.second;
		if(f(x)-f(y))
		{
			s+=G[i].first;
			p[f(x)]=f(y);
		}
	}
	cout<<s<<endl;
}