#include<iostream>
#include<cstdio>
#include<cstring>

namespace Doubi_Problem
{
	const int N=101000,M=N*2;
	int begin[N],next[M],to[M];
	bool f[N],g[N];
	int n,e;
	void add(int x,int y,bool k=1)
	{
		to[++e]=y;
		next[e]=begin[x];
		begin[x]=e;
		if(k)add(y,x,0);
	}
	void predfs(int p=1,int h=0)
	{
		f[p]=0;g[p]=1;
		for(int i=begin[p],q;i;i=next[i])
			if((q=to[i])!=h)
			{
				predfs(q,p);
				f[p]|=g[q];
				g[p]&=f[q];
			}
	}
	void initialize()
	{
		scanf("%d",&n);
		for(int i=1,u,v;i<n;i++)
			scanf("%d%d",&u,&v),add(u,v);
		predfs();
	}
	bool ans;
	void dfs(int p=1,int h=0)
	{
		int cnt_son=0,cntg=0,cntf=0;
		for(int i=begin[p],q;i;i=next[i])
		{
			q=to[i];
			cntg+=g[q];
			cntf+=f[q];
			cnt_son++;
		}
		if(cntf==cnt_son)ans|=1;//return; why not return ? fuck you

		for(int i=begin[p],q;i;i=next[i])
			if((q=to[i])!=h)
			{
				f[p]=(cntg-g[q]!=0);
				g[p]=(cntf-f[q]==cnt_son-1);
				dfs(q,p);
			}
	}
	void solve()
	{
		initialize();
		dfs();
		printf("%s\n",ans?"First":"Second");
	}
}

int main()
{
	Doubi_Problem::solve();
	return 0;
}
