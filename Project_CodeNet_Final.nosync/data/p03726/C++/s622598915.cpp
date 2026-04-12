#include<bits/stdc++.h>
#define FOR(i,a,b) for (register int i=(a);i<=(b);i++)
#define For(i,a,b) for (register int i=(a);i>=(b);i--)
#define mem(i,j) memset(i,j,sizeof(i))
#define GO(u) for (register int j=f[u];j!=-1;j=nxt[j])
#define fi first
#define se second
#define pii pair<int,int>
#define MP make_pair
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,a,b,lf[N],d[N],rt;
int tot=0,f[N],nxt[N<<1];
struct E
{
	int u,v;
}e[N<<1];
inline void add(int u,int v)
{
	tot++;
	nxt[tot]=f[u];
	f[u]=tot;
	e[tot]=(E){u,v};
	return;
}
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return f*x;
}
inline void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
inline void yes() {printf("First\n");exit(0);}
inline void no() {printf("Second\n");exit(0);}
inline int dfs(int u,int fa)
{
	int cnt=0;
	GO(u)
	{
		int v=e[j].v;
		if (v==fa) continue;
		cnt+=dfs(v,u);
	}
	if (cnt>1) yes();
	return cnt^1;
}
int main()
{
	mem(f,-1);
	n=read();
	if (n==2) no();
	if (n==1) yes();
	FOR(i,1,n-1) a=read(),b=read(),add(a,b),add(b,a),d[a]++,d[b]++;
	FOR(i,1,n) lf[i]=(d[i]==1);
	FOR(i,1,n) if (!lf[i]) {rt=i;break;}
	if (dfs(rt,0)) yes();
	no();
	return 0;
}