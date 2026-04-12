#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)) f=ch=='-'?-1:f,ch=getchar();
	while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}

const int N=100000;
const int E=N<<1;

int f[N],g[N],last[N];
int tov[E],nxt[E];
int n,tot;

inline void insert(int x,int y){tov[++tot]=y,nxt[tot]=last[x],last[x]=tot;}

void dp(int x,int fa=0)
{
	f[x]=g[x]=0;
	for (int i=last[x],y;i;i=nxt[i])
		if ((y=tov[i])!=fa) dp(y,x),f[x]+=g[y];
	for (int i=last[x],y;i;i=nxt[i])
		if ((y=tov[i])!=fa) g[x]=max(g[x],f[x]-g[y]+f[y]+1);
	g[x]=max(f[x],g[x]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1,x,y;i<n;++i) scanf("%d%d",&x,&y),insert(x,y),insert(y,x);
	dp(1);
	if ((g[1]<<1)!=n) printf("First\n");
	else printf("Second\n");
	return 0;
}