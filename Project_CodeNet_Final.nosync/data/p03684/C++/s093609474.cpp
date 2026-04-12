#include<bits/stdc++.h>
using namespace std;
const int md=1000000007;
int n,f[100005];
vector<pair<int,int> >v1,v2;
vector<pair<int,pair<int,int> > >g;
int fnd(int x){return f[x]==x?x:f[x]=fnd(f[x]);}
bool uni(int x,int y)
{
	x=fnd(x);
	y=fnd(y);
	if(x==y)return false;
	f[x]=y;
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v1.push_back(make_pair(a,i));
		v2.push_back(make_pair(b,i));
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	g.clear();
	for(int i=0;i<n-1;i++)
	{
		int a=v1[i].first;
		int b=v1[i+1].first;
		int c=v1[i].second;
		int d=v1[i+1].second;
		g.push_back(make_pair(b-a,make_pair(c,d)));
	}
	for(int i=0;i<n-1;i++)
	{
		int a=v2[i].first;
		int b=v2[i+1].first;
		int c=v2[i].second;
		int d=v2[i+1].second;
		g.push_back(make_pair(b-a,make_pair(c,d)));
	}
	sort(g.begin(),g.end());
	for(int i=1;i<=n;i++)f[i]=i;
	int t=n-1;
	long long ans=0;
	for(int i=0;i<g.size();i++)
	{
//		cout<<g[i].second.first<<" "<<g[i].second.second<<" "<<g[i].first<<endl;
		if(uni(g[i].second.first,g[i].second.second))
		{
			ans+=g[i].first;
			t--;
		}
		if(t==0)
		{
			printf("%lld\n",ans);
			return 0;
		}
	}
	return 0;
}