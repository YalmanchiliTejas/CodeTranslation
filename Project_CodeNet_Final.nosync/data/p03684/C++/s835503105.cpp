/***********************
*  Author: xuziyuan    * 
***********************/

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++)
#define LL long long
#define pii pair <LL,LL>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

LL n,ans=0;
int par[100010];
vector <pair <pii,int> > v[2];
vector <pair <int,pii> > con;

inline int getval(pair <pii,int> a,pair <pii,int> b)
{
	return min(abs(a.fi.fi-b.fi.fi),abs(a.fi.se-b.fi.se));
}

int FIND(int pos)//dsu
{
	if(par[pos]!=pos) par[pos]=FIND(par[pos]);
	return par[pos];
}

inline void UNION(int pos1,int pos2)
{
	par[FIND(pos1)]=FIND(pos2);
}

int main()
{ 
	cin>>n;
	rep(i,100005) par[i]=i;
	rep(i,n)
	{
		LL x,y;
		scanf("%I64d%I64d",&x,&y);
		v[0].pb({{x,y},i});
		v[1].pb({{y,x},i});
	}
	sort(v[0].begin(),v[0].end());
	sort(v[1].begin(),v[1].end());
	repn(i,n-1)
	{
		con.pb({getval(v[0][i-1],v[0][i]),{v[0][i-1].se,v[0][i].se}});
		con.pb({getval(v[1][i-1],v[1][i]),{v[1][i-1].se,v[1][i].se}});
	}
	sort(con.begin(),con.end());
	rep(i,con.size())
	{
		if(FIND(con[i].se.fi)==FIND(con[i].se.se)) continue;
		UNION(con[i].se.fi,con[i].se.se);
		ans+=con[i].fi;
	}
	cout<<ans<<endl;
	rt0;
}