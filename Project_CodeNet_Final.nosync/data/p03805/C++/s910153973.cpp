#include <bits/stdc++.h>
using namespace std;
const int N=1234;
int head[N];
struct EdgeNode{
	int to,next;
}Edges[N];
int col;
void add(int u,int v){
	Edges[++col].to=v;
	Edges[col].next=head[u];
	head[u]=col;
}
int bj[N];
int ans;
void dfs(int k,int n,int c){
	if(c==n){
		ans++;
		return;
	}
	for(int i=head[k];i;i=Edges[i].next){
		if(!bj[Edges[i].to]){
			bj[Edges[i].to]=1;
			dfs(Edges[i].to,n,c+1);
			bj[Edges[i].to]=0;
		}
	}
}
int main(int argc, char const *argv[]){
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	memset(bj,0,sizeof(bj));
	ans=0;
	bj[1]=1;
	dfs(1,n,1);
	printf("%d\n",ans);
	return 0;
}