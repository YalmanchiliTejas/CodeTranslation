#include<bits/stdc++.h>
#define M 100005
#define NO {printf("Second\n"); return 0;}
#define YES {printf("First\n"); return 0;}
using namespace std;

struct edge{int u,next;}e[M*2]={0}; int head[M]={0},use=0;
void add(int x,int y){use++;e[use].u=y;e[use].next=head[x];head[x]=use;}
int du[M]={0},ye[M]={0};
int ok=1;
int dfs(int x,int fa){
	int cnt=0; 
	for(int i=head[x];i;i=e[i].next) if(e[i].u!=fa){
		ye[x]=0;
		cnt+=dfs(e[i].u,x);
	}
	if(cnt>1){
		printf("First\n");
		exit(0);
	}
	return cnt^1;
}

int main(){
	int n;
	scanf("%d",&n);
	if(n&1) YES
	if(n==2) NO
	for(int i=1;i<n;i++){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
		du[x]++; du[y]++;
	}
	for(int i=1;i<=n;i++) 
	if(du[i]>1){
		dfs(i,0);
		NO
	}
}
	