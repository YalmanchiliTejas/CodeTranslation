#include<bits/stdc++.h>
using namespace std;
struct E{int v,next;}g[200005];
int n,h[100005],t,ans;
void ins(int u,int v){g[++t].v=v,g[t].next=h[u],h[u]=t;}
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
int dfs(int now,int last){
	int tot=0;
	for(int i=h[now];i;i=g[i].next) if(g[i].v!=last) tot+=dfs(g[i].v,now);
	if(tot>=2){puts("First");exit(0);}
	if(tot==0) return 1;
	return 0;
}
int main(){
	int u,v;
	n=read();
	for(int i=1;i<n;++i){
		u=read(),v=read();
		ins(u,v),ins(v,u);
	}
	ans=dfs(1,-1);
	if(ans) puts("First");
	else puts("Second");
}