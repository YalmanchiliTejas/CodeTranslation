#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x=0;char ch=getchar();
	while(ch<'0' || '9'<ch)ch=getchar();
	while('0'<=ch && ch<='9')x=x*10+(ch^48),ch=getchar();
	return x;
}

const int N=1e5+9;
bool flag=0;
int n,to[N<<1],nxt[N<<1],beg[N],tot;

inline void add(int u,int v)
{
	to[++tot]=v;
	nxt[tot]=beg[u];
	beg[u]=tot;
}

inline int dfs(int u,int fa)
{
	int ret=1;
	for(int i=beg[u];i && !flag;i=nxt[i])
		if(to[i]!=fa)
			ret-=dfs(to[i],u);
	if(flag)return 0;
	if(ret<0)
		flag=1;
	return ret;
}

int main()
{
	if(fopen("vj.in","r"))
	{
		freopen("vj.in","r",stdin);
		freopen("vj.out","w",stdout);
	}
	
	n=read();
	for(int i=1,u,v;i<n;i++)
	{
		u=read();v=read();
		add(u,v);add(v,u);
	}

	if(dfs(1,0) || flag)
		puts("First");
	else
		puts("Second");

	return 0;
}
