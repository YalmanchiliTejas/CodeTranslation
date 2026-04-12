#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define MAX 100100
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int n;
vector<int> E[MAX];
bool dfs(int u,int ff)
{
	int cnt=0;
	for(int v:E[u])
	{
		if(v==ff)continue;
		if(dfs(v,u))++cnt;
	}
	if(cnt>=2){puts("First");exit(0);}
	return cnt^1;
}
int main()
{
	n=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		E[u].push_back(v);
		E[v].push_back(u);
	}
	if(dfs(1,0))puts("First");
	else puts("Second");
	return 0;
}
