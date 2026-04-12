#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200005;
int n,u,v,cnt,head[N],f[N][2],to[N*2],nxt[N*2];
void adde(int u,int v){
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
void dfs(int pre,int u){
	f[u][1]=1;
	int v;
	for(int i=head[u];i;i=nxt[i]){
		v=to[i];
		if(v!=pre){
			dfs(u,v);
			f[u][1]+=min(f[v][0],f[v][1]);
			f[u][0]+=f[v][1];
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		adde(u,v);
		adde(v,u);
	}
	dfs(0,1);
	puts(n%2==0&&min(f[1][0],f[1][1])==n/2?"Second":"First");
	return 0;
}