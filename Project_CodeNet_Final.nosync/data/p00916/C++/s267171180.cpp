#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int n;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
main()
{
	while(cin>>n,n)
	{
		vector<pair<pair<int,int>,pair<int,int> > >a;
		vector<int>x,y;
		for(int i=0;i<=n;i++)
		{
			int u,v,U,V;
			if(i<n)cin>>u>>V>>U>>v;
			else u=v=-1,U=V=1e9;
			a.push_back({{u,v},{U,V}});
			x.push_back(u);
			x.push_back(U);
			y.push_back(v);
			y.push_back(V);
		}
		sort(x.begin(),x.end());x.erase(unique(x.begin(),x.end()),x.end());
		sort(y.begin(),y.end());y.erase(unique(y.begin(),y.end()),y.end());
		map<int,int>X,Y;
		int sz=0;
		for(int e:x)X[e]=sz++;
		sz=0;
		for(int e:y)Y[e]=sz++;
		vector<vector<long> >S(x.size(),vector<long>(y.size()));
		vector<vector<bool> >used(x.size(),vector<bool>(y.size()));
		function<void(int,int)>dfs=[&dfs,&used,&x,&y,&S](int nx,int ny){
			used[nx][ny]=1;
			for(int r=0;r<4;r++)
			{
				int tx=nx+dx[r],ty=ny+dy[r];
				if(tx<0||ty<0||tx>=x.size()||ty>=y.size()||used[tx][ty]||S[nx][ny]!=S[tx][ty])continue;
				dfs(tx,ty);
			}
		};
		sz=0;
		for(auto p:a)
		{
			long pu=1L<<sz++;
			int u,v,U,V;
			u=X[p.first.first];
			v=Y[p.first.second];
			U=X[p.second.first];
			V=Y[p.second.second];
			S[u][v]+=pu;
			S[u][V]-=pu;
			S[U][v]-=pu;
			S[U][V]+=pu;
		}
		for(int i=0;i<x.size();i++)for(int j=0;j+1<y.size();j++)S[i][j+1]+=S[i][j];
		for(int i=0;i+1<x.size();i++)for(int j=0;j<y.size();j++)S[i+1][j]+=S[i][j];
		int ans=0;
		for(int i=0;i+1<x.size();i++)for(int j=0;j+1<y.size();j++)
		{
			if(used[i][j])continue;
			ans++;
			dfs(i,j);
		}
		cout<<ans<<endl;
	}
}

