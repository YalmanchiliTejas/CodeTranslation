//************************
//*  Date: 2018.8.25     *
//*  Problem:            *
//*  Author: xuziyuan    * 
//************************

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

int n,m,w,pos;
string s[110];
bool com=true,col[110][2],row[110][2],vis[110][110];
vector <string> ans;

int main()
{
	cin>>n>>m;
	rep(i,n) cin>>s[i];
	rep(i,n)
	{
		rep(j,m)
		{
			if(vis[i][j]) continue;
			if(s[i][j]=='.')
			{
				row[i][0]=true;
				col[j][0]=true;
			}
			else
			{
				row[i][1]=true;
				col[j][1]=true;
			}
		}
	}
	rep(i,n)
	{
		if(row[i][0]&& !row[i][1])
		{
			com=true;
			rep(j,m) vis[i][j]=true;
		}
	}
	rep(i,m)
	{
		if(col[i][0]&& !col[i][1])
		{
			com=true;
			rep(j,n) vis[j][i]=true;
		}
	}
	rep(i,n)
	{
		string tmp="";
		rep(j,m) if(!vis[i][j]) tmp.pb(s[i][j]);
		if(tmp.size()>0) ans.pb(tmp);
	}
	rep(i,ans.size())
	{
		printf("%s\n",ans[i].c_str());
	}
	rt0;
}