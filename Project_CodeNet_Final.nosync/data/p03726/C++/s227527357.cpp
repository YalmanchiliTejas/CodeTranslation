//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbg=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int n,cnt;
bool vis[100111],vis2[100111];
vector<int>con[100111];
int q[100111],qsz,deg[100111];
bool del[100111];
void dele(int x)
{
	del[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		if(!del[con[x][i]])
		{
			if(!vis[con[x][i]]&&(--deg[con[x][i]])==1)
			{
				q[qsz++]=con[x][i];
				vis[con[x][i]]=1;
			}
		}
	}
}
int main()
{
	geti(n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
		deg[x]++;
		deg[y]++;
	}
	cnt=n;
	for(int i=1;i<=n;i++)
	{
		if(con[i].size()==1)
		{
			q[qsz++]=i;
			vis[i]=1;
			cnt--;
		}
	}
	int qb=0;
	for(int i=0;i<qsz;i++)
	{
		int u=q[i];
		if(del[u])continue;
		del[u]=1;
		bool flag=0;
		for(int j=0;j<con[u].size();j++)
		{
			if(!del[con[u][j]])
			{
				flag=1;
				dele(con[u][j]);
			}
		}
		if(!flag)
		{
			puts("First");
			return 0;
		}
	}
	puts("Second");
	return 0;
}