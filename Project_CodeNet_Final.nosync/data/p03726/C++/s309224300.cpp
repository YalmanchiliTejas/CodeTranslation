// #pragma GCC optimize(3)
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 100010
// #define int long long
using namespace std;
void write(int x){if(x<0){putchar('-');x=-x;}if(x>9) write(x/10);putchar(x%10+'0');}
int read(){int d=0,w=1;char c=getchar();for(;c<'0'||c>'9';c=getchar())if(c=='-')
w=-1;for(;c>='0'&&c<='9';c=getchar())d=(d<<1)+(d<<3)+c-48;return d*w;}
void wln(int x){write(x);putchar('\n');}
void wrs(int x){write(x);putchar(' ');}
int n,f,vis[maxn];
vector<int> b[maxn];
void dfs(int k,int fa)
{
	for(int i=0;i<b[k].size()&&!f;i++)
		if(b[k][i]!=fa) dfs(b[k][i],k);
	if(!vis[k]&&!f)
	{
		if(vis[fa])
		{
			f=1;
			puts("First");
			return;
		}
		vis[k]=vis[fa]=1;
	}
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		b[x].push_back(y);
		b[y].push_back(x);
	}
	dfs(1,0);
	if(!f) puts(vis[0]?"First":"Second");
	return 0;
}
