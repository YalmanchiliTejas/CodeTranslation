//minamoto
#include<bits/stdc++.h>
#define R register
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
const int N=2e5+5;
struct eg{int v,nx;}e[N<<1];int head[N],tot;
inline void add(R int u,R int v){e[++tot]={v,head[u]},head[u]=tot;}
int dep[N],vis[N],fa[N],n;
void dfs(int u,int fa){
	go(u)if(v!=fa)dfs(v,u);
	if(!vis[u]&&vis[fa]){puts("First");exit(0);}
	if(!vis[u])vis[u]=vis[fa]=1;
}
int main(){
//	freopen("testdata.in","r",stdin);
	scanf("%d",&n);
	for(R int i=1,u,v;i<n;++i)scanf("%d%d",&u,&v),add(u,v),add(v,u);
	vis[0]=1;dfs(1,0);
	puts("Second");
	return 0;
}