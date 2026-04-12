#include <bits/stdc++.h>

using namespace std;

inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
struct edge
{
	int v,next;
}vs[300010];
int st[300010],ee,n,size[300010],fg;
inline void addedge(int u,int v)
{
	vs[++ee].v=v;vs[ee].next=st[u];st[u]=ee;
}
inline int dfs(int rt,int pr)
{
	int ret=1,cnt=0;
	for(int i=st[rt];i;i=vs[i].next)
	{
		if(vs[i].v==pr) continue;
		cnt+=dfs(vs[i].v,rt);
	}
	if(cnt>1) fg=1; 
	if(cnt==1) ret=0; 
	return ret;
}
int main()
{
	n=read(); 
	for(int i=1;i<n;i++)
	{
		int u=read(), v=read();
		addedge(u,v); addedge(v,u);
	}
	int x=dfs(1,0); if(x) fg=1;
	if(fg) cout << "First" << endl;
	else cout << "Second" << endl;
}