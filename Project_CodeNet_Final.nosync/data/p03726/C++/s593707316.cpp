#include <bits/stdc++.h>
#define Maxn 600007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,cnt;
int last[Maxn],pre[Maxn],other[Maxn];
int size[Maxn];
bool f[Maxn];
//size[i] means the size of the tree with the root i
//f[i] means whether it is able to color the whole tree with the root i
void insert(int u, int v)
{
	other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u, int fa)
{
	int cnt=0;
	bool check=true;
	size[u]=1;
	for (int q=last[u];q;q=pre[q])
	{
		int v=other[q];
		if (v!=fa)
		{
			dfs(v,u);
			size[u]+=size[v];
			if (size[v]%2==1) ++cnt;
			if (!f[v]) check=false;
		}
	}
	if (cnt<=1&&check) f[u]=true; else f[u]=false;
}
int main()
{
	n=read(),cnt=0;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		insert(u,v),insert(v,u);
	}
	memset(f,false,sizeof(f));
	dfs(1,0);
	if (f[1]&&size[1]%2==0) cout << "Second" << endl; else cout << "First" << endl;
	return 0;
}
