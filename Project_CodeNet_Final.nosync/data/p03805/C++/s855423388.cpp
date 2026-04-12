#include<cstdio>
#include<cstring>
#define MAXN 8+5
int ans=0,n,m;
bool graph[MAXN][MAXN];
//graph邻接矩阵存放图形
bool vis[MAXN];//vis[i]标志i这个点是否被访问过 

void visit(int x,int step){//step当前这条路径访问了多少个点 
	if(step>=n){
		ans++;
	}
	else 
		for(int i=1;i<=n;i++){
			if(graph[x][i]&&!vis[i]){//i与x相连，并且i没有被访问过 
				vis[i]=1,step++;
				visit(i,step);
				vis[i]=0,step--;
			}
		}
} 

int main(){
	int x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		graph[x][y]=1,graph[y][x]=1;
		//1表示两点之间有边 
	}
	
	vis[1]=1;
	visit(1,1);//最开始访问第一个点 
	printf("%d\n",ans);
	return 0;
}