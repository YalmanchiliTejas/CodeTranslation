#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
vector<pair<int,int> >v;
vector<pair<int,int> >vv;
vector<pair<int,pair<int,int> > >vvv;
int par[200007];
int init()
{
	int i;
	for(i=1;i<=2e5+5;i++)
		par[i]=i;
	return 0;
}
int parent(int aa)
{
	if(par[aa]==aa)
		return aa;
	return par[aa]=parent(par[aa]);
}
int union_(int aa,int bb)
{
	if(parent(aa)!=parent(bb))
		par[parent(aa)]=parent(bb);
	return 0;
}
int main()
{
	init();
	int m;
	scanf("%d",&m);
	int i;
	for(i=1;i<=m;i++)
	{
		int aa,bb;
		scanf("%d %d",&aa,&bb);
		v.pb(mp(aa,i));
		vv.pb(mp(bb,i));
	}
	sort(v.begin(),v.end());
	sort(vv.begin(),vv.end());
	for(i=1;i<v.size();i++)
		vvv.pb(mp(abs(v[i-1].fi-v[i].fi),mp(v[i-1].se,v[i].se)));
	for(i=1;i<vv.size();i++)
		vvv.pb(mp(abs(vv[i-1].fi-vv[i].fi),mp(vv[i-1].se,vv[i].se)));
	sort(vvv.begin(),vvv.end());
	long long int ans=0;
	for(i=0;i<vvv.size();i++)
	{
		if(parent(vvv[i].se.fi)!=parent(vvv[i].se.se))
			ans=ans+vvv[i].fi,union_(vvv[i].se.fi,vvv[i].se.se);
	}
	printf("%lld\n",ans);
	return 0;
}