#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define SF scanf
#define PF printf
#define MAXN 100010
using namespace std;
struct node{
	int x;
	node *nxt;	
}edge[MAXN*2];
node *head[MAXN],*ncnt=edge;
int son[MAXN],n;
void add_edge(int x,int y){
	ncnt++;
	ncnt->x=y;
	ncnt->nxt=head[x];
	head[x]=ncnt;
}
bool ans;
void dfs(int x,int f){
	int flag=0;
	for(node *v=head[x];v!=NULL;v=v->nxt){
		int u=v->x;
		if(u==f)
			continue;
		dfs(u,x);
		if(son[u]==1)
			flag++;	
	}
	if(flag>1){
		ans=1;
		return ;	
	}
	if(flag==1)
		son[x]=0;
	else
		son[x]=1;
}
int main(){
	int u,v;
	SF("%d",&n);
	for(int i=1;i<n;i++){
		SF("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	if(son[1]==1)
		ans=1;
	if(ans==1)
		PF("First");
	else
		PF("Second");
}