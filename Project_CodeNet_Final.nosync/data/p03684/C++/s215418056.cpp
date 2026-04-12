#include<bits/stdc++.h>
using namespace std;
long long n,x,y,mst=0,mn,p[100005];
vector<tuple<long long,long long,long long> > v1,v2,g;
long long f(long long a)
{
	if(p[a]==a)
	{
		return a;
	}
	return p[a]=f(p[a]);
}
void un(long long b,long long c)
{
	p[f(b)]=f(c);
}
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);
		v1.push_back(make_tuple(x,y,i));
		v2.push_back(make_tuple(y,x,i));
		p[i]=i;
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(int i=0;i<v1.size()-1;i++)
	{
		mn=min(abs(get<0>(v1[i])-get<0>(v1[i+1])),abs(get<1>(v1[i])-get<1>(v1[i+1])));
		g.push_back(make_tuple(mn,get<2>(v1[i]),get<2>(v1[i+1])));
	}
	for(int i=0;i<v2.size()-1;i++)
	{
		mn=min(abs(get<0>(v2[i])-get<0>(v2[i+1])),abs(get<1>(v2[i])-get<1>(v2[i+1])));
		g.push_back(make_tuple(mn,get<2>(v2[i]),get<2>(v2[i+1])));
	}
	sort(g.begin(),g.end());
	for(int i=0;i<g.size();i++)
	{
		if(f(get<1>(g[i]))!=f(get<2>(g[i])))
		{
			un(get<1>(g[i]),get<2>(g[i]));
			mst+=get<0>(g[i]);
		}
	}
	printf("%lld",mst);
}