#include <cstdio>

const int N=100005;

int fst[N],tot=0;
struct Edge{
	int to,nxt;
}e[N*2];

void addedge(int x,int y){
	e[++tot].to=y;e[tot].nxt=fst[x];fst[x]=tot;
}

int dfs(int x,int father){
	int v=0;
	for (int i=fst[x];i;i=e[i].nxt){
		int y=e[i].to;
		if (y!=father) v+=dfs(y,x);
	}
	return v>1?v:v^1;
}

int main(){
	int n;
	scanf("%d\n",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d\n",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	if (!dfs(1,0)) printf("Second\n");
		else printf("First\n");
}