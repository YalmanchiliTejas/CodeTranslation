#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 100005
using namespace std;
inline int in(){
    int x=0;bool f=0; char c;
    for (;(c=getchar())<'0'||c>'9';f=c=='-');
    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');
    return f?-x:x;
}
struct edge{
	int to,nxt;
}e[MN<<1];
int h[MN],fa[MN],n,x,y,cnt;
bool col[MN];
inline void ins(int x,int y){
	e[++cnt].to=y;e[cnt].nxt=h[x];h[x]=cnt;
}
inline bool dfs(int u){
	for (int i=h[u];i;i=e[i].nxt){
		int v=e[i].to;
		if (fa[u]!=v) {fa[v]=u;if (!dfs(v)) return 0;}
	}if (!col[u])
	if (!fa[u]||col[fa[u]]) return 0;
	else col[fa[u]]=col[u]=1;return 1;
} 
int main()
{
	n=in();
	for (int i=1;i<n;++i){
		x=in();y=in();
		ins(x,y);ins(y,x);
	}fa[1]=0;printf(dfs(1)?"Second":"First");return 0;
}