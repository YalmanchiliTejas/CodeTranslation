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
int par[100010],xx[100010],yy[100010],in[100010][2];
vector <pair <int,pii> > con;

bool cmp1(int x,int y)
{
	return in[x][0]<in[y][0];
}

bool cmp2(int x,int y)
{
	return in[x][1]<in[y][1];
}

inline int getval(int x,int y)
{
	return min(abs(in[x][0]-in[y][0]),abs(in[x][1]-in[y][1]));
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
	rep(i,100005) par[i]=i,xx[i]=i,yy[i]=i;
	rep(i,n) scanf("%I64d%I64d",&in[i][0],&in[i][1]);
	sort(xx,xx+n,cmp1);
	sort(yy,yy+n,cmp2);
	repn(i,n-1)
	{
		con.pb({getval(xx[i-1],xx[i]),{xx[i-1],xx[i]}});
		con.pb({getval(yy[i-1],yy[i]),{yy[i-1],yy[i]}});
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