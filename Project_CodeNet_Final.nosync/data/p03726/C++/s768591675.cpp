#include<bits/stdc++.h>
const int N=1e5+7;
using namespace std;
int n,m,tot,head[N],size[N];
vector<int> G[N];
inline int read(){
	int f=1,x=0;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return f*x;
}
inline void addedge(int u,int v){
	G[u].push_back(v);G[v].push_back(u);
}
int cnt=0;
inline int dfs(int u,int f){
	size[u]=1;int cur=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];if(v==f)continue;
		cur+=dfs(v,u);size[u]+=size[v];
	}
	if(cur>=2){puts("First");exit(0);}
	if(cur)return 0;
	else return 1;
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		addedge(u,v);
	}
	int ans=dfs(1,0);int cnt=0;
	if(cnt)puts("First");
	if(ans)puts("First");else puts("Second");
}