#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int>G[1<<17];
bool re[1<<17];
int d[1<<17];
int pa[1<<17];
void dfs(int u,int p,int di)
{
	pa[u]=p;
	d[u]=di;
	int cnt=0;
	for(int v:G[u])
	{
		if(v!=p)
		{
			cnt++;
			dfs(v,u,di+1);
		}
	}
	re[u]=cnt==0;
}
bool rre[1<<17];
bool ansflag;
pair<int,int>dfs3(int u,int p)
{
	int a=0,b=0,ecnt=0;
	for(int v:G[u])
	{
		ecnt+=v!=p;
		if(v==p||re[v])continue;
		pair<int,int>q=dfs3(v,u);
		a+=q.first;
		b+=q.second;
	}
	if(rre[u])
	{
		a++;
	}
	if(a>=2)ansflag=true;
	if(b!=ecnt)b=0;
	else if(p==-1)ansflag=true;
	return make_pair(b>0,a>0);
}
bool f[2];
vector<int>c[2];
bool reach[1<<17];
void dfs2(int u,int p)
{
	reach[u]=true;
	for(int v:G[u])
	{
		if(v!=p)dfs2(v,u);
	}
}
main()
{
	cin>>N;
	for(int i=1;i<N;i++)
	{
		int a,b;cin>>a>>b;a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	bool flag=true;
	for(int i=0;i<N;i++)flag&=G[i].size()<=2;
	if(flag)
	{
		cout<<(N%2?"First":"Second")<<endl;
		return 0;
	}
	int r=0;
	while(G[r].size()<3)r++;
	dfs(r,-1,0);
	for(int i=0;i<N;i++)
	{
		if(i==r)continue;
		int cnt=0;
		for(int v:G[i])cnt+=re[v];
		if(cnt>=2)
		{
			cout<<"First"<<endl;
			return 0;
		}
		else if(cnt==1)
		{
			rre[i]=true;
			c[d[i]%2].push_back(i);
			if(G[pa[i]].size()==2)f[d[i]%2]=true;
		}
	}
	dfs3(r,-1);
	if(ansflag)
	{
		cout<<"First"<<endl;
		return 0;
	}
	int cnt=0;
	for(int v:G[r])cnt+=re[v];
	if(cnt>=2)
	{
		cout<<"First"<<endl;
		return 0;
	}
	cout<<"Second"<<endl;
}